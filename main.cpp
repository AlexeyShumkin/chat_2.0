#include"chat.h"

int main()
{
    LocalDB db;
    Connector cn(&db);
    Chat chat(&cn);
}
