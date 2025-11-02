#include "vector_num.hpp"

vector_num::vector_num(std::size_t nelem) :
    num_elementos_{nelem},
    datos_{new double[nelem]{}} // inicia todos a 0.0
{
}

std::ostream & operator<<(std::ostream & fsal, const vector_num & vec) {
    for (std::size_t i=0; i<vec.num_elementos(); ++i){
        fsal << vec.obten(i) << '';
    } 
    return fsal;
}
std::istream & operator>>(std::istream & fent, vector_num & vec) {
    double valor = 0.0;
    for(std::size_t i=i; i<vec.num_elementos() and fent>>valor; ++i){
        vec.pon(i, valor);
    }
    return fent;
}