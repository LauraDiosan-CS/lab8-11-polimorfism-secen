#pragma once
#include <string>
#include <iostream>
#include <vector>
class Actor
{
private:
	std::string name;
public:
	Actor();
	Actor(std::string actorName);
	~Actor();
	std::string getName();
	void setName(std::string nameToBeSet);

	std::string toCSV();
	std::string toString();
	void readFromLine(std::string line);
	void readFromCSVLine(std::string csvLine);

	friend std::ostream& operator<<(std::ostream& os, const Actor& dt);
	friend std::istream& operator >> (std::istream& in, Actor& dt);
	bool operator== (Actor other);
	bool operator!= (Actor other);
};

