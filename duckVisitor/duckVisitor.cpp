#include <stdlib.h>
#include <iostream>
#include "Duck.h"
#include "Visitor.h"

using namespace std;

// helper defined at bottom of file
void duck_introduction(Duck* duck);

int main() {
    // EXAMPLE of polymorphism and the Strategy Pattern
    Duck* ducks[5];
    ducks[0] = new Duck();
    ducks[0]->setName("Jane");

    ducks[1] = new Mallard();
    ducks[1]->setName("Maloy");

    ducks[2] = new RubberDuck();
    ducks[2]->setName("Lemon");

    ducks[3] = new DecoyDuck();
    ducks[3]->setName("xXx::KINGP1N::xXx");

    ducks[4] = new SeaDuck();
    ducks[4]->setName("doievenfly?lol");

    for (int i = 0; i < 5; i++) {
        duck_introduction(ducks[i]);
    }

    // EXAMPLE of the Visitor Pattern

    // This is a visitor of ducks.
    // It needs information, but only from certain kinds of ducks.
    RealDuckReport* rd = new RealDuckReport;

    // Tell each duck to accept a visit from RealDuckReport
    cout << "----- REPORT of Real Ducks -----" << endl;
    for (int i = 0; i < 5; i++) {
        ducks[i]->accept(rd);
    }
    cout << endl;

    // This is a visitor of ducks.
    // It needs information, but only from certain kinds of ducks.
    FakeDuckReport* fd = new FakeDuckReport;
    // Tell each duck to accept a visit from FakeDuckReport
    cout << "----- REPORT of Fake Ducks -----" << endl;
    for (int i = 0; i < 5; i++) {
        ducks[i]->accept(fd);
    }
    cout << endl;
}

void duck_introduction(Duck* duck) {
    duck->display();
    duck->fly();
    duck->quack();
    cout << endl;
}
