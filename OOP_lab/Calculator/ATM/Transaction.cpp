#include <iostream>
using namespace std;

class Transaction {
   private:
    int accntNo;

   public:
    int getAccntNo() {
        return accntNo;
    }

    void execute() {}
};

class BalanceInquiry : public Transaction {
   public:
    void execute() {}
};

class Withdraw : public Transaction {
   private:
    double ammount;

   public:
    void execute() {}
};

class Deposit : public Transaction {
   private:
    double ammount;

   public:
    void execute() {}
};