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

	void saveToFile()
	{
		std::ofstream fout(m_filename);
		std::vector<T> q = this->getAll();
		int size = this->getSize();
		fout << size << '\n';
		for (int i = 0; i < size; i++)
		{
			T elem = q[i];
			fout << elem.toCSV() << '\n';
		}
	};
	void loadFromFile()
	{
		std::ifstream fin(m_filename);
		int size = 0;
		fin >> size;
		this->clear();
		fin.ignore();
		for (int i = 0; i < size; i++)
		{
			T elem;
			std::string line;
			std::getline(fin,line);
			elem.readFromCSVLine(line);
			this->push_back(elem);
		}
	};
};

