#include "array_fijo.hpp"
#include <gsl/gsl>

// constructor por defecto
secuencia_fija::secuencia_fija() :
    num_elementos_{0},
    datos_{nullptr}{}

// constructor por parámetro
secuencia_fija::secuencia_fija(std::size_t nelem) :
    num_elementos_{nelem}, datos_{new double[nelem]{}} // inicia todos a 0.0
{}
// constructor por lista de inicialización
secuencia_fija::secuencia_fija(std::initializer_list<double> lista) :
    num_elementos_{lista.size()}, datos_{new double[lista.size()]} {
        std::copy(lista.begin(), lista.end(), datos_);
    }

// constructor de copia
secuencia_fija::secuencia_fija(const secuencia_fija & s) 
    : num_elementos_{s.num_elementos_}, datos_ {new double[s.num_elementos_]} {
        std::copy(s.datos_, s.datos_ + s.num_elementos_, datos_);
}

// constructor de movimiento
secuencia_fija::secuencia_fija(secuencia_fija && s) noexcept
    : num_elementos_{s.num_elementos_}, datos_{s.datos_} {
        s.num_elementos_ = 0;
        s.datos_ = nullptr;
}

//constructor de asignación de copia
secuencia_fija & secuencia_fija::operator=(const secuencia_fija & s) {
    if (this == &s) {return *this;} // autoasignación
    if (s.num_elementos_ == num_elementos_) { // mismo tamaño
        std::copy_n(s.datos_, s.num_elementos_, datos_);
        return *this;
    }
    gsl::owner<double *> nuevos_datos = new double[s.num_elementos_];
    std::copy_n(s.datos_, s.num_elementos_, nuevos_datos);
    delete[] datos_;
    datos_ = nuevos_datos;
    num_elementos_ = s.num_elementos_;
    return * this;
}

// constructor de asignación de movimiento
secuencia_fija & secuencia_fija::operator=(secuencia_fija && s) noexcept {
    std::swap(num_elementos_, s.num_elementos_);
    std::swap(datos_, s.datos_);
    return *this;
}

// destructor
secuencia_fija::~secuencia_fija() {
    delete[] datos_;
}

std::ostream & operator<<(std::ostream & fsal, const secuencia_fija & vec) {
    fsal << "secuencia_fija({";
    for (std::size_t i=0; i<vec.num_elementos(); ++i){
        fsal << vec.obten(i) << ", ";
    } 
    fsal << "})";
    return fsal;
}
std::istream & operator>>(std::istream & fent, secuencia_fija & vec) {
    double valor = 0.0;
    for(std::size_t i=0; i<vec.num_elementos() and fent>>valor; ++i){
        vec.pon(i, valor);
    }
    return fent;
}