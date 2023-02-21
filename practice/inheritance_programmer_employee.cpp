#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    int id;
    float salary;

    Employee() {} // set default constructor for inheritance

    Employee(int inpId)
    {
        id = inpId;
        salary = 234.32;
    }

    void about()
    {
        cout << id << " " << salary << endl;
    }
};

// Inheritance of Employee class
class Programmer : public Employee
{
public:
    Programmer(int inpId)
    {
        id = inpId;
        salary = 343;
    }
};

int main()
{
    Employee joy(3);
    joy.about();

    Programmer pg(4);
    pg.about();

    return 0;
}