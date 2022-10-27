#include "Vector3d.h"
#include <cmath>
// #include <iostream>  included in Vector3d.h
// #include <vector>    included in Vector3d.h


int main()
{
    double const PI = 3.14159265;
    
    double Fx = 10 * std::cos(45 * PI/180.0);   // newtons
    double Fy = 10 * std::sin(45 * PI/180.0);   // newtons
    double Fz = 0;                              // newtons

    double Dx = 10.0; // meters
    double Dy = 0.0; // meters
    double Dz = 0.0; // meters

    Vector3D vec3dForce(Fx, Fy, Fz);
    Vector3D vec3dDisplacement(Dx, Dy, Dz);

    vec3dForce.display();
    vec3dDisplacement.display();

    double dWork = vec3dForce.dot(vec3dDisplacement); // Joules
    std::cout << "Work = " << dWork << std::endl;

    return 0;
}