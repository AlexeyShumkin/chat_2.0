#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include "indexmap.h"

using Users = std::unordered_map<std::string, std::string>;
using Dataset = std::vector<std::string>;
using Dialog = std::list<Dataset>;
using Chats = std::vector<Dialog>;

class DataBase
{
public:
	virtual ~DataBase() = default;
	virtual bool handle(const Dataset& ds) = 0;
};

class LocalDB : public DataBase
{
public:
	LocalDB(IndexMap* imap);
	bool handle(const Dataset& ds) override;
private:
	Users userData_;
	Chats msgData_;
	IndexMap* indexData_;
};
