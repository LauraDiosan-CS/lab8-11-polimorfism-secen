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
	EXIT
};
class Console
{
private:
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
	//BUYING RELATED
	void buyTicketMenu(Entry entr);
	//SEARCH BY DATE RELATED
	void selectEntryToBuyMenu(std::vector<Entry> results);
	void executeSearchByDate();
	//PRINT RELATED
	void executePrintActors();
	void executePrintMenu();
public:
	void run();
	Console();
	~Console();
};

