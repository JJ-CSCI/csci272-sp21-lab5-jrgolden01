//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
#include <iostream>
using namespace std;

class Real{
  public:
  double RealNum;
  Real(double a=0){
    RealNum = a;
  }

  Real operator*(double b){
    Real a3;
    a3.RealNum = RealNum + b;
    return a3;
  }

  double GetReal(){
    return RealNum;
 }
};

class Complex:public Real{
  public:
  double imag;

  Complex(double r=0, double i= 0){
  RealNum=r;
  imag=i; 
}

Complex operator* (double b){
  Complex c3;
  c3.RealNum = RealNum +b;
  c3.imag = imag +b;
  return c3;
}
double GetImaginary(){
  return imag;
}
};

class Surreal:public Complex{
  public:
  double surrealNum;

  Surreal(double r=0, double i= 0, double s=0){
  RealNum=r;

  imag=i; 

  surrealNum=s;
}

Surreal operator* (double b){
  Surreal d3;
  d3.RealNum = RealNum +b;
  d3.imag = imag +b;
  d3.surrealNum = surrealNum +b;
  return d3;
}
double GetSurreal(){
  return surrealNum;
}
};


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
