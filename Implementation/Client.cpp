#include "Client.h"
#include "Person.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


Client::Client()
{
    (*this).amountMoney = 0;
}

Client::Client(Person& person, int amountMoney)
{
    (*this).person = person;
    (*this).amountMoney = amountMoney;
}

Client::Client(const Client& copy)
{
    (*this).person = copy.person;
    (*this).amountMoney = copy.amountMoney;
}

void Client::AddTicket(const Ticket& ticket) {

    (*this).ticket = ticket;
}

void Client::PayMoney(int amount) {
    (*this).amountMoney -= amount;
}

string Client::ToString()
{
    return person.ToString() + '\n'+"Amount money: " + to_string(amountMoney);
}

void Client::WritePersonToFile() {
    ofstream outdata;
    outdata.open("ClientOutput.txt");
    outdata << (*this).ToString();
}
void Client::ReadFromFile() {

    ifstream MyFile("InputFile/ClientInput.txt");
    if (MyFile.is_open()) {
        string fullName;
        getline(MyFile, fullName); // 1 LINE
        string passport;
        getline(MyFile, passport); // 2 LINE
        string gender;
        getline(MyFile, gender); // 3 LINE
        string age;
        getline(MyFile, age); // 4 LINE
        string countOfMoney;
        getline(MyFile, countOfMoney);

        Person personFromFile = Person(fullName, passport, gender, stoi(age));
        (*this) = Client(personFromFile, stoi(countOfMoney));

    }
}

bool Client::operator==(Client &client) {
    if(this->amountMoney == client.amountMoney && this->person == client.person){
        return true;
    }
    return false;
}

bool Client::operator!=( Client &s) {
    return !operator==(s);
}
