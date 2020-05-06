#pragma once
#include <iostream>
#include <vector>
#include "Actor.h"
class Movie
{
private:
	std::vector<Actor*> actorList;
	std::string title;
public:
	Movie();
	Movie(std::string newTitle);
	~Movie();
	void setTitle(std::string titleToBeSet);
	void setActors(std::vector<Actor*> newList);
	std::vector<Actor*> getActors();
	std::string getTitle();
};

