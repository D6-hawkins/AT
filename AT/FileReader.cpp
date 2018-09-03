#include "FileReader.h"

FileReader::FileReader(string _Filename)
{
}

FileReader::~FileReader()
{
}

void FileReader::GenerateVector(string _filename)
{
	string line;
	ifstream readFile("level.txt");
	if (readFile.is_open())
	{
		while (getline (readFile, line))
		{
			int i = 0; //Pull request test
		}
	}
}
