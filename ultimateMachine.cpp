#include <iostream>

class UltimateMachine {
    public:
        UltimateMachine() : m_bState(false){
            std::cout << "Ultimate Machine constructor (ctor) caled" << std::endl;
        }

        void displayState() 
        {
            switch(m_bState) {
                case true:
                    std::cout << "Ultimate Machine is ON" << std::endl;
                    break;
                case false:
                    std::cout << "Ultimate Machine is OFF" << std::endl;
                    break;
            }
        }

        void turnOn()
        {
            m_bState = true;
            displayState();
            if( true == m_bState ){
                m_bState = false;
            }
            displayState();
        }

        ~UltimateMachine(){
            std::cout << "Ultimate Machine destructor (dtor) caled" << std::endl;
        };

    private:
        bool m_bState; //true (on), false (off)
};

int main()
{
    std::cout << "The Ultimate Machine Simulation\n";

    UltimateMachine ultmach;
    ultmach.displayState();
    ultmach.turnOn();
}