#pragma once
#include <iostream>
#include "connector.h"

class Chat
{
public:
	Chat(Connector* cn);
	virtual void reg() final;
	virtual void sign() final;
	virtual void post(const std::string& str1, const std::string& str2);
	std::string getTime();
protected:
	Connector* cn_{ nullptr };
	std::string currentUser_;
	std::string recipient_;
};
