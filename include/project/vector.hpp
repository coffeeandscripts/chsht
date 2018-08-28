#ifndef PROJECT_VECTOR_
#define PROJECT_VECTOR_

class Vector {
  double x,y,z;
public:
  Vector();
  Vector(double,double,double);
  Vector operator+(const Vector &other) const;
  Vector operator*(const Vector &other) const;
  void print();
};

#endif
