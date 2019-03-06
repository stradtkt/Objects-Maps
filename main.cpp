#include <iostream>
#include <map>
using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person(string name, int age) :
        name(name), age(age) {

    }
    Person(const Person &other) {
        cout << "Copy constructor running" << endl;
        name = other.name;
        age = other.age;
    }
    void print() const {
        cout << name << ": " << age << flush;
    }
    bool operator<(const Person &other) const {
        if(name == other.name) {
            return age < other.age;
        } else {
            return name < other.name;
        }
    }
};

int main() {
    map<Person, int> people;
    people[Person("Kevin", 29)] = 29;
    people[Person("Debra", 61)] = 61;
    people[Person("Patrick", 32)] = 32;
//    people[0] = Person("Mike", 40);
//    people[1] = Person("Vicky", 30);
//    people[2] = Person("Kevin", 20);

    for(map<Person, int>::iterator it=people.begin(); it != people.end(); it++) {
        it->second.print();
    }

    return 0;
}