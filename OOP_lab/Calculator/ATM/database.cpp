#include <iostream>
using namespace std;

class BankDatabase {
   public:
    bool authenticateUser() {}
    double getAvailbal() {}
    double getTotalbal() {}
    void credit() {}
    void debit() {}
};

class Account {
   private:
    int accountNum;
    int pin;
    double availBal;
    double totalBal;

   public:
    Account(int accountNum, int pin, double availBal, double totalBal) {
        this->accountNum = accountNum;
        this->pin = pin;
        this->availBal = availBal;
        this->totalBal = totalBal;
    }
    bool validatePin() {}
    double getAvailbal() {}
    double getTotalbal() {}
    void credit() {}
    void debit() {}
};