#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define ll long long
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// clang-format on

int dateCmp(string date1, string date2) {
    int year1 = stoi(date1.substr(6));
    int year2 = stoi(date2.substr(6));
    int mnt1 = stoi(date1.substr(3, 2));
    int mnt2 = stoi(date2.substr(3, 2));
    int day1 = stoi(date1.substr(0, 2));
    int day2 = stoi(date2.substr(0, 2));

    if (year1 == year2 && mnt1 == mnt2 && day1 == day2) {
        return 0;
    }

    if (year1 > year2) {
        return 1;
    } else if (mnt1 > mnt2) {
        return 1;
    } else if (day1 > day2) {
        return 1;
    } else {
        return 2;
    }
}

int timeCmp(string time1, string time2) {
    int sec1 = stoi(time1.substr(6));
    int sec2 = stoi(time2.substr(6));
    int min1 = stoi(time1.substr(3, 2)) * 60;
    int min2 = stoi(time2.substr(3, 2)) * 60;
    int h1 = stoi(time1.substr(0, 2)) * 3600;
    int h2 = stoi(time2.substr(0, 2)) * 3600;

    int total1 = sec1 + min1 + h1;
    int total2 = sec2 + min2 + h2;

    if (total1 > total2) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    FIO;

    int t;
    cin >> t;

    map<string, array<string, 3>> std;

    while (t--) {
        string dateTime, email, dob, bl;
        cin >> dateTime >> email >> dob >> bl;

        if (std.count(email)) {
            string date = dateTime.substr(0, 10);
            string timee = dateTime.substr(11);

            string date2 = std[email][0].substr(0, 10);
            string time2 = std[email][0].substr(11);

            int latest = dateCmp(date2, date);
            if (latest == 2) {
                std[email] = {dateTime, dob, bl};
            } else if (latest == 0) {
                int timecmp = timeCmp(time2, timee);
                if (timecmp == 2) {
                    std[email] = {dateTime, dob, bl};
                }
            }
        } else {
            std[email] = {dateTime, dob, bl};
        }
    }

    map<string, int> blg;
    map<string, int> cnt;
    string group[] = {"A+", "A-", "AB+", "AB-", "B+", "B-", "O+", "O-"};

    for (auto each : std) {
        blg[each.second[2]]++;
        string year = each.second[1].substr(6);
        cnt[year]++;
    }

    for (auto ele : group) {
        cout << ele << " " << blg[ele] << nl;
    }
    for (auto yr : cnt) {
        cout << yr.first << " " << yr.second << nl;
    }

    return 0;
}