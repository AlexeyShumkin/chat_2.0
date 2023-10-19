#include "hashtable.h"

MsgNode::MsgNode(const Dataset& ds) : ds_{ ds } {}

MsgNode::~MsgNode()
{
    if(next_ != nullptr)
        delete next_;
}

HashTable::HashTable()
{
    dialogs_ = new MsgNode*[memSize_];
    for(int i = 0; i < memSize_; ++i)
        dialogs_[i] = nullptr;
}

HashTable::~HashTable()
{
    for(int i = 0; i < memSize_; ++i)
    {
        if(dialogs_[i] != nullptr)
            delete dialogs_[i];
    }
    delete[] dialogs_;
}

void HashTable::addMsg(const Dataset& ds)
{
    if(counter_ >= memSize_)
        resize();
    int index = hash(ds[0], ds[1]);
    if(dialogs_[index] != nullptr)
    {
        MsgNode* newNode = new MsgNode(ds);
        newNode->next_ = dialogs_[index];
        dialogs_[index] = newNode;
    }
    else
    {
        dialogs_[index] = new MsgNode(ds);
        ++counter_;
    }
}

MsgNode* HashTable::getDialog(const Dataset& ds)
{
    int index = hash(ds[1], ds[2]);
    if(dialogs_[index] != nullptr)
        return dialogs_[index];
    return nullptr;
}

void HashTable::resize()
{
    MsgNode** save = dialogs_;
    int oldSize = memSize_;
    memSize_ *= 2;
    counter_ = 0;
    dialogs_ = new MsgNode*[memSize_];
    for(int i = 0; i < memSize_; ++i)
        dialogs_[i] = nullptr;
    for(int i = 0; i < oldSize; ++i)
    {
        MsgNode* current = save[i];
        while(current != nullptr)
        {
            addMsg(current->ds_);
            current = current->next_;
        }
    }
    for(int i = 0; i < oldSize; ++i)
    {
        if(save[i] != nullptr)
            delete save[i];
    }
    delete[] save;
}

int HashTable::hash(const std::string &sender, const std::string &recipient)
{
    size_t i = 0;
    int sum = 0;
    while(i < sender.size() && i < recipient.size())
        sum += sender[i] + recipient[i];
    return sum % memSize_;
}
