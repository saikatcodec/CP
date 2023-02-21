#include <bits/stdc++.h>
using namespace std;

class Student
{
protected:
    int roll_no;

public:
    void set_roll(int r)
    {
        roll_no = r;
    }
};

/**
 * @brief Use virtual base class because
 * Student --> Test
 * Student --> Sport
 * Test --> Result
 * Sport --> Result
 *
 */
class Test : virtual public Student
{
protected:
    int math, physics;

public:
    void set_marks(int m, int p)
    {
        math = m;
        physics = p;
    }
};

class Sport : virtual public Student
{
protected:
    int score;

public:
    void set_score(int sc)
    {
        score = sc;
    }
};

class Result : public Test, public Sport
{
    int total;

public:
    void display(void)
    {
        cout << "Your roll number is " << roll_no << endl
             << "Your marks are: " << endl
             << "Math: " << math << endl
             << "Physics: " << physics << endl
             << "Your PT score is " << score << endl
             << "Total score is " << math + physics + score << endl;
    }
};

int main()
{
    Result joy;
    joy.set_roll(200126);
    joy.set_marks(89, 99);
    joy.set_score(4);
    joy.display();

    return 0;
}