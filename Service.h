#pragma once
#include <string>
#include <vector>
#include "Actor.h"
#include "Entry.h"
#include "FileRepo.h"
class Service
{
private:
	FileRepo<Actor> actors;
	std::vector<Entry> entries;
	std::string filename;
	/*
	long long compute_hash(string const& s) {
		const int p = 31;
		const int m = 1e9 + 9;
		long long hash_value = 0;
		long long p_pow = 1;
		for (char c : s) {
			hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
			p_pow = (p_pow * p) % m;
		}
		return hash_value;
	}*/
public:
	Service();
	Service(FileRepo<Actor> actorRepo);
	void addActor(std::string name);
	std::vector<Actor> getActors();
	std::vector<Entry> queryByDate(std::string date);
	std::vector<Entry> getEntires();
	void addEntry(Entry ent);
	void addActorsToEntry(std::vector<Actor> actorList, Entry& entryToModify);
	void setActorRepo(FileRepo<Actor> actorRepo);
	void loadFromFile();
	void Buy(Entry entr, int tickets);
};

