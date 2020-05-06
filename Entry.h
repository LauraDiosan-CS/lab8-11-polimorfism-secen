#pragma once
#include "Movie.h"
#include <string>
class Entry
{
private:
	int noOfSeatsLeft=0;
	Movie movie;
	std::string date;
public:
	Entry();
	Entry(Movie mv, int seats, std::string date);
	~Entry();
	int getNoOfSeatsLeft();
	void setNoOfSeatsLeft(int nom);
	Movie* getMovie();
	std::string getDate();
	bool operator==(Entry other);
};

