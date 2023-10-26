#pragma once
#include "database.h"

class PubChat
{
public:
	PubChat() = default;
	PubChat(DataBase* db);
	virtual ~PubChat() = default;
	virtual void run() final;
	virtual void reg() final;
	virtual void sign() final;
	virtual void showMenu();
	void post();
	std::string getTime();
protected:
	DataBase* db_{ nullptr };
	std::string currentUser_;
	std::string recipient_ = "all"s;
};

class PvtChat : public PubChat
{
public:
	PvtChat(DataBase* db, const std::string& currentUser, const std::string& recipient);
	void showMenu() override;
};
