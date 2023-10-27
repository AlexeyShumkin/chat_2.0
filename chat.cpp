#include "chat.h"

Chat::Chat(DataBase* db) : db_{ db } {}

void Chat::run()
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
		{
			showUsers();
			showMenu();
		}
	} while(true);
	std::cout << "Goodbye!\n";
}

void Chat::showMenu()
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
			Dataset ds{ "FIND"s, recipient };
			if(!db_->handle(ds))
			{
				std::cout << "There is no user with this login in the chat room!\n";
				continue;
			}
			Dialog pvt(db_, currentUser_, recipient);
			pvt.showMenu();
		}
		else if(action == '3')
		{
			Dataset ds{ "PUB"s };
			ds = db_->reply(ds);
			read(ds[0]);
		}
		else if(action == 'q')
			break;
		else
			std::cout << "Your command is unclear. Please, select an action from the list.\n";
	} while(true);
}

void Chat::showUsers()
{
	Dataset ds{ "USERS"s };
	ds = db_->reply(ds);
	fs::path path;
	int number = 1;
	std::cout << "Now in chat room:\n";
    for (const auto& entry : fs::directory_iterator(ds[0]))
    {
		path = entry;
		auto user = path.generic_string();
		user = user.substr(14);
		if(user == currentUser_)
			std::cout << number++ << ") " << user << " | online\n";
		else
			std::cout << number++ << ") " << user << " | offline\n";
	}
}

void Chat::reg()
{
	std::string login;
	std::string password;
	std::cout << "Enter your login: ";
	std::cin >> login;
	std::cout << "Enter your password: ";
	std::cin >> password;
	Dataset ds{ "REG"s, login, password };
	if (login == "all"s || !db_->handle(ds))
		std::cout << "This login is already taken!\n";
	else
		std::cout << "Registration was successful!\n";
}

void Chat::sign()
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

void Chat::post()
{
	std::string text;
	std::cout << "Message: ";
	std::getline(std::cin.ignore(), text);
	if(text == ""s)
		std::cout << "You can't send an empty message!\n";
	else
	{
		Dataset ds{ currentUser_, recipient_, text, getTime() };
		if (!db_->handle(ds))
			std::cout << "Failed attempt to send!\n";
	}
}

void Chat::read(const fs::path& path)
{
	std::ifstream in(path);
	for (std::string line; std::getline(in, line);) 
    	std::cout << line << std::endl;
}

std::string Chat::getTime()
{
	time_t now = time(nullptr);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "%X %d/%m/%Y", localtime(&now));
	return buffer;
}

Dialog::Dialog(DataBase* db, const std::string& currentUser, const std::string& recipient) : Chat(db)
{
	currentUser_ = currentUser;
	recipient_ = recipient;
}

void Dialog::showMenu()
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
			Dataset ds{ "PVT"s, currentUser_, recipient_ };
			ds = db_->reply(ds);
			if(!ds.size())
				std::cout << "There are no messages in this dialog yet!\n";
			else
				read(ds[0]);
		}
		else if(action == 'q')
			break;
		else
			std::cout << "Your command is unclear. Please, select an action from the list.\n";
	} while(true);
}
