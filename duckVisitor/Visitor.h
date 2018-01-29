#ifndef DUCKS_EXERCISES_VISITOR_H_
#define DUCKS_EXERCISES_VISITOR_H_

class Duck;
class RubberDuck;
class Mallard;
class DecoyDuck;
class SeaDuck;

class Visitor {
   public:
    Visitor();
    virtual void visit(Duck* d);
    virtual void visit(RubberDuck* r);
    virtual void visit(Mallard* m);
    virtual void visit(DecoyDuck* dd);
    virtual void visit(SeaDuck* s);
};

class RealDuckReport : public Visitor {
   public:
    void visit(RubberDuck* r);
    void visit(Mallard* m);
    void visit(Duck* d);
    void visit(DecoyDuck* d);
    void visit(SeaDuck* s);
};

class FakeDuckReport : public Visitor {
   public:
    void visit(RubberDuck* r);
    void visit(Mallard* m);
    void visit(Duck* d);
    void visit(DecoyDuck* d);
    void visit(SeaDuck* s);
};

#endif
