#pragma once
#include "FileRepo.h"
#include <string>
template <class T>
class FileRepoCSV :
	public FileRepo<T>
{
private:
	std::string m_filename;
public:
	FileRepoCSV()
	{
		m_filename = "DebugFilename.csv";
	};
	FileRepoCSV(const std::string newFilename)
	{
		m_filename = newFilename;
	}
};

