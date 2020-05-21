#include "Actor.h"

std::ostream& operator<<(std::ostream& os, const Actor& dt)
{
	os << dt.name;
	return os;
}

std::istream& operator>>(std::istream& in, Actor& dt)
{
	std::string futureName;
	getline(in, futureName);
	dt.name = futureName;
	return in;
}

Actor::Actor()
{
	this->name = "";
}

Actor::Actor(std::string actorName)
{
	this->name = actorName;
}

Actor::~Actor()
{
}

std::string Actor::getName()
{
	return this->name;
}

void Actor::setName(std::string nameToBeSet)
{
	this->name = nameToBeSet;
}

std::string Actor::toCSV()
{
	return this->getName();
}

std::string Actor::toString()
{
	return this->getName();
}

void Actor::readFromLine(std::string line)
{
	this->setName(line);
}

void Actor::readFromCSVLine(std::string csvLine)
{
	this->setName(csvLine);
}

bool Actor::operator==(Actor other)
{
	return this->name == other.name;
}

bool Actor::operator!=(Actor other)
{
	return !(*this == other);
}
