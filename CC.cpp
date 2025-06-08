#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {

   void CC::aloCopy(const char* name) {
      if (name != nullptr) {
         cardholderName = new char[strlen(name) + 1];
         strcpy(cardholderName, name);
      }
   }

   void CC::deallocate() {
      delete[] cardholderName;
      cardholderName = nullptr;
   }

   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
      if (name == nullptr || strlen(name) <= 2) {
         return false;
      } else if (cardNo < 4000000000000000ULL || cardNo > 4099999999999999ULL) {
         return false;
      } else if (cvv < 100 || cvv > 999) {
         return false;
      } else if (expMon < 1 || expMon > 12) {
         return false;
      } else if (expYear < 24 || expYear > 32) {
         return false;
      } else {
         return true;
      }
   }

   void CC::set() {
      deallocate();
      cardholderName = nullptr;
      CVV = 0;
      expiryMonth = 0;
      expiryYear = 0;
      number = 0;
   }

     CC::CC() {
      set();
   }

   CC::CC(const char* name, unsigned long long number, short cvv, short expMon, short expYear) {
   set(name, number, cvv, expMon, expYear);
   }

    CC::~CC() {
      deallocate();
   }

   

   void CC::set(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) {
      set();
      if (validate(name, cardNo, cvv, expMon, expYear) == true) {
         aloCopy(name);
         number = cardNo;
         CVV = cvv;
         expiryMonth = expMon;
         expiryYear = expYear;
      }
   }

   bool CC::isEmpty() const {
      return cardholderName == nullptr;
   }

   void CC::display() const {
      if (!isEmpty()) {
         display(cardholderName, number, expiryYear, expiryMonth, CVV);
      } else {
         cout << "Invalid Credit Card Record" << endl;
      }
   }

   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }

   



}