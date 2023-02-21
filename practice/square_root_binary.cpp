#include <iostream>
using namespace std;

long long binarySearch(long long target)
{
    long long s = 0, e = target;
    long long mid, square, ans = -1;

    while (s <= e)
    {
        // cout<<"S= "<<s<<" E= "<<e<<endl;
        mid = (s + e) / 2;
        // cout<<"mid = "<<mid<<endl;
        square = mid * mid;
        // cout<<"square = "<<square<<endl;
        if (square == target)
            return mid;
        else if (square < target)
        {
            // cout<<"square = "<<square<<"Target = "<<target<<endl;
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

int main()
{
    long long target;
    cin >> target;

    if (target == 1)
        cout << 1 << endl;
    else
        cout << binarySearch(target);

    return 0;
}