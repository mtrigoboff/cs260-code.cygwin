#ifndef _FILEARRAY_H_
#define _FILEARRAY_H_

#include <ostream>
#include <fstream>

// manages an array of ints that is stored in a file

class FileArray
{
public:
	FileArray(char* fileName);			// create array based on file with this name
	~FileArray(void);
	bool getStatus(void);				// true means "good", false means "bad"
	void setValue(int index, char ch);	// set item at position specified by index

	char operator[](int index);			// overload for get

	friend std::ostream& operator<<(std::ostream& out, FileArray& fa);
	friend std::ostream& operator<<(std::ostream& out, FileArray *fa);

private:
	static const int	DEFAULT_VALUE = 0;	// when a file grows because we have written past the end of it,
											// Windows fills the space in between with this value

	std::fstream	file;				// stream to/from array file
	bool			status;				// file status

	std::streampos	fileSize(void);

	char			ch;						// operator[] returns reference to here
};

#endif
