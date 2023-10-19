#include "database.h"

bool LocalDB::processRequest(const Dataset& ds)
{
	if (ds[0] == "REG")
	{
		auto it = userData_.find(ds[1]);
		if (it != userData_.end())
			return false;
		userData_.emplace(ds[1], ds[2]);
		return true;
	}
	else if (ds[0] == "SIGN")
	{
		auto it = userData_.find(ds[1]);
		if (it != userData_.end() && it->second == ds[2])
			return true;
		return false;
	}
	else if (ds[0] == "READ")
	{
		for (auto& msg : msgData_)
			std::cout << "to: " << msg[0] << '\n' << "from: " << msg[1] << '\n' << msg[2] << '\n' << msg[3] << std::endl;
		return true;
	}
	else if (ds[2] == "")
		return false;
	else
	{
		msgData_.push_back(ds);
		return true;
	}	
}
