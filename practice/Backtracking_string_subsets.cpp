#include <bits/stdc++.h>
using namespace std;

void subsets(char *in, char *out, int i, int j) {
    // Base Case
    if (in[i] == '\0') {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // Recursive Case
    out[j] = in[i];
    // Include
    subsets(in, out, i + 1, j + 1);

    // Exclude
    subsets(in, out, i + 1, j);
}

int main() {
    char input[100], output[100];
    cin >> input;

    subsets(input, output, 0, 0);

    return 0;
}