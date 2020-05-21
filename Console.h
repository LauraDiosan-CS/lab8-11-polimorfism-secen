#pragma once
#include <iostream>
#include "Actor.h"
#include "Service.h"
enum class States
{
	ASK_FOR_FILE,
	LOGIN_PROMPT,
	MAIN_MENU,
	SEACH_BY_DATE,
	BUY,
	ADD_MENU,
	ADD_ENTRY,
	ADD_MOVIE,
	ADD_ACTOR,
	REMOVE_MENU,
	REMOVE_ENTRY,
	REMOVE_MOVIE,
	REMOVE_ACTOR,
	PRINT_ACTORS,
	PRINT_MENU,
	PRINT_ENTRIES,
	PRINT_MOVIES,
	EXIT
};
class Console
{
private:
	bool isCSV;
	States currentState=States::ASK_FOR_FILE;
	Service serv;
	//ASK_FOR_FILE RELATED
	void executeAskForFile();
	//LOGIN PROMPT STATE RELATED
	bool validCreds(std::string user, std::string pass);
	void executeLoginPrompt();
	//LOGIN MENU RELATED
	void executeMainMenu();
	//ADD MENU RELATED
	void executeAddMenu();
	void executeAddActor();
	void executeAddMovie();
	void executeAddEntry();
	//BUYING RELATED
	void buyTicketMenu(Entry entr);
	//SEARCH BY DATE RELATED
	void selectEntryToBuyMenu(std::vector<Entry> results);
	void executeSearchByDate();
	//PRINT RELATED
	void executePrintActors();
	void executePrintMenu();
	void executePrintMovies();
	void executePrintEntries();
public:
	void run();
	Console();
	~Console();
};

