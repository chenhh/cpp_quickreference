#include <iostream>
#include <gsl/gsl_sf_bessel.h>

int main (){
    double x = 5.0;
    double y = gsl_sf_bessel_J0 (x);
    std::cout<<"GSL SF Bessel:"<<y<<std::endl;
    return 0;
}