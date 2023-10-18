#pragma once
#include"database.h"

class Connector
{
public:
	Connector(LocalDB* db) : db_{ db } {}
	bool query(const std::vector<std::string>& dataset);
	
private:
	DataBase* db_{ nullptr };
};
