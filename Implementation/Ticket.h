using namespace std;
#include<string>

#ifndef AVICOMPANY_TICKET_H
#define AVICOMPANY_TICKET_H


class Ticket
{
private:
    string numberTicket;
    string placeInPlain;
public:
    Ticket();
    Ticket(string numberTicket, string placeInPlain);
    Ticket(const Ticket& copy);
    string ToString();
};

#endif //AVICOMPANY_TICKET_H
