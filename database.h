#pragma once
#include <vector>
#include <list>
#include "indexmap.h"

using Dataset = std::vector<std::string>;
using Dialog = std::list<Dataset>;

class DataBase
{
public:
	virtual ~DataBase() = default;
	virtual bool processRequest(const Dataset& ds) = 0;
};

class LocalDB : public DataBase
{
public:
	LocalDB(IndexMap* imap);
	bool processRequest(const Dataset& ds) override;
private:
	std::unordered_map<std::string, std::string> userData_;
	std::vector<Dialog> msgData_;
	IndexMap* indexData_;
};
