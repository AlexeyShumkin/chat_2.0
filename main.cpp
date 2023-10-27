#include "chat.h"

int main()
{
    LocalDB db;
    Chat pub(&db);
    pub.run();
}
