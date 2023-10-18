#pragma once
#include"connector.h"

class Chat
{
public:
	Chat(Connector* cn) : cn_{ cn } {}
	void reg();
	void sign();
	void post();
	void read();
	std::string getTime();
protected:
	Connector* cn_{ nullptr };
	std::string currentUser_;
};
