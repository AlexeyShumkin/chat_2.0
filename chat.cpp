#include "chat.h"

Chat::Chat(Connector *cn) : cn_{ cn } {}

void Chat::reg()
{
	std::string login;
	std::string password;
	std::cout << "Enter your login: ";
	std::cin >> login;
	std::cout << "Enter your password: ";
	std::cin >> password;
	Dataset ds;
	ds.resize(2);
	ds[0] = login;
	ds[1] = password;
	if (cn_->query(ds))
		std::cout << "Registration was successful!\n";
	else
		std::cout << "This login is already taken!\n";
	
}

void Chat::sign()
{
	std::string login;
	std::string password;
	std::cout << "Enter your login: ";
	std::cin >> login;
	std::cout << "Enter your password: ";
	std::cin >> password;
	Dataset ds;
	ds.resize(3);
	ds[0] = "SIGN";
	ds[1] = login;
	ds[2] = password;
	if (cn_->query(ds))
	{
		currentUser_ = login;
		std::cout << "Welcome to the chat room!\n";
	}
	else
		std::cout << "Invalid login or password!\n";
}

void Chat::post(const std::string& str1, const std::string& str2)
{
	std::string text;
	std::cout << "Message: ";
	std::cin >> text;
	Dataset ds;
	ds.resize(4);
	ds[0] = str1;
	ds[1] = str2;
	ds[2] = text;
	ds[3] = getTime();
	if (!cn_->query(ds))
		std::cout << "You can't send an empty message!\n";
}

std::string Chat::getTime()
{
	time_t now = time(nullptr);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "%X %d/%m/%Y", localtime(&now));
	return buffer;
}
