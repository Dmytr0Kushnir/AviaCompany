#include "Plaine.h"
#include <string>
#include <iostream>
using namespace std;

Plaine::Plaine()
{
    (*this).nameRaice = "No data";
    (*this).price = 0;
    (*this).raicePasangers = list<Client>();
    (*this).listOfTickets = list<Ticket>();
}

Plaine::Plaine(list<Ticket>& ticket, string nameRaice, int price)
{
    (*this).nameRaice = std::move(nameRaice);
    (*this).price = price;
    (*this).raicePasangers = list<Client>();
    (*this).listOfTickets = ticket;
}

Plaine::Plaine(const Plaine& copy)
{
    (*this).nameRaice = copy.nameRaice;
    (*this).price = copy.price;
    (*this).raicePasangers = copy.raicePasangers;
    (*this).listOfTickets = copy.listOfTickets;
}

void Plaine::GetAvailibleTicket(){

    for (Ticket ticket : (*this).listOfTickets)
    {
        std::cout << ticket.ToString() << endl;
    }

}
void Plaine::GetAllPassager() {

    for (Client client : (*this).raicePasangers)
    {
        std::cout << client.ToString() << endl;
    }
}

void Plaine::AddPassager(Client& client) {
    try {
        Ticket lastTicket =Ticket(listOfTickets.back());
        listOfTickets.pop_back();
        client.PayMoney(price);
        client.AddTicket(lastTicket);
        raicePasangers.push_back(client);
    }
    catch (const char* msg)
    {
        std::cout << msg << std::endl;
    }
}

int Plaine::GetPrice()
{
    return price;
}

string Plaine::ToString()
{
    return "Name raice: " + nameRaice + '\n' + "Price: " + to_string(price) + '\n';
}
    
void Plaine::operator+(Client &client) {
    AddPassager(client);
    cout << "Operator + successful usage" << endl;
}

bool Plaine::operator==(Plaine &plaine) {

        return this->nameRaice == plaine.nameRaice && this->price == plaine.price;
    }


Plaine& Plaine::operator--() {
    raicePasangers.pop_back();
    cout << "Operator - successful usage" << endl;
    return *this;
}

ostream &operator<<(ostream &os, const Plaine &obj) {
    os << "Name plaine: " + obj.nameRaice + '\n' + "Price: " + to_string(obj.price) + '\n';
    return os;
}




