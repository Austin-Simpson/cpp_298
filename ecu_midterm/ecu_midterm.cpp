#include <iostream>

class ElectronicControlUnit
{
public:
    ElectronicControlUnit();
    ~ElectronicControlUnit();
    void handleCommand(char cCommand);
    void printDisplay();

private:
    bool m_buttonA;
    bool m_buttonB;
    bool m_buttonE;
};

ElectronicControlUnit::ElectronicControlUnit() : m_buttonA(false), m_buttonB(false), m_buttonE(false)
{
    std::cout << "ElectronicControlUnit Constructor called" << std::endl;
}

ElectronicControlUnit::~ElectronicControlUnit()
{
    std::cout << "ElectronicControlUnit Destructor called" << std::endl;
}

void ElectronicControlUnit::printDisplay()
{
    std::cout << "        (A)       " << std::endl;
    std::cout << "   (F)  (G)  (B)   " << std::endl;
    std::cout << "   (E)       (C)   " << std::endl;
    std::cout << "        (D)       " << std::endl;
}
void ElectronicControlUnit::handleCommand(char cCommand)
{
    switch (cCommand)
    {
    case 'A':
    case 'a':
        m_buttonA = !m_buttonA;
        if (m_buttonA)
        {
            std::cout << "Hydraulic Jacks activated" << std::endl;
            if(m_buttonB)
            {
                m_buttonB = false;
                std::cout << "Belt Tires deactivated" << std::endl;
            }

        }
        else
        {
            std::cout << "Hydraulic Jacks deactivated" << std::endl;
        }
        break;
    case 'B':
    case 'b':
        m_buttonB = !m_buttonB;
        if (m_buttonB)
        {
            std::cout << "Belt Tires activated" << std::endl;
        }
        else
        {
            std::cout << "Belt Tires deactivated" << std::endl;
        }

        break;
    case 'E':
    case 'e':
        m_buttonE = !m_buttonE;
        if(m_buttonE)
        {
            std::cout << "Infrared Illumination activated" << std::endl;
        }
        else
        {
            std::cout << "Infrared Illumination deactivated" << std::endl;
        }
        break;
    case 'X':
    case 'x':
        exit(0);
    default:
        std::cout << "Invalid command" << std::endl;
        break;
    }
}

int main()
{
    ElectronicControlUnit ecu;
    char cCommand;
    std::cout << "Press X to turn off ignition or enter a steering wheel button (A, B, or E)" << std::endl;
    while (true)
    {
        ecu.printDisplay();
        std::cin >> cCommand;
        ecu.handleCommand(cCommand);
    }
    return 0;
}