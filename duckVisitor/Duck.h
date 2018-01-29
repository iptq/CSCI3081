#ifndef DUCKS_EXERCISES_DUCK_H_
#define DUCKS_EXERCISES_DUCK_H_

#include <stdlib.h>
#include <iostream>
#include "Fly.h"
#include "Quack.h"
#include "Visitor.h"

using namespace std;

//----------------------------------------------
//  THE DUCKS

class Duck {
   protected:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;
    string name;

   public:
    Duck();

    virtual void accept(Visitor* v);

    virtual void display();
    virtual void fly();
    virtual void quack();

    virtual double getSpeed();
    virtual double getDB();

    virtual void setName(string inName);
    virtual string getName();
};

class Mallard : public Duck {
   public:
    Mallard();
    void accept(Visitor* v);
    void display();
};

class RubberDuck : public Duck {
   public:
    RubberDuck();
    void accept(Visitor* v);
    void display();
};

class DecoyDuck : public Duck {
   public:
    DecoyDuck();
    void accept(Visitor* v);
    void display();
};

class SeaDuck : public Duck {
   public:
    SeaDuck();
    void accept(Visitor* v);
    void display();
};

#endif
