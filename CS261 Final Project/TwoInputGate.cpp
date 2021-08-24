#include <iostream>
using namespace std;
#include "TwoInputGate.h"

TwoInputGate::TwoInputGate(LogicOperation op)
{
    input1 = nullptr;
    input2 = nullptr;
    getType = op;
}

bool TwoInputGate::getOutput() const
{
    if(getType == AND)
        return input1->getOutput() && input2->getOutput();
    else if(getType == OR)
        return input1->getOutput() || input2->getOutput();
    else
        return input1->getOutput() ^ input2->getOutput();
}

void TwoInputGate::setInput1(Component* in1)
{
    input1 = in1;
}

void TwoInputGate::setInput2(Component* in2)
{
    input2 = in2;
}

void TwoInputGate::prettyPrint(std::string padding) const
{
    cout << padding << LOGIC_LABELS[getType] << endl;
    input1->Prettyprint(padding + "--");
    cout << endl;
    input2->Prettyprint(padding + "--");

}

void TwoInputGate::linearPrint() const
{
    if(getType == OR)
    {
        cout << "(";
        input1->Linearprint();
        cout << " || ";
        input2->Linearprint();
        cout << ")";
    }
    else if(getType == AND)
    {
        cout << "(";
        input1->Linearprint();
        cout << " && ";
        input2->Linearprint();
        cout << ")";
    }
    else
    {
        cout << "(";
        input1->Linearprint();
        cout << " ^ ";
        input2->Linearprint();
        cout << ")";
    }
}
