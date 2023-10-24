#include "database.h"

LocalDB::LocalDB(IndexMap *imap) : indexData_{ imap } 
{
	msgData_.resize(1);
}

bool LocalDB::handle(const Dataset &ds)
{
	if (ds.size() == 2)
	{
		if(ds[0] == "all")
			return false;
		auto it = userData_.find(ds[0]);
		if (it != userData_.end())
			return false;
		userData_.emplace(ds[0], ds[1]);
		return true;
	}
	else if (ds[0] == "SIGN")
	{
		auto it = userData_.find(ds[1]);
		if (it != userData_.end() && it->second == ds[2])
			return true;
		return false;
	}
	
	else if(ds.size() == 4)
	{
		if(ds[2] == "")
			return false;
		if(ds[1] == "all")
		{
			msgData_[0].push_back(ds);
			return true;
		}
		else
		{
			size_t dialogID = indexData_->getID(ds[0], ds[1]);
			int index = indexData_->search(dialogID);
			if(index <= 0)
			{
				index = indexData_->getIndex();
				if(index >= msgData_.size())
					msgData_.resize(index + 1);
				msgData_[index].push_back(ds);
				indexData_->add(dialogID);
			}
			else
			{
				if(index >= msgData_.size())
					msgData_.resize(index + 1);
				msgData_[index].push_back(ds);
			}
			return true;
		}
	}
	else
		return false;
}

void LocalDB::zip(const std::string& path)
{
	std::fstream out;
    out.open(path, std::fstream::app | std::fstream::out);
    if(out.is_open())
    {
        out << userData_.size();
        for(const auto& u : userData_)
            out << ' ' << u.first << ' ' << u.second;
        out.close();
    }
	else
		std::cout << "Failed to open file!\n";
}

void LocalDB::unzip(const std::string& path)
{

	std::fstream in;
	in.open(path, std::fstream::in);
	if(in.is_open())
	{
		size_t size = 0;
		in >> size;
		for(size_t i = 0; i < size; ++i)
		{
			std::string key;
			std::string val;
			in >> key >> val;
			userData_.emplace(key, val);
		}
	}
	else
		std::cout << "Failed to open file!\n";
}
