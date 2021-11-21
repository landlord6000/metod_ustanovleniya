#include "header.h"
#include "constants.h"

template<typename T>
void swap(T *r, T *s){
    T *pSwap = r;
    r = s;
    s = pSwap;
    return;
}

template<typename T>
T f(T x){
    return 9*sin(9*x);
}

template<typename T>
T initial_conditions(T x){
    return x*(pi - x);
}

template<typename T>
void init_vector(std::vector<T>& vec){
    T x = 0.;
    for(int i = 0; i < N+1; ++i){
        vec[i] = initial_conditions(x);
        x+=h;
    }
}


template<typename T>
void file_output_csv(std::vector<T>& vec, std::string file_name){
    std::ofstream fout;
    fout.open(file_name);
    for(int i = 0; i < vec.size(); ++i){
        fout << h*i << ", ";
        fout << vec[i] << "\n";
    }
    fout.close(); 
}

template<typename T>
void uravnoveshivanie_launch(std::vector<T>& vec){
    const T tauDhh = tau/(h*h);
    std::vector<T> vec2(N+1);
    for(int m = 0; m < m1; ++m){
        T x = 0.;
        for(int i = 0; i < N+1; ++i){
            vec2[i] = vec[i] + tauDhh*(vec[i-1] - 2*vec[i] + vec[i+1] + f(x));
            x+=h;
        }
        swap(vec, vec2);
    }
    file_output_csv(vec, "m1.csv");

    for(int m = m1; m < m2; ++m){
        T x = 0.;
        for(int i = 0; i < N+1; ++i){
            vec2[i] = vec[i] + tauDhh*(vec[i-1] - 2*vec[i] + vec[i+1] + f(x));
            x+=h;
        }
        swap(vec, vec2);
    }
    file_output_csv(vec, "m2.csv");
}


int main()
{
    std::vector <double> x(N+1);
    init_vector<double>(x);
    for(double i : x) std::cout << i << " ";
    uravnoveshivanie_launch<double>(x);
    std::cout << "\n\n";
    for(double i : x) std::cout << i << " ";
    return 0;
}