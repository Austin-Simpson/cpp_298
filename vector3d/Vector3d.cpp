#include "Vector3d.h"


Vector3D::Vector3D()
{
    this->m_vector.at(0) = 0.0;
    this->m_vector.at(1) = 0.0;
    this->m_vector.at(2) = 0.0;
    return;
}

Vector3D::Vector3D(double dx, double dy, double dz)
{
    this->m_vector.at(0) = dx;
    this->m_vector.at(1) = dy;
    this->m_vector.at(2) = dz;
    return;
}

Vector3D::~Vector3D() {}

void Vector3D::display()
{
    std::cout << this->m_vector.at(0) << " x, " << this->m_vector.at(1) << " y, " << this->m_vector.at(2) << " z" << std::endl;
    return;
}

double Vector3D::dot(Vector3D vec3d)
{
    double dDotProduct = 0;
    for (unsigned int i = 0; i < this->m_vector.size(); i++)
    {
        dDotProduct += this->m_vector.at(i) * vec3d.m_vector.at(i);
    }
    return dDotProduct;
}


