#include <iostream>
#include <string>
#include <fstream>

class CentralPolygonalNumbers
{
    public:
        CentralPolygonalNumbers();
        CentralPolygonalNumbers(int nMax);
        ~CentralPolygonalNumbers();
        void display();
        bool save(std::string strFilename);
    
    private:
        int m_nMax;
        int* mp_iNumbers;
};

CentralPolygonalNumbers::CentralPolygonalNumbers()
{
    mp_iNumbers = new int[1];
    m_nMax = 0;
}

CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax)
{
    mp_iNumbers = new int[nMax+1];
    m_nMax = nMax;
    for(int i = 0; i <= nMax; i++)
    {
        mp_iNumbers[i] = (i*i + i + 2)/2;
    }

}

CentralPolygonalNumbers::~CentralPolygonalNumbers()
{
    delete[] mp_iNumbers;
    std::cout << "~CentralPolygonalNumbers called" << std::endl;
}

void CentralPolygonalNumbers::display()
{
    for(int i = 0; i <= m_nMax; i++)
    {
        std::cout << "n: " << i << ", maximum number of pieces: " << mp_iNumbers[i] << "\n";
    }
}

bool CentralPolygonalNumbers::save(std::string strFilename)
{
    std::ofstream ofsnumbers;
    ofsnumbers.open(strFilename);
    if(ofsnumbers.is_open())
    {
        for(int i = 0; i <= m_nMax; i++)
        {
            ofsnumbers << "n: " << i << ", maximum number of pieces: " << mp_iNumbers[i] << "\n";
        }
        ofsnumbers.close();
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    CentralPolygonalNumbers cpn(10);
    cpn.display();
    cpn.save("CPN");
}