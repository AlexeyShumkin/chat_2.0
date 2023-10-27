#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

using Dataset = std::vector<std::string>;
using namespace std::string_literals;
namespace fs = std::filesystem;

class DataBase
{
public:
	virtual ~DataBase() = default;
	virtual bool handle(const Dataset& ds) = 0;
	virtual const Dataset& reply(Dataset& ds) = 0;
};

class LocalDB : public DataBase
{
public:
	LocalDB();
	bool handle(const Dataset& ds) override;
	const Dataset& reply(Dataset& ds) override;
private:
	fs::path userDataPath_{ "data/userData"s };
	fs::path msgDataPath_{ "data/msgData"s };
	std::fstream fst_;
	size_t makeDialogID(const std::string& sender, const std::string& recipient);
	size_t hashFunction(const std::string& password);
};
