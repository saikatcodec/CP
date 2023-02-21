#include <bits/stdc++.h>
using namespace std;

class Animal
{
private:
    string type, name;
    int legs;

public:
    int age;

    void init(string type1, string name1, int legs1);
    void about()
    {
        cout << "Name of animals is " << name << endl;
        cout << "Animals type is " << type << endl;
        cout << "Age of " << name << " is " << age << " years" << endl;
    }
};

void Animal ::init(string type1, string name1, int legs1)
{
    type = type1;
    name = name1;
    legs = legs1;
}

int main()
{
    Animal dog;
    dog.init("dog", "Tommy", 4);
    dog.age = 4;
    dog.about();

    return 0;
}