#ifndef PIN_H
#define PIN_H

#include "Component.h"

class Pin : public Component
{
public:
    Pin(std::string theLabel);

    virtual bool getOutput() const;

    void setValue(bool newVal);

    virtual void prettyPrint(std::string padding) const;

    virtual void linearPrint() const;

private:
    bool value;
    std::string label;
};

#endif // PIN_H
