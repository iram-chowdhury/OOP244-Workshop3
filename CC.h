#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
      char* cardholderName{};
      short CVV{};
      short expiryMonth{};
      short expiryYear{};
      unsigned long long number{};

      void aloCopy(const char* cardholderName);
      void deallocate();
      void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
      bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const;
      void prnNumber(unsigned long long CCnum) const;

      public:
         CC(); 
         void set();
         bool isEmpty() const;
         CC(const char* name, unsigned long long number, short cvv, short expMon = 12, short expYear = 26);
         void set(const char* name, unsigned long long number, short cvv, short expiryMonth, short expiryYear);
         void display() const;
         ~CC();
   };

}
#endif 


