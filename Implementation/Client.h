#include "Person.h"
#include "Ticket.h"


#ifndef AVICOMPANY_CLIENT_H
#define AVICOMPANY_CLIENT_H



class Client{
private:
    Person person;
    Ticket ticket;
    int amountMoney;

public:
    Client();
    Client(Person& person, int amountMoney);
    Client(const Client& copy);
    void PayMoney(int amount);
    bool operator == (Client& client);
    bool operator != ( Client& s) ;
    void AddTicket(const Ticket& ticket);
    string ToString();
    void WritePersonToFile();
    void ReadFromFile();

};



#endif //AVICOMPANY_CLIENT_H
