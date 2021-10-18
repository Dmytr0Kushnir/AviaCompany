#include <string>

using namespace std;

#ifndef AVICOMPANY_PERSON_H
#define AVICOMPANY_PERSON_H


class Person
{
private:
    string fullName;
    string passportNumber;
    string gender;
    int age;

public:
    Person();
    Person(string fullName, string passportNumber, string gender, int age);
    Person(const Person& copy);
    bool operator == (Person& person);
    string ToString();
};


#endif //AVICOMPANY_PERSON_H
