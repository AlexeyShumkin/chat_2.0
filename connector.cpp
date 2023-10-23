#include "connector.h"

Connector::Connector(DataBase *db) : db_{ db } {}

bool Connector::query(const Dataset &ds)
{
	return db_->handle(ds);
}
