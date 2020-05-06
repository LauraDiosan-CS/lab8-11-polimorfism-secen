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

void Movie::setActors(std::vector<Actor*> newList)
{
	this->actorList = newList;
}

std::vector<Actor*> Movie::getActors()
{
	return this->actorList;
}

std::string Movie::getTitle()
{
	return this->title;
}
