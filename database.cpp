#include "database.h"

LocalDB::LocalDB()
{
	fs::create_directory(userDataPath_);
	fs::create_directory(msgDataPath_);
}

bool LocalDB::handle(const Dataset& ds)
{
    if(ds[0] == "REG"s && !fs::exists(userDataPath_ / ds[1]))
    {
        fst_.open(userDataPath_ / ds[1], std::fstream::out);
        if(fst_.is_open())
        {
            fst_ << ds[2];
            fst_.close();
            return true;
        }
    }
    else if(ds[0] == "SIGN"s && fs::exists(userDataPath_ / ds[1]))
    {
        std::string tmp;
        fst_.open(userDataPath_ / ds[1], std::fstream::in);
        if(fst_.is_open())
        {
            fst_ >> tmp;
            fst_.close();
        }
        if(ds[2] == tmp)
            return true;
    }
    else if(ds[0] == "FIND"s && fs::exists(userDataPath_ / ds[1]))
        return true;
    else if(ds.size() == 4)
    {
        if(ds[1] == "all"s)
        {
            fst_.open(msgDataPath_ / ds[1], std::fstream::app |  std::fstream::out);
            if(fst_.is_open())
            {
                fst_ << ds[0] << " -> " << ds[1] << " | " << ds[2] << " | " << ds[3] << '\n';
                fst_.close();
                return true;
            }
        }
        auto dialog = std::to_string(makeDialogID(ds[0], ds[1]));
        fst_.open(msgDataPath_ / dialog, std::fstream::app |  std::fstream::out);
        if(fst_.is_open())
        {
            fst_ << ds[0] << " -> " << ds[1] << " | " << ds[2] << " | " << ds[3] << '\n';
            fst_.close();
            return true;
        }
    }
    return false;
}

const Dataset& LocalDB::reply(Dataset& ds)
{
    if(ds[0] == "USERS"s)
        ds[0] = userDataPath_;
    else if(ds[0] == "PUB"s)
        ds[0] = msgDataPath_ / "all"s;
    else if(ds[0] == "PVT"s)
    {
        ds.clear();
        auto dialog = std::to_string(makeDialogID(ds[1], ds[2]));
        if(!fs::exists(msgDataPath_ / dialog))
            return ds;
        ds.push_back(msgDataPath_ / dialog);
    }
    else
        ds.clear();
    return ds;
}

size_t LocalDB::makeDialogID(const std::string& sender, const std::string& recipient)
{
    size_t i = 0;
    size_t res = 0;
    size_t sum = sender.size() + recipient.size();
    while(i < sender.size() && i < recipient.size())
    {
        res += sender[i] + recipient[i];
        ++i;
    }
    return res <<= sum;
}
