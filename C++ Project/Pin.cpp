#include <iostream>
using namespace std;
#include "Pin.h"

 Pin::Pin(std::string theLabel)
 {
     label = theLabel;
     value = 0;
 }

 bool Pin::getOutput() const
 {
     return value;
 }

 void Pin::setValue(bool newVal)
 {
     value = newVal;
 }

void Pin::prettyPrint(std::string padding) const
{
   cout << padding << label << " : " << value;
}

void Pin::linearPrint() const
{
   cout << label;
}
