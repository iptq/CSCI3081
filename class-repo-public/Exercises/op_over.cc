#include <cstdio>
#include <iostream>
#include <cstring>

class VectorDouble;

// Vector in an x,y plane
class Vector {
public:
  Vector(int x=0, int y=0) : x_(x), y_(y) {}
  //*** SPECIAL CONSTRUCTOR ****//
  // Vector( VectorDouble v) {}
  int get_x() { return x_; }
  void set_x(int x) { x_ = x; }
  int get_y() { return y_; }
  void set_y(int y) { y_ = y; }

  friend class VectorDouble;

  // Overload = (binary)
  const Vector operator=(const Vector& right) {
    x_ = right.x_;
    y_ = right.y_;
    return *this;
  }

  // Overload + (binary)
  const Vector operator+(const Vector& right) {
    return Vector(x_ + right.x_, y_ + right.y_);
  }

  // Overload - (binary)

  // Overload * of Vector*Vector = x*x + y*y

  // Overload * of Vector*int = Vector(int*x, int*y)

  // Overland - (unary)

  // Overload <<
  friend std::ostream& operator<<(std::ostream& os, const Vector& v);

private:
  int x_;
  int y_;
};

std::ostream& operator<<(std::ostream& os, const Vector& v) {
  os << "[" << v.x_ << ", " << v.y_ << "]";
  return os;
}

class VectorDouble {
public:
  VectorDouble( double x=0, double y=0) : x_(x), y_(y) {}
  //*** SPECIAL CONSTRUCTOR ****//
  VectorDouble( Vector v) { x_ = v.get_x(); y_ = v.get_y(); }
  double get_x() { return x_; }
  void set_x(double x) { x_ = x; }
  double get_y() { return y_; }
  void set_y(double y) { y_ = y; }

  // Overload = (binary)
  const VectorDouble operator=(const VectorDouble& right) {
    x_ = right.x_;
    y_ = right.y_;
    return *this;
  }

  // Overload + (binary)
  const VectorDouble operator+(const VectorDouble& right) {
    x_ = x_ + right.x_;
    y_ = y_ + right.y_;
    return *this;
  }

  // Overload <<
  friend std::ostream& operator<<(std::ostream& os, const VectorDouble& v);

  const VectorDouble operator+(const Vector& right) {
    return VectorDouble( x_ + right.x_, y_ + right.y_);
  }

private:
  double x_;
  double y_;
};

std::ostream& operator<<(std::ostream& os, const VectorDouble& v) {
  os << "[" << v.x_ << ", " << v.y_ << "]";
  return os;
}

int main(void) {
  Vector v1(2,3);
  Vector v2(5,8);
  Vector v3;
  VectorDouble d1(1.0,1.5);
  VectorDouble d2(6.3,2.9);

  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << d1 << std::endl;
  std::cout << d2 << std::endl;

  v1 = v2;
  std::cout << v1 << std::endl;

  v3 = v1+v2;
  std::cout << v3 << std::endl;

  VectorDouble mix = d1+v3;
  std::cout << mix << std::endl;
}
