#include "Implementation/Person.h"
#include "Implementation/Ticket.h"
#include "Implementation/Plaine.h"
#include "Implementation/Client.h"
#include <iostream>
#include <fstream>
#include <list>
#include <conio.h>

using namespace std;

void  ReadRaiceFromFile() {

    list<Plaine> raicelist;
    list<Ticket> ticketsOnPlain;
    for (int i = 1; i < 33; i++) {
        int random_number;
        random_number = 1000 + rand() % 9999;
        Ticket temp = Ticket(to_string(random_number), to_string(i));
        ticketsOnPlain.push_back(temp);
    }

    ifstream fileRaice("../InputFile/RaiceInput.txt");
    if (fileRaice.is_open()) {
        string countRaice;
        getline(fileRaice, countRaice);
        for (int i=0; i < stoi(countRaice); i++) {

            string nameRaice;
            getline(fileRaice, nameRaice); // 1 LINE
            string price;
            getline(fileRaice, price); // 2 LINE
            Plaine raice = Plaine(ticketsOnPlain, nameRaice, stoi(price));
            raicelist.push_back(raice);

        }
    }

    //find avarege of price in raices:
    int averagePrice=0;
    for (Plaine item : raicelist) {
        averagePrice += item.GetPrice();
    }

    averagePrice /= raicelist.size();
    cout  <<"Avarage price all raices = "<< averagePrice << endl;

    Plaine maxRaice;
    int maxelement = 0;
    for (Plaine item : raicelist) {

        if (maxelement < item.GetPrice()) {
            maxelement = item.GetPrice();
            maxRaice = item;
        }
    }

    cout << "Most expensive raice = "<< maxRaice.ToString() << endl;
}
int main(){
    //create new plain
    list<Ticket> ticketsOnPlain;
    for (int i = 1; i < 33; i++) {
        int random_number = 1000 + rand() % 9999;
        Ticket temp = Ticket(to_string(random_number), to_string(i));
        ticketsOnPlain.push_back(temp);
    }
    Plaine LvivKyiv = Plaine(ticketsOnPlain, "Lviv-Kyiv", 120);

    int i = 0;
    cout << "AviaCompany" << endl;
    cout << "1. Operator + (In class Plain) -> Add new passenger to plain " << endl;
    cout << "2. Operator == (In class Person)" << endl;
    cout << "3. Operator =! (In class Client)" << endl;
    cout << "4. Operator -- (In class Plain)" << endl;
    cout << "5. Operator << (In class Plain)" << endl;
    cout << "6. exit()" << endl;

    cin >> i;
    Person person1 = Person("Ivan Laska", "2112", "man", 21);
    Client newClient = Client(person1,500);
    if (i == 1) {
        cout << "----------------------------------" <<endl;
        cout << "Client" <<endl;
        cout << newClient.ToString()<<endl;
        cout << "----------------------------------" <<endl;
        cout << "Plaine"<<endl;
        cout << LvivKyiv.ToString();
        cout << "----------------------------------" <<endl;
        cout << "Before operator " << endl;
        cout << "All passengers: " << endl;
        LvivKyiv.GetAllPassager();
        cout << "----------------------------------" <<endl;
        LvivKyiv+newClient;
        cout << "After operator +"<< endl;
        LvivKyiv.GetAllPassager();
        cout << "----------------------------------" <<endl;
    }
    if(i == 2 ){
        Person person_1 = Person("Ivan Laska", "2112", "man", 21);
        Person person_2 = Person("Ivan Laska", "2112", "man", 21);
        cout << "----------------------------------" <<endl;
        cout << "Try to compare 2 person" <<endl;
        cout << "Person 1" <<endl;
        cout << person_1.ToString() <<endl;
        cout << "----------------------------------" <<endl;
        cout << "Person 2" <<endl;
        cout << person_2.ToString() <<endl;
        cout << "----------------------------------" <<endl;
        if(person_1 == person_2)
        {
            cout << "Persons equal" <<endl;
        }
        else
        {
            cout << "Persons not equal" <<endl;
        }

    }
    if(i == 3 ){
        Person person_1 = Person("Ivan Laska", "2112", "man", 21);
        Client client_1 = Client(person_1,120);
        Person person_2 = Person("Ivan Lasa", "2132", "man", 22);
        Client client_2 = Client(person_2,120);
        cout << "----------------------------------" <<endl;
        cout << "Try to compare 2 client" <<endl;
        cout << "Client 1" <<endl;
        cout << client_1.ToString() <<endl;
        cout << "----------------------------------" <<endl;
        cout << " Client 2" <<endl;
        cout << client_2.ToString() <<endl;
        cout << "----------------------------------" <<endl;
        if(client_1 != client_2)
        {
            cout << "Client not equal" <<endl;
        }
        else
        {
            cout << " Client equal" <<endl;
        }
    }
    if (i == 4){
        Person person_1 = Person("Ivan Laska", "2112", "man", 21);
        Client client_1 = Client(person_1,120);
        Person person_2 = Person("Ivan Lasa", "2132", "man", 22);
        Client client_2 = Client(person_2,120);
        Plaine plaine_1 = Plaine(ticketsOnPlain, "Test_race", 120);
        plaine_1 + client_1;
        plaine_1 + client_2;
        cout << "----------------------------------" <<endl;
        cout << "Before" <<endl;
        plaine_1.GetAllPassager();
        cout << "----------------------------------" <<endl;
        cout << "After" <<endl;
        --plaine_1;
        plaine_1.GetAllPassager();
        cout << "----------------------------------" <<endl;
    }
    if (i == 5){
        Plaine plaine_out = Plaine(ticketsOnPlain, "Plane_Out", 120);
        cout << plaine_out << endl;
    }
    if (i == 6){
        exit(0);
    }
}

