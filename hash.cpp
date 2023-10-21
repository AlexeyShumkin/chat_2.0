#include "hash.h"

void HashTable::add(const Dataset &ds)
{
    size_t index = hash(ds[0], ds[1]);
    if(index >= dialogData_.size())
    {
        dialogData_.resize(index + 1);
        dialogData_[index].push_back(ds);
    }
    else
        dialogData_[index].push_back(ds);
}

size_t HashTable::hash(const std::string &sender, const std::string &recipient)
{
    size_t i = 0;
    size_t sum = sender.size() + recipient.size();
    size_t res = 0;
    while(i < sender.size() && i < recipient.size())
    {
        res += sender[i] + recipient[i];
        ++i;
    }
    return (res << sum) % sum;
}
