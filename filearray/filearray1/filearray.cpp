#include "filearray.h"

using namespace std;

// flags for opening a file that already exists
static const ios::openmode		readWriteMode = ios::in | ios::out | ios::binary;

// flags for creating a file that does not yet exist
static const ios::openmode		createMode = ios::out | ios::binary;

FileArray::FileArray(char* fileName)
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
	file.close();
}

bool FileArray::getStatus(void)
{
	return status;
}

char FileArray::operator[](int index)
{
	file.seekg(index * sizeof(ch));
	file.read((char *) &ch, sizeof(ch));
	if (file.eof()) {
		file.clear();			// clear eof and fail error bits
		ch = DEFAULT_VALUE;
		}
	return ch;
}

void FileArray::setValue(int index, char ch)
{
	file.seekp(index * sizeof(ch));
	file.write((char *) &ch, sizeof(ch));
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

ostream& operator<<(ostream& out, FileArray *fa)
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
