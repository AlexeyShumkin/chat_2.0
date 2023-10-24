#pragma once
#include "database.h"

class Chat
{
public:
	Chat() = default;
	Chat(DataBase* db);
	virtual ~Chat() = default;
	virtual void run() final;
	virtual void reg() final;
	virtual void sign() final;
	virtual void showMenu();
	void showUsers();
	void post();
	std::string getTime();
protected:
	DataBase* db_{ nullptr };
	std::string currentUser_;
	std::string recipient_ = "all";
};

class pvtChat : public Chat
{
public:
	pvtChat(DataBase* db, const std::string& currentUser, const std::string& recipient);
	void showMenu() override;
};
