#include "FileManager.h"

std::vector<std::string> FileManager::LoadFile(const char* txtFile)
{
	std::string data; // used to store data from file
	std::ifstream inFile(txtFile); // Input file
	std::vector<std::string> res;

	// Check for any error
	if (inFile.fail())
	{
		std::cerr << "Unable to open file: " << txtFile << std::endl;
		exit(1);
	}

	// Loop through till the end of the file
	while (!inFile.eof())
	{
		inFile >> data;
		res.push_back(data);
	}

	return res;
}

void FileManager::SaveFile(const std::vector<std::string> saveData, const char* txtFile)
{
	std::ofstream outFile(txtFile);
	for (std::string data : saveData)
		outFile << data << std::endl;
}

void FileManager::SaveFile(const std::string saveData, const char* txtFile)
{
	std::ofstream outFile(txtFile);
	outFile << saveData;
}

bool FileManager::DeleteFile(const char* txtFile)
{
	// delete the file
	return remove(txtFile);
}

bool FileManager::FileExist(const char* txtFile)
{
	std::ifstream file(txtFile);
	// No error opening the file, save file exist
	if (!file.fail())
		return true;
	return false;
}