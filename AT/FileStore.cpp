#include "FileStore.h"
//#include "PlatformGenerator.h"
#include "Platform.h"
FileStore::FileStore(vector<Platform*> PlatVec)
{
	StoreLevel(PlatVec);
}

FileStore::~FileStore()
{

}

void FileStore::StoreLevel(vector<Platform*> PlatVec)
{
	ofstream outputFile;
	outputFile.open("level.txt");
	if (outputFile.is_open())
	{
		for (int i = 0; i != PlatVec.size(); i++)
		{
			int x = PlatVec[i]->GetPos().x;
			int y = PlatVec[i]->GetPos().y;
			outputFile << "_ ";
			outputFile << "X: ";
			outputFile << x;
			outputFile << " ";
			outputFile << "Y:";
			outputFile << y;
			outputFile << "\n";
		}

		outputFile.close();
	}
}
