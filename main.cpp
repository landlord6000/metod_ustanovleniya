#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>

#define N 100
#define pi 3.141592653589793
#define m1 10000
#define m2 100000
#define h pi/N
#define tau 0.01

template<typename T>
void swap(T *r, T *s)
{
    T *pSwap = r;
    r = s;
    s = pSwap;
    return;
}

template<typename T>
T f(T x)
{
    return 9*sin(9*x);
}

template<typename T>
T initial_conditions(T x)
{
    return x*(pi - x);
}

template<typename T>
void init_vector(std::vector<T>& vec)
{
    T x = 0.;
    for(int i = 0; i < N+1; ++i)
    {
        vec[i] = initial_conditions(x);
        x+=h;
    }
}

template<typename T>
void uravnoveshivanie_launch(std::vector<T>& vec)
{
    std::cout << "h = " << h << " tau = " << tau; 
    const T tauDhh = tau/(h*h);
    std::vector<T> vec2(N+1);
    for(int m = 0; m < m1; ++m){
        T x = 0.;
        for(int i = 0; i < N+1; ++i){
            vec2[i] = vec[i] + tauDhh*(vec[i-1] - 2*vec[i] + vec[i+1] + f(x));
            x+=h;
        }
        std::cout << "\n\n"; for(double i : vec2) std::cout << i << " ";
        if (m > 10)break;
        swap(vec, vec2);
        std::cout << "\n\n"; for(double i : vec2) std::cout << i << " ";
    }

    
}



int main()
{
    std::vector <double> x(N+1);
    init_vector<double>(x);
    for(double i : x) std::cout << i << " ";
    uravnoveshivanie_launch<double>(x);
    std::cout << "\n";
    for(double i : x) std::cout << i << " ";
    return 0;
}