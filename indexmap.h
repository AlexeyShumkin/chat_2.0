#pragma once
#include <string>
#include <unordered_map>

class IndexMap
{
public:
    int makeDialogID(const std::string& str1, const std::string& str2);
    void add(int uniqueNum);
    int search(int uniqueNum);
    int getIndex() const;
private:
    std::unordered_map<int, int> iMap_;
    int index_{ 1 };
};
