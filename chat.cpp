#include "chat.h"

PubChat::PubChat(DataBase* db) : db_{ db } {}

void PubChat::run()
{
	std::cout << "Hello! You are welcome to register, or you can enter the chat room if you are already registered.\n";
	char action = '0';
	do
	{
		std::cout << "To register press 1, to enter press 2, to log out of the account press 3, press q to exit: ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> action;
		if(action == '1')
		{
			if(currentUser_.size())
				std::cout << "You are already logged in!\n";
			else
				reg();
		}
		else if(action == '2')
		{
			if (currentUser_.size())
					std::cout << "You are already logged in!\n";
			else
				sign();
		}
		else if(action == '3')
		{
			if (!currentUser_.size())
				std::cout << "You are not authorized yet!\n";
			else
			{
				std::cout << "User " << currentUser_ << " left the chat room.\n";
				currentUser_.clear();
			}
		}
		else if(action == 'q')
		{	
			if(currentUser_.size())
				currentUser_.clear();
			break;
		}
		else
			std::cout << "Your command is unclear. Please, select an action from the list:\n";
		if(currentUser_.size())
			showMenu();
	} while(true);
	std::cout << "Goodbye!\n";
}

void PubChat::showMenu()
{
	char action = '0';
	do
	{
		std::cout << "To write a public message press 1, to go to the dialog press 2, to view chat press 3, press q to exit from chat menu: ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> action;
		if(action == '1')
			post();
		else if(action == '2')
		{
			std::string recipient;
			std::cout << "Enter the recipient login: ";
			std::cin >> recipient;
			if (recipient == currentUser_)
			{
				std::cout << "The developer still believes that users should not send messages to themselves :)\n";
				continue;
			}
			Dataset ds{ "FIND", recipient };
			if(!db_->handle(ds))
			{
				std::cout << "User with this login is not in the chat room!\n";
				continue;
			}
			PvtChat pvt(db_, currentUser_, recipient);
			pvt.showMenu();
		}
		else if(action == '3')
			std::cout << "There should be conversation here\n";
		else if(action == 'q')
			break;
		else
			std::cout << "Your command is unclear. Please, select an action from the list.\n";
	} while (true);
}

void PubChat::reg()
{
	std::string login;
	std::string password;
	std::cout << "Enter your login: ";
	std::cin >> login;
	std::cout << "Enter your password: ";
	std::cin >> password;
	Dataset ds{ "REG"s, login, password };
	if (db_->handle(ds))
		std::cout << "Registration was successful!\n";
	else
		std::cout << "This login is already taken!\n";
}

void PubChat::sign()
{
	std::string login;
	std::string password;
	std::cout << "Enter your login: ";
	std::cin >> login;
	std::cout << "Enter your password: ";
	std::cin >> password;
	Dataset ds{ "SIGN"s, login, password };
	if (db_->handle(ds))
	{
		currentUser_ = login;
		std::cout << "Welcome to the chat room!\n";
	}
	else
		std::cout << "Invalid login or password!\n";
}

void PubChat::post()
{
	std::string text;
	std::cout << "Message: ";
	std::cin >> text;
	Dataset ds{ currentUser_, recipient_, text, getTime() };
	if (!db_->handle(ds))
		std::cout << "You can't send an empty message!\n";
}

std::string PubChat::getTime()
{
	time_t now = time(nullptr);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "%X %d/%m/%Y", localtime(&now));
	return buffer;
}

PvtChat::PvtChat(DataBase* db, const std::string& currentUser, const std::string& recipient) : PubChat(db)
{
	currentUser_ = currentUser;
	recipient_ = recipient;
}

void PvtChat::showMenu()
{
	char action = '0';
	do
	{
		std::cout << "To send a message press 1, to view the conversation press 2, to leave the dialog press q: ";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> action;
		if(action == '1')
			post();
		else if(action == '2')
		{
			Dataset ds{ "READ"s, currentUser_, recipient_ };
			if(!db_->handle(ds))
				std::cout << "There are no messages in this dialog yet!\n";
		}
		else if(action == 'q')
			break;
		else
			std::cout << "Your command is unclear. Please, select an action from the list.\n";
	} while (true);
}
