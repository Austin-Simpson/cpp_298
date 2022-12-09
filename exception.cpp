#include <iostream>
#include <stdexcept>
#include <string>

unsigned long sigma(unsigned long n);


int main()
{
    int sum = sigma(5);
    std::cout << "sigma(5) = " << sum << std::endl;
    sum = sigma(0);
    std::cout << "sigma(0) = " << sum << std::endl;

    return 0;
}

unsigned long sigma(unsigned long n)
{
    unsigned long sum = 0;

    try
    {
        if(n < 1)
        {
            throw std::runtime_error("n < 1");
        }

        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }

        if(sum != (n*(n+1)/2))
        {
            std::string strMessage = "Postcondition sum == (n(n+1))/2 violated: sum: " + std::to_string(sum) + "; n(n+1)/2: " + std::to_string((n*(n+1))/2) + " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";;

            throw std::runtime_error(strMessage); 
        }
    }
    catch(const std::exception& ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
        std::cout << "Cannot compute sum; returning 0" << std::endl;
        sum = 0;
    }
    
    return sum;
}