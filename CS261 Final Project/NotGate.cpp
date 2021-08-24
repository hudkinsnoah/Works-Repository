#include <iostream>
using namespace std;
#include "NotGate.h"

NotGate::NotGate()
{
   input = nullptr;
}

bool NotGate::getOutput() const
{
    if(input->getOutput() == 0)
        return 1;
    else
        return 0;
}

void NotGate::setInput(Component* in)
{
    input = in;
}

 void NotGate::prettyPrint(std::string padding) const
 {
     cout << padding << "NOT" << endl;
     input->prettyPrint(padding + "--");

 }

 void NotGate::linearPrint() const
 {
   cout << "~(";
   input->linearPrint();
   cout << ")";
 }
