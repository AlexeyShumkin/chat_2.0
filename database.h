#pragma once
#include<iostream>
#include<unordered_map>
#include"hash.h"

class DataBase
{
public:
	virtual ~DataBase() = default;
	virtual bool processRequest(const Dataset& ds) = 0;
};

class LocalDB : public DataBase
{
public:
	bool processRequest(const Dataset& ds) override;
private:
	std::unordered_map<std::string, std::string> userData_;
	HashTable msgData_;
};
