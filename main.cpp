#include "library.h"

int main()
{
    Session session;
    Library library(session);
    library.run();
    return 0;
}
