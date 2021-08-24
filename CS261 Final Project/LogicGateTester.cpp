//Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"
#include "doctest.h"

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//Include your .h files
#include "Pin.h"
#include "NotGate.h"
#include "TwoInputGate.h"

#include <iostream>
#include <vector>

using namespace std;


TEST_CASE( "Components/Pin" ) {
    cout << "Pin Only Test..." << endl;

    Pin a("A");
    a.setValue(false);

    REQUIRE(a.getOutput() == false);

    a.setValue(true);
    REQUIRE(a.getOutput() == true);
}

TEST_CASE("NotGate") {
    cout << "NotGate Test..." << endl;

    Pin c("C");
    c.setValue(false);
    NotGate n1;
    n1.setInput(&c);

    REQUIRE(n1.getOutput() == true);

    c.setValue(true);
    REQUIRE(n1.getOutput() == false);
}

TEST_CASE("TwoInputGate/AND") {
    cout << "AND Only Test..." << endl;

    Pin a("A");
    a.setValue(false);
    Pin b("B");
    b.setValue(false);

    TwoInputGate t1(AND);
    t1.setInput1(&a);
    t1.setInput2(&b);
    REQUIRE(t1.getOutput() == false);

    a.setValue(true);
    REQUIRE(t1.getOutput() == false);

    a.setValue(false);
    b.setValue(true);
    REQUIRE(t1.getOutput() == false);

    a.setValue(true);
    REQUIRE(t1.getOutput() == true);

}

TEST_CASE("TwoInputGate/OR") {
    cout << "OR Only Test..." << endl;

    Pin a("A");
    a.setValue(false);
    Pin b("B");
    b.setValue(false);

    TwoInputGate t1(OR);
    t1.setInput1(&a);
    t1.setInput2(&b);
    REQUIRE(t1.getOutput() == false);

    a.setValue(true);
    REQUIRE(t1.getOutput() == true);

    a.setValue(false);
    b.setValue(true);
    REQUIRE(t1.getOutput() == true);

    a.setValue(true);
    REQUIRE(t1.getOutput() == true);

}

TEST_CASE("TwoInputGate/XOR") {
    cout << "XOR Only Test..." << endl;

    Pin a("A");
    a.setValue(false);
    Pin b("B");
    b.setValue(false);

    TwoInputGate t1(XOR);
    t1.setInput1(&a);
    t1.setInput2(&b);
    REQUIRE(t1.getOutput() == false);

    a.setValue(true);
    REQUIRE(t1.getOutput() == true);

    a.setValue(false);
    b.setValue(true);
    REQUIRE(t1.getOutput() == true);

    a.setValue(true);
    REQUIRE(t1.getOutput() == false);

}

TEST_CASE("Test for special circuit/part4") {
    cout << "Part 4 only Test..." << endl;

    Pin a("A");
    a.setValue(false);
    Pin b("B");
    b.setValue(false);
    Pin c("c");
    c.setValue(false);

    TwoInputGate t1(XOR);
    t1.setInput1(&a);
    t1.setInput2(&b);

    NotGate n1;
    n1.setInput(&c);

    TwoInputGate t2(AND);
    t2.setInput1(&t1);
    t2.setInput2(&n1);

    REQUIRE(t2.getOutput() == false);

    c.setValue(true);
    REQUIRE(t2.getOutput() == false);

    b.setValue(true);
    c.setValue(false);
    REQUIRE(t2.getOutput() == true);

    a.setValue(true);
    b.setValue(false);
    REQUIRE(t2.getOutput() == true);

    a.setValue(false);
    b.setValue(true);
    c.setValue(true);
    REQUIRE(t2.getOutput() == false);

    a.setValue(true);
    b.setValue(false);
    REQUIRE(t2.getOutput() == false);

    b.setValue(true);
    c.setValue(false);
    REQUIRE(t2.getOutput() == false);

    c.setValue(true);
    REQUIRE(t2.getOutput() == false);
}

TEST_CASE("Pretty Print") {
    cout << "Pretty Print Only Test..." << endl;

    Pin a("A");
    a.setValue(true);
    Pin b("B");
    b.setValue(true);
    Pin c("C");
    c.setValue(false);

    NotGate n1;
    n1.setInput(&c);

    TwoInputGate t1(XOR);
    t1.setInput1(&a);
    t1.setInput2(&b);
    TwoInputGate t2(OR);
    t2.setInput1(&b);
    t2.setInput2(&n1);
    TwoInputGate t3(AND);
    t3.setInput1(&t1);
    t3.setInput2(&t2);

    t3.prettyPrint("");
    cout << endl;

}

TEST_CASE("Linear Print") {
    cout << "Linear Print Only Test..." << endl;

    Pin a("A");
    a.setValue(true);
    Pin b("B");
    b.setValue(true);
    Pin c("C");
    c.setValue(false);

    NotGate n1;
    n1.setInput(&c);

    TwoInputGate t1(XOR);
    t1.setInput1(&a);
    t1.setInput2(&b);
    TwoInputGate t2(OR);
    t2.setInput1(&b);
    t2.setInput2(&n1);
    TwoInputGate t3(AND);
    t3.setInput1(&t1);
    t3.setInput2(&t2);

    t3.linearPrint();
    cout << endl;
}
