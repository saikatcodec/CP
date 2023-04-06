#include <iostream>
using namespace std;

class CashDispenser {
   private:
    static const int INITAL_COUNT = 500;
    int count;

   public:
    CashDispenser() {
        count = INITAL_COUNT;
    }
    void dispenseCash(int ammt) {
        int bill = ammt / 20;
        count -= bill;
    }
    bool isSuffCashAvail(int amnt) {
        int bill = amnt / 20;

        if (count >= bill) {
            return true;
        } else {
            return false;
        }
    }
};

class DepositSlot {
   public:
    bool isEnvelopeRecieved() {
        return true;
    }
};