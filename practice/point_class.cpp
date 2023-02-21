#include <bits/stdc++.h>
using namespace std;

class Point
{
    int x, y;
    friend float distance(Point, Point);

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    void displayPoint()
    {
        cout << "Point is (" << x << ", " << y << ")" << endl;
    }
};

float distance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
    Point p1(1, 0);
    p1.displayPoint();

    Point p2(70, 0);
    p2.displayPoint();

    cout << "Distance between two point " << distance(p1, p2) << endl;

    return 0;
}