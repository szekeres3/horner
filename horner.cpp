#include <iostream>
#include <array>
#include <cmath>
int Horner(int* e, int k, int n, int* eh){
    int eredmeny = e[n];
    int i;
    for (i = n-1; i > 0; i--)
    {
        eh[n-i-1] = eredmeny;
        eredmeny = k * eredmeny + e[i];
    }
    eh[n-i-1] = eredmeny;
    return k * eredmeny + e[0]; 
}
void kiir(int kszi, int h, int* x, int n){
std::cout << "f(" << kszi << ") = " << h << " és" << std::endl 
    << "f(x) = (x-" << kszi << ")(";
    for (int i = 0; i<n; i++)
    {
        if (x[i] < 0)
        {
            std::cout << " - ";
        }
        std::cout << abs(x[i]);
        std::cout << "x^" << n-i-1;
        if (i == n-1)
        {
            std::cout << ")";
        }
        if (x[i+1] > -1)
        {
            std::cout << " + ";
        }
    }
    std::cout << h << std::endl;
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
    int * x = new int[n];
    int kszi;
    std::cout << "kszí megadása: ";
    std::cin >> kszi;
    for (size_t i = 0; i <= n; i++)
    {
        std::cout << "Kérem a számot (x^" << i << "): ";
        std::cin >> egyutthatok[i];
    }
    int h = Horner(egyutthatok, kszi, n, x);
    kiir(kszi, h, x, n);
}
