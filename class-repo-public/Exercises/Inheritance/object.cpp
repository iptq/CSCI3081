#include <iostream>

using std::cout;
using std::endl;

class ObjectClass {
private:
  int privateVar;
protected:
  int protectedVar;
public:
  ObjectClass() :
    privateVar(10), protectedVar(15) {}
  ObjectClass(int a, int b) :
    privateVar(a), protectedVar(b) {}
  void print() {
    cout << "in objectClass. ";
    cout << "priv, prot =  " << privateVar << ' '<< protectedVar << endl;
  }
  void setPrivate(int a) { privateVar = a;}
  void setProtected(int a) { protectedVar = a;}
};

class ComposedClass {
private:
  ObjectClass object;
  //int privateVar;
public:
  void print() {
    //cout << "in composedClass. ";
    //cout << "privateVar " << privateVar << endl;
    //cout << "protectedVar " << protectedVar << endl;
    //cout << "object privateVar " << object.privateVar << endl;
    //cout << "object protectedVar " << object.protectedVar << endl;
    object.print();
  }
protected:
  //int protectedVar;
};

class DerivedClass : public ObjectClass {
private:
  /*
  int privateVar;
  int protectedVar;
  */
public:
  // DerivedClass() {}
  //DerivedClass() : ObjectClass(1,2) {}
  /*{
    privateVar = 20;
    protectedVar = 25;
  }*/
  void print() {
    //cout << "in derivedClass. ";
    //cout << "privateVar " << privateVar << endl;
    //cout << "protectedVar " << protectedVar << endl;
    //cout << "object privateVar " << ObjectClass::privateVar << endl;
    //cout << "object protectedVar " << ObjectClass::protectedVar << endl;
    ObjectClass::print();
  }
};

int main() {
  ObjectClass baseObject_default;
  ObjectClass baseObject_2_3(2,3);
  ComposedClass hasAobject_default;
  DerivedClass isAobject_default;
  // DerivedClass isAobject_4_5(4,5);

  cout << "Base default: ";
  baseObject_default.print();
  cout << "Base 2,3 : ";
  baseObject_2_3.print();
  cout << "Composed default : ";
  hasAobject_default.print();
  cout << "Derived default : ";
  isAobject_default.print();
  cout << "Derived 4,5 : ";
  // isAobject_4_5.print();

  return 1;
}
