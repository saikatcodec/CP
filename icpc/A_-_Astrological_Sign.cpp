#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int d;
        string s;
        cin >> d >> s;

        if (s == "Jan")
        {
            if (d <= 20)
                cout << "Capricorn" << nl;
            else
                cout << "Aquarius" << nl;
        }
        else if (s == "Feb")
        {
            if (d <= 19)
                cout << "Aquarius" << nl;
            else
                cout << "Pisces" << nl;
        }
        else if (s == "Mar")
        {
            if (d <= 20)
                cout << "Pisces" << nl;
            else
                cout << "Aries" << nl;
        }
        else if (s == "Apr")
        {
            if (d <= 20)
                cout << "Aries" << nl;
            else
                cout << "Taurus" << nl;
        }
        else if (s == "May")
        {
            if (d <= 20)
                cout << "Taurus" << nl;
            else
                cout << "Gemini" << nl;
        }
        else if (s == "Jun")
        {
            if (d <= 21)
                cout << "Gemini" << nl;
            else
                cout << "Cancer" << nl;
        }
        else if (s == "Jul")
        {
            if (d <= 22)
                cout << "Cancer" << nl;
            else
                cout << "Leo" << nl;
        }
        else if (s == "Aug")
        {
            if (d <= 22)
                cout << "Leo" << nl;
            else
                cout << "Virgo" << nl;
        }
        else if (s == "Sep")
        {
            if (d <= 21)
                cout << "Virgo" << nl;
            else
                cout << "Libra" << nl;
        }
        else if (s == "Oct")
        {
            if (d <= 22)
                cout << "Libra" << nl;
            else
                cout << "Scorpio" << nl;
        }
        else if (s == "Nov")
        {
            if (d <= 22)
                cout << "Scorpio" << nl;
            else
                cout << "Sagittarius" << nl;
        }
        else
        {
            if (d <= 21)
                cout << "Sagittarius" << nl;
            else
                cout << "Capricorn" << nl;
        }
    }

    return 0;
}