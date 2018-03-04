#ifndef  FILE_READER_H_
#define FILE_READER_H_
#include <string>
#include <ostream>
#include <fstream>
using namespace std;
class FileReader
{

public:
	FileReader(string _Filename);
	~FileReader();
	void GenerateVector(string);
private:



};



#endif // ! FILE_READER_H_
