#include <fstream>

template <class TemplatePerson,class TemplateTicket>

class Repository {

private:
    TemplatePerson person;
    TemplateTicket ticket;
    int amountMoney;

public:
    Repository(){
        amountMoney = 0;
    }

    Repository(TemplatePerson& Person, int AmountMoney){
        person = Person;
        amountMoney = AmountMoney;
    }

    Repository(const Repository& copy){
        person = copy.person;
        amountMoney = copy.amountMoney;
    }

    void PayMoney(int amount){
        amountMoney -=amount;
    }
    bool operator == (Repository<Person,Ticket>& client) {
        if(this->amountMoney == client.amountMoney && this->person == client.person){
            return true;
        }
        return false;
    }

    bool operator != ( TemplatePerson& s){
        return !operator==(s);
    }

    void AddTicket(const TemplateTicket& Ticket){
        ticket = Ticket;
    }

    string ToString(){
        return person.ToString() + '\n'+"Amount money: " + to_string(amountMoney);
    }

    void WritePersonToFile() {
        ofstream outdata;
        outdata.open("OutputRepository.txt");
        outdata << (*this).ToString();
    }
};