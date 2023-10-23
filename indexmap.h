#pragma once
#include <string>
#include <unordered_map>

class IndexMap
{
public:
    size_t getID(const std::string& str1, const std::string& str2);
    void add(size_t DialogID);
    int search(size_t DialogID);
    int getIndex() const;
private:
    size_t makeID(const std::string& str1, const std::string& str2);
    std::unordered_map<size_t, int> iMap_;
    int index_{ 1 };
};
