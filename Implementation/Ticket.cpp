#include "Ticket.h"
#include <string>
using namespace std;

Ticket::Ticket()
{
    (*this).numberTicket = "No data";
    (*this).placeInPlain = "No data";
}

Ticket::Ticket(string numberTicket, string place)
{
    (*this).numberTicket = numberTicket;
    (*this).placeInPlain = place;
}

Ticket::Ticket(const Ticket& copy)
{
    (*this).numberTicket = copy.numberTicket;
    (*this).placeInPlain = copy.placeInPlain;
}

string Ticket::ToString()
{
    return "Ticket Info: \nNumber ticket: " + numberTicket  + " \nPlace: " + placeInPlain + "\n";
}
