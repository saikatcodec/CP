#include <iostream>
using namespace std;

class Screen {
   public:
    void displayMessage(string messages) {
        cout << messages << endl;
    }

    void displayMessage(int messages) {
        cout << messages << endl;
    }

    void displayAmmount(double amnt) {
        cout << amnt << endl;
    }
};

class Keypad {
   public:
    int getInput() {
        int n;
        cin >> n;

        return n;
    }
};