#include "chat.h"

int main()
{
    IndexMap imap;
    LocalDB db(&imap);
    Connector cn(&db);
    Chat chat(&cn);
    while(true)
    {
        std::string sender;
	    std::string recipient;
	    std::cout << "sender: ";
	    std::cin >> sender;
	    std::cout << "recipient: ";
	    std::cin >> recipient;
        chat.post(sender, recipient);
    }
}
