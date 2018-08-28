#include <iostream>

#include "project/vector.hpp"

Vector::Vector() {
  x = y = z = 0.0;
}

Vector::Vector(double a, double b, double c) {
  x = a;
  y = b;
  z = c;
}

Vector Vector::operator+(const Vector &other) const {
  return Vector(x + other.x, y + other.y, z + other.z);
}


Vector Vector::operator*(const Vector &other) const {
  return Vector((y * other.z - z * other.y), (z * other.x - x * other.z),
  (x * other.y - y * other.x));
}


void Vector::print() {
  std::cout << "(" << x << "," << y << "," << z << ")" << std::endl;
}
