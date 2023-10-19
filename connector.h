#pragma once
#include"database.h"

class Connector
{
public:
	Connector(DataBase* db) : db_{ db } {}
	bool query(const Dataset& ds);
	
private:
	DataBase* db_{ nullptr };
};
