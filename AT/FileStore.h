#ifndef FILE_STORE_H_
#define FILE_STORE_H_
#include <string>
#include <vector>
#include <ostream>
#include <fstream>
using namespace std;
class Platform;
class FileStore
{
public:
	FileStore(vector<Platform*> PlatVec);
	~FileStore();

private:
	void StoreLevel(vector<Platform*>);

};




#endif