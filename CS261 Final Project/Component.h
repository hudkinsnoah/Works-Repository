#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component{
public:
    virtual bool getOutput() const = 0;

    virtual void Prettyprint(std::string padding) const = 0;

    virtual void Linearprint() const = 0;

};


#endif // COMPONENT_H
