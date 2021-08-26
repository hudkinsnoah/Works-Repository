#ifndef NOTGATE_H
#define NOTGATE_H

#include <memory>
#include "Component.h"

class NotGate : public Component
{
public:
    NotGate();

    virtual bool getOutput() const;

    void setInput(Component* in);

    virtual void prettyPrint(std::string padding) const;

    virtual void linearPrint() const;

private:
    Component* input;
};

#endif // NOTGATE_H
