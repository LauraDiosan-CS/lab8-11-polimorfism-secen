#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Actor.h"
class Movie
{
private:
	std::vector<Actor> actorList;
	std::string title;
public:
	Movie();
	Movie(std::string newTitle);
	~Movie();
	void setTitle(std::string titleToBeSet);
	void setActors(std::vector<Actor> newList);
	std::string toCSV();
	std::string toString();
	std::vector<Actor> getActors();
	std::string getTitle();
	void readFromLine(std::string line);
	void readFromCSVLine(std::string csvLine);
	bool operator==(Movie &m);
	bool operator!=(Movie &m);
};

