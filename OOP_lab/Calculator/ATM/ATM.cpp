#include <iostream>

#include "CashDispenser.cpp"
#include "database.cpp"
#include "input_output.cpp"
using namespace std;

class ATM {
   private:
    bool userAuthenticate = false;
    int crntAcntNo;
    Screen screen;
    Keypad keypad;
    CashDispenser cashDis;
    BankDatabase bankDB;
    DepositSlot dp;

    static const int BALANCE_ENQUIRY = 1;
    static const int WITHDRAWAL = 2;
    static const int DEPOSIT = 3;
    static const int EXIT = 4;

   public:
    ATM() {
        userAuthenticate = false;
        crntAcntNo = 0;
        screen = Screen();
        keypad = Keypad();
        cashDis = CashDispenser();
        bankDB = BankDatabase();
        dp = DepositSlot();
    }

    void userAuthenticated() {
        screen.displayMessage("\nEnter Your Account Number: ");
        int acntNo = keypad.getInput();
        screen.displayMessage("\nEnter your PIN: ");
        int pin = keypad.getInput();

        
    }

    void performTask() {}

    void run() {
        while (true) {
            while (!userAuthenticate) {
                screen.displayMessage("\nWelcome");
                userAuthenticated();
            }

            performTask();
            userAuthenticate = false;
            crntAcntNo = 0;
            screen.displayMessage("\nThank You");
        }
    }
};
