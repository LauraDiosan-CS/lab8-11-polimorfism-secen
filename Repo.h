#pragma once
#include <vector>
template <class T>
class Repo
{
protected:
	std::vector<T> entities;
public:
		Repo() { entities = std::vector<T>(); }
	   ~Repo() {}
	   void push_back(T s){this->entities.push_back(s);}
	   std::vector<T> getAll() {return this->entities;}
	   unsigned int getSize() { return entities.size(); }
	   void removeElementAtPos(int i) { entities.erase(i); }
	   void clear() { entities.clear(); }
};

