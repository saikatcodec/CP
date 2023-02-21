#include <bits/stdc++.h>
using namespace std;

class employee
{
    int id;
    int salary;
    static int counter;

public:
    void setdata(void);
    void about(void);
    static void getCounter(void)
    {
        cout << "Present Employee number is " << counter << endl;
    }
};

int employee ::counter;

void employee ::setdata(void)
{
    salary = 1000;
    cout << "Enter your employee id ";
    cin >> id;
    counter++;
}

void employee ::about(void)
{
    cout << counter << ". Employee's id is " << id << endl;
}

int main()
{
    employee em, emm, emn;

    em.setdata();
    em.about();
    employee ::getCounter();

    emm.setdata();
    emm.about();
    employee ::getCounter();

    emn.setdata();
    emn.about();
    employee ::getCounter();

    return 0;
}