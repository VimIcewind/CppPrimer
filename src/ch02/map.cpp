#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	map<string, string> telephone_directory;

	telephone_directory.insert(pair<string, string>("VimIcewind", "15216410720"));
	telephone_directory.insert(map<string, string>::value_type("HWD", "18661830886"));

	map<string,string>::iterator iter;

	for (iter = telephone_directory.begin(); iter != telephone_directory.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;

	return 0;
}
