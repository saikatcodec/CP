#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string s;

    bool isPalindrome(int i, int j) {
        for (int k = 0; k <= (j - i) / 2; k++) {
            if (s[i + k] != s[j - k]) {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> dp(int i) {
        if (i >= s.size()) {
            return vector<vector<string>>();
        }

        vector<vector<string>> ans;
        for (int k = i; k < s.size(); k++) {
            if (isPalindrome(i, k)) {
                vector<vector<string>> res = dp(k + 1);
                string ss = s.substr(i, k - i + 1);

                for (auto &x : res) {
                    x.insert(x.begin(), ss);
                }

                if (res.empty()) {
                    res.push_back({ss});
                }

                for (auto x : res) {
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }

    vector<vector<string>> partition(string s) {
        this->s = s;

        return dp(0);
    }
};

int main() {
    string s;
    cin >> s;

    Solution S;

    return 0;
}