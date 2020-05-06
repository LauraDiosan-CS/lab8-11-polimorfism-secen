#include "Console.h"
#include "Entry.h"


//LOGIN MENU RELATED


//ASK_FOR_FILE RELATED

void Console::executeAskForFile()
{
	std::cout << "FILENAME ASKING IS UNIMPLEMENTED YET, BYPASSING\n";
	this->currentState = States::LOGIN_PROMPT;
}


//LOGIN PROMPT STATE RELATED

bool Console::validCreds(std::string user, std::string pass)
{
	return ((user == "ana") && (pass == "parola"));
}

void Console::executeLoginPrompt()
{
	while (this->currentState == States::LOGIN_PROMPT)
	{
		std::string username, pass;
		std::cout << "Please enter a username and password\n";
		std::cout << "User: ";
		std::cin >> username;
		std::cout << "Password: ";
		std::cin >> pass;
		if (validCreds(username, pass))
			this->currentState = States::MAIN_MENU;
	}
}

void Console::executeMainMenu()
{
	while (this->currentState == States::MAIN_MENU)
	{

		std::cout << "1.Search by date\n";
		std::cout << "2.Buy\n";
		std::cout << "3.Add..\n";
		std::cout << "4.Remove..\n";
		std::cout << "5.Print..\n";
		std::cout << "0.Logout\n";
		std::cout << "Selection: ";

		int choice;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			this->currentState = States::SEACH_BY_DATE;
			break;
		case 2:
			this->currentState = States::BUY;
			break;
		case 3:
			this->currentState = States::ADD_MENU;
			break;
		case 4:
			this->currentState = States::REMOVE_MENU;
			break;
		case 5:
			this->currentState = States::PRINT_MENU;
			break;
		case 0:
			this->currentState = States::EXIT;
			break;
		default:
			std::cout << "Invalid selection!\n";
			break;
		}
	}
}

void Console::executeAddMenu()
{
	while (this->currentState == States::ADD_MENU)
	{
		std::cout << "1.Add Actor\n";
		std::cout << "0.Exit\n";
		std::cout << "Selection: ";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			this->currentState = States::ADD_ACTOR;
			break;
		case 0:
			this->currentState = States::MAIN_MENU;
			break;
		default:
			std::cout << "Invalid selection!\n";
			break;
		}
	}
}

void Console::executeAddActor()
{
	while (currentState == States::ADD_ACTOR)
	{
		std::cout << "Please enter the name of the actor: ";
		std::string newName;
		std::cin.ignore();
		std::getline(std::cin, newName);
		this->serv.addActor(newName);
		currentState = States::MAIN_MENU;
	}
}

void Console::buyTicketMenu(Entry entr)
{
	if (this->currentState == States::BUY)
	{
		std::string name;
		int tickets;
		std::cout <<"Tickets Left: " <<entr.getNoOfSeatsLeft()<<"\n";
		std::cout << "No of Tickets To Be Purchased: ";
		std::cin >> tickets;
		std::cout << "Name: ";
		std::cin >> name;
		if (tickets > entr.getNoOfSeatsLeft())
			std::cout << "Im m sorry there aren't that many seats available.\n";
		else
		{
			serv.Buy(entr, tickets);
		}
		this->currentState = States::MAIN_MENU;
	}
}

void Console::selectEntryToBuyMenu(std::vector<Entry> results)
{
	while (this->currentState == States::SEACH_BY_DATE)
	{
		for (int i = 0; i < results.size(); i++)
		{
			std::cout << i + 1 << ".";
			Entry ent = results[i];
			std::cout << ent.getMovie()->getTitle();
		}
		std::cout << "0.Exit";
		int choice;
		std::cin >> choice;
		if (choice < 0)
			continue;
		if (choice == 0)
			this->currentState = States::MAIN_MENU;
		else if (choice <= results.size())
		{
			this->currentState = States::BUY;
			buyTicketMenu(results[choice-1]);
		}
	}
}

void Console::executeSearchByDate()
{
	if (this->currentState == States::SEACH_BY_DATE)
	{
		std::string date;
		std::cout << "Please enter a date:";
		std::cin >> date;
		std::vector <Entry> results = this->serv.queryByDate(date);
		if (results.size())
			selectEntryToBuyMenu(results);
		else
		{
			std::cout << "Nothing found for that date\n";
			this->currentState = States::MAIN_MENU;
		}
	}
}

void Console::executePrintActors()
{
	if (currentState == States::PRINT_ACTORS)
	{
		std::vector<Actor> aux = this->serv.getActors();
		for (Actor act : aux)
		{
			std::cout << act.getName() << "\n";
		}
		currentState = States::PRINT_MENU;
	}
}

void Console::executePrintMenu()
{
	while (currentState == States::PRINT_MENU)
	{
		std::cout << "1.Print Actors\n";
		std::cout << "0.Exit\n";
		std::cout << "Selection: ";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			this->currentState = States::PRINT_ACTORS;
			break;
		case 0:
			this->currentState = States::MAIN_MENU;
			break;
		}
	}
}

void Console::run()
{
	while (currentState != States::EXIT)
	{
		switch (currentState)
		{
		case States::ASK_FOR_FILE:
			executeAskForFile();
			break;
		case States::LOGIN_PROMPT:
			executeLoginPrompt();
			break;
		case States::MAIN_MENU:
			executeMainMenu();
			break;
		case States::ADD_ACTOR:
			executeAddActor();
			break;
		case States::ADD_MENU:
			executeAddMenu();
			break;
		case States::PRINT_MENU:
			executePrintMenu();
			break;
		case States::PRINT_ACTORS:
			executePrintActors();
			break;
		case States::SEACH_BY_DATE:
			executeSearchByDate();
			break;
		default:
			this->currentState = States::MAIN_MENU;
			break;
		}
	}
}

Console::Console()
{
}

Console::~Console()
{
}
