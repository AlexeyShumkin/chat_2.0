#include "indexmap.h"

int IndexMap::makeDialogID(const std::string &str1, const std::string &str2)
{
    int i = 0;
    int res = 0;
    int sum = str1.size() + str2.size();
    while(i < str1.size() && i < str2.size())
    {
        res += str1[i] + str2[i];
        ++i;
    }
    return res <<= sum;
}

void IndexMap::add(int uniqueNum)
{
    iMap_.emplace(uniqueNum, index_++);
}

int IndexMap::search(int uniqueNum)
{
    auto it = iMap_.find(uniqueNum);
    if(it != iMap_.end())
        return it->second;
    return -1;
}

int IndexMap::getIndex() const
{
    return index_;
}
