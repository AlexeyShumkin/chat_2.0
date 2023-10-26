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
};

class LocalDB : public DataBase
{
public:
	LocalDB();
	bool handle(const Dataset& ds) override;
private:
	fs::path userDataPath_{ "userData"s };
	fs::path msgDataPath_{ "msgData"s };
	std::fstream fst_;
	size_t makeDialogID(const std::string& sender, const std::string& recipient);
};
