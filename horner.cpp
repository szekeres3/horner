#include <iostream>
#include <array>
#include <cmath>
int Horner(int* e, int k, int n){
    int eredmeny = e[n];
    for (size_t i = n-1; i > 0; i--)
    {
        eredmeny = k * eredmeny + e[i];
        //std::cout << eredmeny << std::endl;
        //std::cin.get();
    }
    return k * eredmeny + e[0]; 
}
int main(){
    int n;
    std::cout << "Polinom fokszáma: ";
    std::cin >> n;
    if (n < 1)
    {
        std::cout << "n nem lehet 0.";
        std::exit(1);
    }
    int egyutthatok[n+1];
    int kszi;
    std::cout << "kszí megadása" << std::endl;
    std::cin >> kszi;
    for (size_t i = 0; i <= n; i+=1)
    {
        std::cout << "Kérem a számot: " << i << std::endl;
        std::cin >> egyutthatok[i];
    }
    int h = Horner(egyutthatok, kszi, n);
    std::cout << "f(" << kszi << ") = " << h << " és" << std::endl 
    << "f(x) = (x-" << kszi << ")(";
    int index = 0;
    for (int elem: egyutthatok)
    {
        if (elem < 0)
        {
            std::cout << " - ";
        }
        std::cout << abs(elem);
        if (index > 0)
        {
            std::cout << "x^" << index;
        }
        if (index == n)
        {
            std::cout << ")";
        }
        if (egyutthatok[index+1] > -1)
        {
            std::cout << " + ";
        }
        index++;
    }
    std::cout << h << std::endl;
}