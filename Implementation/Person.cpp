#include "Person.h"
#include <string>
using namespace std;

Person::Person()
{
    (*this).fullName = "No data";
    (*this).passportNumber = "No data";
    (*this).gender = "No data";
    (*this).age = 0;
}

Person::Person(string fullName, string passportNumber, string gender, int age)
{
    (*this).fullName = std::move(fullName);
    (*this).passportNumber = std::move(passportNumber);
    (*this).gender = std::move(gender);
    (*this).age = age;
}

Person::Person(const Person& copy)
{
    (*this).fullName =copy.fullName;
    (*this).passportNumber = copy.passportNumber;
    (*this).gender = copy.gender;
    (*this).age = copy.age;
}

string Person::ToString()
{
    return "Person Info: \nFull name:" + fullName + " \nPassport Number: " + passportNumber + "\nGender: "+gender+"\nAge: " + to_string(age) ;
}

bool Person::operator==(Person &person) {
    if(this->age==person.age && this->fullName==person.fullName && this->gender == person.gender && person.passportNumber == this->passportNumber ){
        return true;
    }
    return false;
}
