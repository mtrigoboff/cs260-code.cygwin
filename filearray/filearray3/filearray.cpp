#include <iostream>
#include "filearray.h"

using namespace std;

// flags for opening a file that already exists
static const ios::openmode		readWriteMode{ios::in | ios::out | ios::binary};

// flags for creating a file that does not yet exist
static const ios::openmode		createMode{ios::out | ios::binary};

FileArray::FileArray(char* fileName) :
	ch{0},
	chPrev{0},
	indexPrev{0}
{
	file.open(fileName, readWriteMode);		// try to open file in read/write mode
	if (! file.is_open()) {					// file is not there
		file.clear();						// clear error condition
		file.open(fileName, createMode);	// create file
		file.close();						// close so we can re-open
		file.open(fileName, readWriteMode);	// open file in read/write mode
		}
	status = file.is_open() && file.good();	// record stream status
}

FileArray::~FileArray(void)
{
	// write out previously set value to file if necessary
	if (ch != chPrev) {
		setValue(indexPrev, ch);
		cout << "destructor: item " << indexPrev << " set to " << ch << endl << endl;
		}

	file.close();
}

bool FileArray::getStatus(void)
{
	return status;
}

char FileArray::getValue(int index)
{
	char	ch;
	
	file.seekg(index * sizeof(ch));
	file.read((char *) &ch, sizeof(ch));
	if (file.eof()) {
		file.clear();		// clear eof and fail error bits
		ch = DEFAULT_VALUE;	// default value for Windows file system
		}
	return ch;
}

void FileArray::setValue(int index, char ch)
{
	file.seekp(index * sizeof(ch));
	file.write((char *) &ch, sizeof(ch));
}

// Operator[] works by returning a reference to the place in memory
// that's designated by the index. This works well for memory-based
// arrays, but isn't helpful for a file-based array. In particular,
// since operator[] is not told whether it was on the left side or
// right side of an assignment, we need a way to figure that out.
//
// This operator[] always gets the indexed char from the file, stores
// it in 'ch', and returns a reference to 'ch'. This works fine when
// operator[] is called on the righthand side of an assignment because
// the code compiled for the assignment copies the value out of 'ch'
// into the lefthand side of the assignment.
//
// When this operator[] is called on the lefthand side of an assignment,
// the code compiled for the assignment copies the value of the righthand
// side into 'ch' via the reference that operator[] returns. This,
// however, does not write that data into the file. For that to happen,
// operator[] needs to realize that it was on the lefthand side of
// the assignment.
//
// Since an assignment using operator[] on its lefthand side stores
// the data into 'ch', operator[] can tell that this has happened
// the NEXT time it's called by looking to see if the data in 'ch'
// has been changed 'from the outside' by the assignment. It does this
// by storing values from the previous time it was called. This allows
// it to discover if it was called on the lefthand side by comparing
// the data in the 'ch' data member to what it put into 'ch' the previous
// time. If that has changed, then the previous call was on the lefthand
// side and the file needs to be updated.
//
char& FileArray::operator[](int index)
{
	// write out previously set value to file if necessary
	if (ch != chPrev)
		setValue(indexPrev, ch);

	ch = getValue(index);

	// record current values for next time
	indexPrev = index;
	chPrev = ch;

	return ch;
}

streampos FileArray::fileSize(void)
{
	file.seekg(0, ios::end);		// seek to end of file
	return file.tellg();			// find out where that is
}

ostream& operator<<(ostream& out, FileArray& fa)
{
	streampos	size{fa.fileSize() / sizeof(char)};
	bool		first{true};

	out << "[";
	for (int i = 0; i < size; i++) {
		if (first)
			first = false;
		else
			out << ", ";
		out << fa[i];
		}
	out << "]";
	return out;
}

ostream& operator<<(ostream& out, FileArray* fa)
{
	char	ch;
	bool	first{true};

	out << "[";
	fa->file.seekg(0);
	for (;;) {
		fa->file.read(&ch, sizeof(ch));
		if (fa->file.eof()) {
			fa->file.clear();		// clear eof and fail error bits
			break;
			}
		if (first)
			first = false;
		else
			out << ", ";
		out << ch;
		}
	out << "]";
	return out;
}
