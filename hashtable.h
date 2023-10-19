#pragma once
#include<string>
#include<vector>

using Dataset = std::vector<std::string>;

struct MsgNode
{
    Dataset ds_;
    MsgNode* next_{ nullptr };
    MsgNode(const Dataset& ds);
    ~MsgNode();
};

class HashTable
{
public:
    HashTable();
    ~HashTable();
    void addMsg(const Dataset& ds);
    MsgNode* getDialog(const Dataset& ds);
    void resize();
private:
    int hash(const std::string& sender, const std::string& recipient);
    MsgNode** dialogs_{ nullptr };
    int memSize_{ 10 };
    int counter_{ 0 };
};
