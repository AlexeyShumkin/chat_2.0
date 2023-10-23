#include "indexmap.h"

size_t IndexMap::getID(const std::string &str1, const std::string &str2)
{
    return makeID(str1, str2);
}

void IndexMap::add(size_t DialogID)
{
    iMap_.emplace(DialogID, index_++);
}

int IndexMap::search(size_t DialogID)
{
    auto it = iMap_.find(DialogID);
    if(it != iMap_.end())
        return it->second;
    return -1;
}

int IndexMap::getIndex() const
{
    return index_;
}

size_t IndexMap::makeID(const std::string &str1, const std::string &str2)
{
    size_t i = 0;
    size_t res = 0;
    size_t sum = str1.size() + str2.size();
    while(i < str1.size() && i < str2.size())
    {
        res += str1[i] + str2[i];
        ++i;
    }
    return res <<= sum;
}
