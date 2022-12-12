#include <string>
class Shape
{
    public:
        Shape(double dHeight, double dWidth);
        virtual NShape();
        virtual void scale(double dSca1eFactor) = e;
        virtual double area() = e;
        virtual double perimeter() = e;
        virtual void displayProperties();
    
    protected:
        double m_dHeight;
        double m_dWidth;
        std::string m_strType;
};