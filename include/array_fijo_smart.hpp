// Requerimientos de array_fijo
// - Double
// - Memoria dinámica
// - no se puede usar ningún contenedor de la STL
// - Se pueden usar punteros elegantes o primitivos
// - Creación: número de elementos como argumento del constructor, pero no se puedew modificar posteriormente
// - Creación también a partir de lista de inicialización
// - Ofrece operaciones de copia y movimiento

#ifndef ARRAY_FIJO_SMART_HPP
#define ARRAY_FIJO_SMART_HPP
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <cstddef>
#include <gsl/gsl>

class secuencia_fija_smart {
    public:
        secuencia_fija_smart();// constructor por defecto
        explicit secuencia_fija_smart(std::size_t nelem); // constructor con número de elementos
        secuencia_fija_smart(std::initializer_list<double> lista); // constructor con lista de inicialización
        secuencia_fija_smart(const secuencia_fija_smart & s); // constructor de copia
        secuencia_fija_smart(secuencia_fija_smart && s) noexcept; // constructor de movimiento
        secuencia_fija_smart & operator=(const secuencia_fija_smart & s); // operador de asignación por copia
        secuencia_fija_smart & operator=(secuencia_fija_smart && s) noexcept; // operador de asignación por movimiento
        ~secuencia_fija_smart(); //destructor

        std::size_t num_elementos() const { return num_elementos_;}

        double obten(std::size_t i) const {Expects(i<num_elementos_); return datos_[i]; }
        void pon(std::size_t i, double x) {Expects(i<num_elementos_); datos_[i] = x; }
    
    private:
        std::size_t num_elementos_;
        std::unique_ptr<double []> datos_;
};

std::ostream & operator <<(std::ostream & fsal, const secuencia_fija_smart & vec);
std::istream & operator >>(std::istream & fent, secuencia_fija_smart & vec);

#endif
