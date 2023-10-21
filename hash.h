#pragma once
#include<string>
#include<vector>
#include<list>

using Dataset = std::vector<std::string>;
using Dialog = std::list<Dataset>;

class HashTable
{
public:
    void add(const Dataset& ds);
private:
    size_t hash(const std::string& sender, const std::string& recipient);
    std::vector<Dialog> dialogData_;
};
