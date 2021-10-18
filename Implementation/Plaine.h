#include<string>
using namespace std;
#include <list>
#include "Ticket.h"
#include "Client.h"

#ifndef AVICOMPANY_PLAINE_H
#define AVICOMPANY_PLAINE_H


class Plaine {

    private:
        list<Client> raicePasangers;
        list<Ticket> listOfTickets;
        string nameRaice;
        int price;

    public:
        Plaine();
        Plaine(list<Ticket>& ticket,string nameRaice,int price);
        Plaine(const Plaine& copy);
        void AddPassager(Client& client);
        int GetPrice();
        void operator+(Client& client);
        friend ostream& operator<<(ostream& os, const Plaine& obj);
        bool operator == (Plaine& client);
        Plaine& operator--();
        void GetAllPassager();
        void GetAvailibleTicket();
        string ToString();
};


#endif //AVICOMPANY_PLAINE_H
