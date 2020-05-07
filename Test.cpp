#include "Test.h"
#include "Service.h"
#include "FileRepo.h"
#include "FileRepoCSV.h"
#include <vector>
#include <assert.h>
#include <string>
void tests()
{
	{
		Actor act1 = Actor("Maria");
		Actor act2 = Actor("Ion");
		assert(act1.getName() == "Maria");
		assert(act1 == Actor("Maria"));
		assert(act1 != act2);
		act1 = act2;
	}
	{
		Service s;
		s.addActor("Ion");
		std::vector<Actor> vec = s.getActors();
		assert(vec.size() == 1);
		Actor act = vec[0];
		assert(act.getName() == "Ion");
	}
	{
		Service s;
		s.addEntry(Entry(Movie("Peles Curcanu"), 20, "11.11.1111"));
		s.addEntry(Entry(Movie("Ion"), 20, "12.34.5678"));
		s.addEntry(Entry(Movie("Aliens"), 20, "11.11.1111"));
		std::vector<Entry> results = s.queryByDate("11.11.1111");
		assert(results.size() == 2);
		Entry aux = results[0];
		assert(aux.getDate() == "11.11.1111");
		assert(aux.getMovie()->getTitle() == "Peles Curcanu");
		s.Buy(aux, 5);
		assert(s.getEntires()[0].getNoOfSeatsLeft() == 15);
	}
	{
		Service s;
		std::vector<Actor> actors;
		actors.push_back(Actor("Mihai Barbu"));
		actors.push_back(Actor("Victor Crainic"));
		Entry testEntry = Entry(Movie("Miorita"), 10, "10.10.1000");
		s.addEntry(testEntry);
		s.addActorsToEntry(actors, testEntry);
		assert((s.getEntires()[0].getMovie()->getActors())[0] == actors[0]);
		assert((s.getEntires()[0].getMovie()->getActors())[1] == actors[1]);
	}
	{
		FileRepo<Actor> rep("testing actor.txt");
		Actor a = Actor("Ionel Crudu");
		Actor b = Actor("Ana Maria");
		rep.push_back(a);
		rep.push_back(b);
		rep.saveToFile();
		rep.clear();
		rep.loadFromFile();
		assert(rep.getSize() == 2);
		assert(rep.getAll()[0] == a);
		assert(rep.getAll()[1] == b);
	}
	{
		FileRepoCSV<Actor> rep("testing actor.csv");
		Actor a = Actor("Ionel Crudu");
		Actor b = Actor("Ana Maria");
		rep.push_back(a);
		rep.push_back(b);
		rep.saveToFile();
		rep.clear();
		rep.loadFromFile();
		assert(rep.getSize() == 2);
		assert(rep.getAll()[0] == a);
		assert(rep.getAll()[1] == b);
	}
}
