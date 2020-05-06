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
private:
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
		std::priority_queue<T> q = this->getAll();
		int size = this->getSize();
		fout << size<<'\n';
		while(!q.empty())
		{
			T elem = q.top();
			fout << elem << '\n';
			q.pop();
		}
	};
	void loadFromFile()
	{
		std::ifstream fin(m_filename);
		int size;
		fin >> size;
		this->clear();
		for (int i = 0; i < size; i++)
		{
			T elem;
			fin >> elem;
			this->addItem(elem);
		}
	};
};

