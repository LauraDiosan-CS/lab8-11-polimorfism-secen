#pragma once
#include "Repo.h"
#include <cstring>
#include <fstream>
#include <queue>
#include <string>
#include <sstream>
template <class T>
class FileRepo :
	public Repo<T>
{
protected:
	std::string m_filename;
public:
	FileRepo() 
	{
		m_filename = "DebugFilename.txt";
	};
	FileRepo(const std::string newFilename)
	{
		m_filename = newFilename;
	}
	~FileRepo() {}
	void saveToFile()
	{
		std::ofstream fout(m_filename);
		std::vector<T> q = this->getAll();
		int size = this->getSize();
		fout << size<<'\n';
		for(int i =0;i<size;i++)
		{
			T elem = q[i];
			fout << elem << '\n';
		}
	};
	void loadFromFile()
	{
		std::ifstream fin(m_filename);
		int size=0;
		fin >> size;
		this->clear();
		fin.ignore();
		for (int i = 0; i < size; i++)
		{
			T elem;
			fin >> elem;
			this->push_back(elem);
		}
	};
};

