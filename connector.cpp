#include "connector.h"

bool Connector::query(const Dataset& ds)
{
	return db_->processRequest(ds);
}
