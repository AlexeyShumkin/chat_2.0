#include "database.h"

bool LocalDB::processRequest(const std::vector<std::string>& dataset)
{
	if (dataset[0] == "REG")
	{
		auto it = userData_.find(dataset[1]);
		if (it != userData_.end())
			return false;
		userData_.emplace(dataset[1], dataset[2]);
		return true;
	}
	else if (dataset[0] == "SIGN")
	{
		auto it = userData_.find(dataset[1]);
		if (it != userData_.end() && it->second == dataset[2])
			return true;
		return false;
	}
	else if (dataset[0] == "READ")
	{
		for (auto& msg : msgData_)
			std::cout << msg[0] << ' ' << msg[1] << ' ' << msg[2] << ' ' << msg[3] << std::endl;
		return true;
	}
	else if (dataset[2] == "")
		return false;
	else
	{
		msgData_.push_back(dataset);
		return true;
	}	
}
