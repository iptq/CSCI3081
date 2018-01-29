#include "Visitor.h"
#include <stdlib.h>
#include <iostream>
#include "Duck.h"

using namespace std;

Visitor::Visitor() {}

void Visitor::visit(Duck *d) {}
void Visitor::visit(RubberDuck *r) {}
void Visitor::visit(Mallard *m) {}
void Visitor::visit(DecoyDuck *d) {}
void Visitor::visit(SeaDuck *s) {}

void RealDuckReport::visit(RubberDuck *r) {
    // RubberDucks aren't real ducks. do not include
}

void RealDuckReport::visit(Mallard *m) {
    cout << "Mallard : " << m->getName() << " : " << m->getSpeed() << " MPH"
         << endl;
}

void RealDuckReport::visit(Duck *d) {
    // Ducks are generic ducks. do not include
}

void RealDuckReport::visit(DecoyDuck *d) {}

void RealDuckReport::visit(SeaDuck *s) {
    cout << "SeaDuck : " << s->getName() << " : " << s->getSpeed() << " MPH"
         << endl;
}

void FakeDuckReport::visit(RubberDuck *r) {
    cout << "Rubberduck : " << r->getName() << " : " << r->getDB() << " DB"
         << endl;
}

void FakeDuckReport::visit(Mallard *m) {
    // Mallards aren't fake. Do not include.
}

void FakeDuckReport::visit(Duck *d) {
    // Ducks are generic ducks. do not include
}

void FakeDuckReport::visit(DecoyDuck *d) {
    cout << "DecoyDuck : " << d->getName() << " : " << d->getDB() << " DB"
         << endl;
}

void FakeDuckReport::visit(SeaDuck *s) {}
