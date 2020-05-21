#include "Movie.h"

Movie::Movie()
{
	title = "";
	actorList = {};
}

Movie::Movie(std::string newTitle)
{
	actorList = {};
	this->title = newTitle;
}

Movie::~Movie()
{

}

void Movie::setTitle(std::string titleToBeSet)
{
	this->title = titleToBeSet;
}

void Movie::setActors(std::vector<Actor> newList)
{
	this->actorList = newList;
}

std::string Movie::toCSV()
{
	std::string aux = title;
	title += ',' + std::to_string(actorList.size());
	for (Actor a : actorList)
		aux += ',' + a.getName();
	return aux;
}

std::string Movie::toString()
{
	std::string aux = title;
	title += '#' + std::to_string(actorList.size());
	for (Actor a : actorList)
		aux += '#' + a.getName();
	return aux;
}

std::vector<Actor> Movie::getActors()
{
	return this->actorList;
}

std::string Movie::getTitle()
{
	return this->title;
}

void Movie::readFromLine(std::string line)
{
	char sep = '#';
	std::stringstream ss(line);
	std::string aux;
	std::getline(ss, title, sep);
	std::getline(ss, aux, sep);
	if (stoi(aux) > 0)
	{
		for (int i = 0; i < stoi(aux); i++)
		{
			std::string auxActorTitle;
			std::getline(ss, auxActorTitle, sep);
			this->actorList.push_back(*new Actor(auxActorTitle));
		}
	}
}

void Movie::readFromCSVLine(std::string csvLine)
{

	char sep = ',';
	std::stringstream ss(csvLine);
	std::string aux;
	std::getline(ss, title, sep);
	std::getline(ss, aux, sep);
	if (stoi(aux) > 0)
	{
		for (int i = 0; i < stoi(aux); i++)
		{
			std::string auxActorTitle;
			std::getline(ss, auxActorTitle, sep);
			this->actorList.push_back(*new Actor(auxActorTitle));
		}
	}
}

bool Movie::operator==(Movie& m)
{
	if (this->title == m.title)
		return true;
	return false;
}

bool Movie::operator!=(Movie& m)
{
	return !(*this==m);
}
