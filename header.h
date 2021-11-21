#ifndef METOD_USTANOVLENIYA
#define METOD_USTANOVLENIYA

#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <fstream>

template<typename T>
void swap(T *r, T *s);

template<typename T>
T f(T x);

template<typename T>
T initial_conditions(T x);

template<typename T>
void init_vector(std::vector<T>& vec);

template<typename T>
void uravnoveshivanie_launch(std::vector<T>& vec);

template<typename T>
void file_output_csv(std::vector<T>& vec, std::string file_name);

#endif