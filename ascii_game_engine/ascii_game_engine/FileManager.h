// static class to handles saving and loading into .txt file
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <fstream> // file stream
#include <stdio.h> // remove(fileName);
#include <vector>

class FileManager
{
public:
	FileManager() {};
	~FileManager() {};

	static std::vector<std::string> LoadFile(const char* txtFile);
	static void SaveFile(const std::vector<std::string> saveData, const char* txtFile);
	static void SaveFile(const std::string saveData, const char* txtFile);
	static bool DeleteFile(const char* txtFile);
	static bool FileExist(const char* txtFile);
};

#endif