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
			std::cout << "from: " << msg[0] << '\n' << "to: " << msg[1] << '\n' << msg[2] << '\n' << msg[3] << std::endl;
		return true;
	}
	else if(ds[0] == "DIALOG")
	{
		MsgNode* dialog = pvtMsgData_.getDialog(ds);
		MsgNode* currentMsg = dialog;
		while(currentMsg != nullptr)
		{
			std::cout << "from: " << currentMsg->ds_[0] << '\n' << "to: " << currentMsg->ds_[1] << '\n' << currentMsg->ds_[2] << '\n' << currentMsg->ds_[3] << std::endl;
			currentMsg = currentMsg->next_;
		}
		return true;
	}
	else if (ds[2] == "")
		return false;
	else
	{
		if(ds[1] != "all")
		{
			pvtMsgData_.addMsg(ds);
			return true;
		}
		else
		{
			msgData_.push_back(ds);
			return true;
		}
	}	
}
