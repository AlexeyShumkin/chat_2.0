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
    return false;
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
