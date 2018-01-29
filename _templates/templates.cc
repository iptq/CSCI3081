#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

class ArenaEntity {
   public:
    ArenaEntity(int r = 10) : radius(r) {}
    void Print() { std::cout << "Entity with radius " << radius << std::endl; }

   private:
    int radius;
};

// A polymorphic swap function for any type of object
template <typename T>
void MySwap(T& x, T& y) {
    T temp;
    temp = x;
    x = y;
    y = temp;
}

// A polymorphic class holding an [x,y] position of any type
template <class T>
class Position {
   public:
    Position(T x = 0, T y = 0) : x_(x), y_(y) {}
    friend std::ostream& operator<<(std::ostream& os, const Position& p) {
        return os << "[" << p.x_ << ", " << p.y_ << "]";
    }
    // >>>> ADD SETTERS AND GETTERS
    T get_x() { return x_; }
    void set_x(T x) { x_ = x; }
    T get_y() { return y_; }
    void set_y(T y) { y_ = y; }
    // >>>>> OVERLOAD OPERATORS + and - binary operators as member functions.
    Position operator+(const Position& other) {
        return Position(x_ + other.x_, y_ + other.y_);
    }
    Position operator-(const Position& other) {
        return Position(x_ - other.x_, y_ - other.y_);
    }

   private:
    T x_;
    T y_;
};

// >>>>> CREATE AN ARRAY TEMPLATE that takes type and number of elements
// template<class T, int N> ...
// >>>>> OVERLOAD operator []. Do a check on index to be in range
// >>>>> METHODS to push and pop
template <class T, int N>
class
    AnArrayClassThatsWorseThanVectorButApparentlyBetterThanBuiltinArraysButNotReally {
   public:
    T operator[](const int index) {
        if (index > N) {
            int* x = (int*)NULL;
            printf("%d\n", *x);
            // cause a segfault cuz why not
        }
        return array[index];
    }
    void push(T a) {
        if (array.size() >= N) return;
        array.push_back(a);
    }
    T pop() {
        auto last = *(array.rbegin());
        array.erase(array.rbegin());
        return last;
    }

   private:
    std::vector<T> array;  // use a vector internally because it's the best!
};

int main(void) {
    // -----------------------------------------------------------------
    // Demonstration of the use of the template Vector and its iterator
    std::vector<class ArenaEntity*> entities_;
    entities_.push_back(new ArenaEntity(20));
    entities_.push_back(new ArenaEntity(25));

    for (std::vector<class ArenaEntity*>::iterator ent = entities_.begin();
         ent != entities_.end(); ++ent) {
        (*ent)->Print();
    }

    // This is the same as above, except with the convenience of auto typing
    std::cout << std::endl;
    for (auto ent : entities_) {
        ent->Print();
    }

    // -----------------------------------------------------------------
    // Demonstration of the use of template for function overloading
    int intA, intB;
    float floatA, floatB;
    char charA, charB;
    intA = 10;
    intB = 20;
    floatA = 2.5;
    floatB = 10.5;
    charA = 'a';
    charB = 'b';

    std::cout << std::endl;
    std::cout << "int A,B: [" << intA << ", " << intB << "]" << std::endl;
    std::cout << "float A,B: [" << floatA << ", " << floatB << "]" << std::endl;
    std::cout << "char A,B: [" << charA << ", " << charB << "]" << std::endl;
    MySwap(intA, intB);
    MySwap(floatA, floatB);
    MySwap(charA, charB);
    std::cout << std::endl;
    std::cout << "int A,B: [" << intA << ", " << intB << "]" << std::endl;
    std::cout << "float A,B: [" << floatA << ", " << floatB << "]" << std::endl;
    std::cout << "char A,B: [" << charA << ", " << charB << "]" << std::endl;

    // -----------------------------------------------------------------
    // Demonstration of the use of template for class definition
    Position<int> intPos(10, 10);
    Position<float> floatPos(1.5, 1.5);
    Position<char> charPos('A', 'B');
    std::cout << std::endl;
    std::cout << intPos << std::endl;
    std::cout << floatPos << std::endl;
    std::cout << charPos << std::endl;

    Position<int> intPos2(20, 20);
    intPos2.set_x(30);
    std::cout << intPos + intPos2 << std::endl;

    // -----------------------------------------------------------------
    // Demonstration of the use of template for class ARRAY
    AnArrayClassThatsWorseThanVectorButApparentlyBetterThanBuiltinArraysButNotReally<
        int, 1>
        a;
    a.push(5);
    a.push(6);
    printf("value: %d\n", a[2]);
}
