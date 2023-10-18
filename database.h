#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

class DataBase
{
public:
	virtual ~DataBase() = default;
	virtual bool processRequest(const std::vector<std::string>& dataset) = 0;
};

class LocalDB : public DataBase
{
public:
	bool processRequest(const std::vector<std::string>& dataset) override;
private:
	std::unordered_map<std::string, std::string> userData_;
	std::vector<std::vector<std::string>> msgData_;
};
