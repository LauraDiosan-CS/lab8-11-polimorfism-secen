#include "Entry.h"

Entry::Entry()
{
	this->noOfSeatsLeft = 0;
	this->movie = Movie("debug title");
	this->date = "00.00.0000";
}

Entry::Entry(Movie mv, int seats, std::string dt)
{
	this->movie = mv;
	this->noOfSeatsLeft = seats;
	this->date = dt;
}

Entry::~Entry()
{
}

int Entry::getNoOfSeatsLeft()
{
	return this->noOfSeatsLeft;
}

void Entry::setNoOfSeatsLeft(int nom)
{
	this->noOfSeatsLeft = nom;
}

Movie* Entry::getMovie()
{
	return &(this->movie);
}

std::string Entry::getDate()
{
	return this->date;
}

bool Entry::operator==(Entry other)
{
	if(this->movie.getTitle() == other.movie.getTitle())
		return true;
	return false;
}