int main1()
{

    list<Ticket> ticketsOnPlain;
    for (int i = 1; i < 33; i++) {
        int random_number = 1000 + rand() % 9999;
        Ticket temp = Ticket(to_string(random_number), to_string(i));
        ticketsOnPlain.push_back(temp);
    }
    Plaine LvivKyiv = Plaine(ticketsOnPlain, "Lviv-Kyiv", 120);
    Plaine KyivOdesa = Plaine(ticketsOnPlain, "Kyiv-Odesa", 100);
    Plaine OdesaRivne = Plaine(ticketsOnPlain, " Odesa-Rivne", 120);
    Plaine RivneLviv = Plaine(ticketsOnPlain, "Rivne-Lviv", 140);
    list<Plaine> AvaibleRaices;

    cout << LvivKyiv;
    AvaibleRaices.push_back(LvivKyiv);
    AvaibleRaices.push_back(KyivOdesa);
    AvaibleRaices.push_back(OdesaRivne);
    AvaibleRaices.push_back(RivneLviv);

    //string passportNumber, string gender, int age
    //Create a person
    int i = 0;
    cout << "AviaCompany" << endl;
    cout << "1. Add person" << endl;
    cout << "2. Read person from file" << endl;
    cout << "3. Would you want some date about races ?" << endl;
    cout << "4. Exit." << endl;
    cin >> i;
    Client newClient;
    if (i == 1) {
        cout << " Enter the full name" << endl;
        string fullName;
        cin >> fullName;
        cout << " Enter passport data" << endl;
        string passportNumber;
        cin >> passportNumber;
        cout << "Enter gender" << endl;
        string gender;
        cin >> gender;
        cout <<"Age" << endl;
        int age;
        cin >> age;
        cout << "Amount of money" << endl;
        int amountofMoney;
        cin >> amountofMoney;
        Person newPerson = Person(fullName, passportNumber, gender, age);
        newClient = Client(newPerson, amountofMoney);
        cout << "Client successful created" << endl;
    }
    if (i == 2){
        newClient.ReadFromFile();
        cout << "Client successful readed" << endl;

    }
    if (i == 3) {
        ReadRaiceFromFile();
        system("pause");
    }
    if (i == 4) {
        exit(0);
    }

    system("CLS");
    cout << "Avia Company" << endl;
    cout << "1. Choose Plaine " << endl;
    cout << "2. View current client " << endl;
    cout << "3. Exit." << endl;
    cin >> i;
    int option;
    if (i == 1) {
        int i = 0;
        for (Plaine item : AvaibleRaices) {
            i++;
            cout << to_string(i) +" "+ item.ToString();
        }
        cout << "Choice your raice" << endl;
        cin >> option;
        option -= 1;
        list<Plaine> ::iterator it = AvaibleRaices.begin(); // ???????? ?????? ???????? ??*??? ? ????
        advance(it, option);
        cout << " Your choosen" << (*it).ToString() << endl;
        (*it) + newClient;
        cout << "Passsager successful added";

    }
    if (i == 2) {
        cout << newClient.ToString();
    }
    if (i == 3) {
        exit(0);
    }
    newClient.WritePersonToFile();

    return 0;
}
