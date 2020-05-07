#include "Service.h"

void Service::addActor(std::string name)
{
	this->actors.push_back(Actor(name));
}

std::vector<Actor> Service::getActors()
{
	return this->actors.getAll();
}

std::vector<Entry> Service::queryByDate(std::string date)
{
	std::vector<Entry> aux;
	for (Entry ent : this->entries)
	{
		if (ent.getDate() == date)
			aux.push_back(ent);
	}
	return aux;
}

std::vector<Entry> Service::getEntires()
{
	return this->entries;
}

void Service::addEntry(Entry ent)
{
	this->entries.push_back(ent);
}

void Service::addActorsToEntry(std::vector<Actor> actorlist, Entry &entryToModify)
{
	for (int i =0;i<this->entries.size();i++)
	{
		if (this->entries[i] == entryToModify)
			this->entries[i].getMovie()->setActors(actorlist);
	}
}

void Service::Buy(Entry entr, int tickets)
{
	for(int i =0;i<entries.size();i++)
		if (entries[i] == entr)
			this->entries[i].setNoOfSeatsLeft(entr.getNoOfSeatsLeft() - tickets);
}
