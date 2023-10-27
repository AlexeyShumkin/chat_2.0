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
	void read(const fs::path& path);
	std::string getTime();
protected:
	DataBase* db_{ nullptr };
	std::string currentUser_;
	std::string recipient_ = "all"s;
};

class Dialog : public Chat
{
public:
	Dialog(DataBase* db, const std::string& currentUser, const std::string& recipient);
	void showMenu() override;
};
