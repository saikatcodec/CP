#include <iostream>
using namespace std;

main()
{
    int flag = 0;
    for (int i = 1000; i >= 1; i--)
    {
        if (flag == 5)
        {
            flag = 0;
            cout << endl;
        }
        cout << i << "\t";
        flag++;
    }

    return 0;
}