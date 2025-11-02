// Requerimientos de array_fijo
// - Double
// - Memoria dinámica
// - no se puede usar ningún contenedor de la STL
// - Se pueden usar punteros elegantes o primitivos
// - Creación: número de elementos como argumento del constructor, pero no se puedew modificar posteriormente
// - Creación también a partir de lista de inicialización
// - Ofrece operaciones de copia y movimiento

#ifndef ARRAY_FIJO_HPP
#define ARRAY_FIJO_HPP
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <cstddef>
#include <gsl/gsl>

class secuencia_fija {
    public:
        secuencia_fija();// constructor por defecto
        explicit secuencia_fija(std::size_t nelem); // constructor con número de elementos
        secuencia_fija(std::initializer_list<double> lista); // constructor con lista de inicialización
        secuencia_fija(const secuencia_fija & s); // constructor de copia
        secuencia_fija(secuencia_fija && s) noexcept; // constructor de movimiento
        secuencia_fija & operator=(const secuencia_fija & s); // operador de asignación por copia
        secuencia_fija & operator=(secuencia_fija && s) noexcept; // operador de asignación por movimiento
        ~secuencia_fija(); //destructor

        std::size_t num_elementos() const { return num_elementos_;}

        double obten(std::size_t i) const {Expects(i<num_elementos_); return datos_[i]; }
        void pon(std::size_t i, double x) {Expects(i<num_elementos_); datos_[i] = x; }
    
    private:
        std::size_t num_elementos_;
        double * datos_;
};

std::ostream & operator <<(std::ostream & fsal, const secuencia_fija & vec);
std::istream & operator >>(std::istream & fent, secuencia_fija & vec);

#endif
