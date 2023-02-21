#include <iostream>
using namespace std;

int haveStayed(int r, int b, bool *flag)
{
    int countB = r % (b + 1);
    int countR = r / (b + 1);
    if (countB == 0)
    {
        *flag = true;
    }
    else
    {
        countR++;
    }

    return countR;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, r, b, countR, len = 0;
        bool flag = false;
        cin >> n >> r >> b;

        int tempB = b;

        countR = haveStayed(r, b, &flag);

        while (len < n)
        {
            for (int i = 0; i < countR; i++)
            {

                cout << "R";
                len++;
            }
            if (b > 0)
            {
                b--;
                cout << "B";
            }

            len++;

            if (flag == false)
            {
                r -= countR;
                countR = haveStayed(r, b, &flag);
            }
        }

        cout << endl;
    }

    return 0;
}