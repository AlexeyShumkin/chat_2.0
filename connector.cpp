#include "connector.h"

bool Connector::query(const std::vector<std::string>& dataset)
{
	return db_->processRequest(dataset);
}
