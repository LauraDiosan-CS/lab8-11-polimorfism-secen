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
	friend std::ostream& operator<<(std::ostream& os, const Actor& dt);
	friend std::istream& operator >> (std::istream& in, Actor& dt);
	bool operator== (Actor other);
	bool operator!= (Actor other);
};

