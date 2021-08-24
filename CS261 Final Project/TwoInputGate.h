#ifndef TWOINPUTGATE_H
#define TWOINPUTGATE_H

#include <memory>
#include "Component.h"

//Supported operations
enum LogicOperation {OR, AND, XOR};

//Lookup table for names of operations:
//  LOGIC_LABELS[OR] --> "OR"
//  LOGIC_LABELS[AND] --> "AND"...
const std::string LOGIC_LABELS[] = {"OR", "AND", "XOR"};

class TwoInputGate : public Component
{
public:
    TwoInputGate(LogicOperation op);

    virtual bool getOutput() const;

    void setInput1(Component* in1);

    void setInput2(Component* in2);

    virtual void prettyPrint(std::string padding) const;

    virtual void linearPrint() const;

private:
    Component* input1;
    Component* input2;
    LogicOperation getType;
};

#endif // TWOINPUTGATE_H
