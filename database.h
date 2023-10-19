#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using Dataset = std::vector<std::string>;

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
	std::vector<Dataset> msgData_;
};
