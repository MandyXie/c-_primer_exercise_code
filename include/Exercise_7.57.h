#ifndef Exercise_7_57_h
#define Exercise_7_57_h

class Account
{
public:
   void calculate() {amount += amount * interestRate;}
   static double rate() {return intereRate;}
   static void rate(double newRate) {interestRate = newRate;}
private:
   std::string owner; 
   double amount;
   static double interetRate;
   static constexpr double todayRate = 42.42;
   static double initRate() {return todayRate;}
};

double Account::interestRate = initRate();

#endif
