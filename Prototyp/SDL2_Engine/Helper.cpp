#pragma region system include
#include <SDL.h>
#include <fstream>
#pragma endregion

#pragma region project include
#include "Helper.h"
#pragma endregion

string GetParentDirectory(string _path, int _depth)
{
	// if depth higher 1
	if (_depth > 1)
	{
		// get parent directory until depth 1 or lower
		_path = GetParentDirectory(_path, _depth - 1);
	}

	// position of last sub
	size_t pos = _path.find_last_of("\\/");

	// return parent
	return (string::npos == pos) ? "" : _path.substr(0, pos);
}

string GetAssetPath(const char* _pPath, int _depth)
{
	// get parent directory
	string path = GetParentDirectory(SDL_GetBasePath(), _depth);

	// append sub path
	path.append("/Assets/").append(_pPath);

	// return complete path
	return path;
}

void SaveStringToFile(string _text, const char* _pFileName)
{
	// open file
	ofstream file;
	file.open(GetAssetPath(_pFileName, 4).c_str());

	// if file is not opened
	if (!file.is_open())
		return;

	// write string into file
	file << _text;

	// close file
	file.close();
}

string LoadStringFromFile(const char* _pFileName)
{
	string text = "";

	string line;

	ifstream file;

	file.open(GetAssetPath(_pFileName, 4).c_str());

	// if file is not opened
	if (!file.is_open())
		return "";

	// as long as there is a line
	while (getline(file, line))
	{
		text.append(line);
		text.append("\n");
	}

	// close file
	file.close();

	// return text from file
	return text;
}