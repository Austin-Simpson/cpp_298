#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <vector>
#include <iostream>

class Vector3D
{
    public:
        Vector3D();
        Vector3D(double dx, double dy, double dz);
        ~Vector3D();
        double dot(Vector3D vec3d);
        void display();

    private:
        std::vector<double> m_vector = {0, 0, 0};
};


#endif