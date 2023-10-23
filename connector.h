#pragma once
#include "database.h"

class Connector
{
public:
	Connector(DataBase* db);
	bool query(const Dataset& ds);
	
private:
	DataBase* db_{ nullptr };
};
