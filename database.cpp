#include "database.h"

bool LocalDB::processRequest(const Dataset& ds)
{
	if (ds.size() == 2)
	{
		auto it = userData_.find(ds[0]);
		if (it != userData_.end())
			return false;
		userData_.emplace(ds[0], ds[1]);
		return true;
	}
	else if (ds.size() == 3)
	{
		auto it = userData_.find(ds[0]);
		if (it != userData_.end() && it->second == ds[1])
			return true;
		return false;
	}
	else if(ds.size() == 4 && ds[2] != "")
	{
		msgData_.add(ds);
		return true;
	}
	else
		return false;
}
