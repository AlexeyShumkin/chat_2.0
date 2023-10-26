#include "chat.h"

int main()
{
    LocalDB db;
    Dataset ds;
    PubChat pub(&db);
    pub.reg();
    pub.sign();

}
