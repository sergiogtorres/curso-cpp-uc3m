#include "array_fijo_smart.hpp"
#include <gsl/gsl>

// constructor por defecto
secuencia_fija_smart::secuencia_fija_smart() :
    num_elementos_{0},
    datos_{nullptr}{}

// constructor por parámetro
secuencia_fija_smart::secuencia_fija_smart(std::size_t nelem) :
    num_elementos_{nelem}, datos_{std::make_unique<double[]>(nelem)} // inicia todos a 0.0
{}
// constructor por lista de inicialización
secuencia_fija_smart::secuencia_fija_smart(std::initializer_list<double> lista) :
    num_elementos_{lista.size()}, datos_{std::make_unique<double []>(lista.size())} {
        std::copy(lista.begin(), lista.end(), datos_.get()); // con datos_.get() obtenemos el puntero primitivo
    }

// constructor de copia
secuencia_fija_smart::secuencia_fija_smart(const secuencia_fija_smart & s) 
    : num_elementos_{s.num_elementos_}, datos_ {std::make_unique<double []>(s.num_elementos_)} {
        std::copy_n(s.datos_.get(), s.num_elementos_, datos_.get());
}

// constructor de movimiento
secuencia_fija_smart::secuencia_fija_smart(secuencia_fija_smart && s) noexcept
    : num_elementos_{s.num_elementos_}, datos_{std::move(s.datos_)} {
        s.num_elementos_ = 0;
        s.datos_ = nullptr;
}

//constructor de asignación de copia
secuencia_fija_smart & secuencia_fija_smart::operator=(const secuencia_fija_smart & s) {
    if (this == &s) {return *this;} // autoasignación
    if (s.num_elementos_ == num_elementos_) { // mismo tamaño
        std::copy_n(s.datos_.get(), s.num_elementos_, datos_.get());
        return *this;
    }
    std::unique_ptr<double[]> nuevos_datos = std::make_unique<double []>(s.num_elementos_);
    std::copy_n(s.datos_.get(), s.num_elementos_, nuevos_datos.get());

    datos_ = std::move(nuevos_datos);  // take ownership
    num_elementos_ = s.num_elementos_;

    return * this;
}

// constructor de asignación de movimiento
secuencia_fija_smart & secuencia_fija_smart::operator=(secuencia_fija_smart && s) noexcept {
    num_elementos_ = s.num_elementos_;
    datos_ = std::move(s.datos_);
    s.num_elementos_ = 0;
    return *this;
}

secuencia_fija_smart::~secuencia_fija_smart() = default;

std::ostream & operator<<(std::ostream & fsal, const secuencia_fija_smart & vec) {
    fsal << "secuencia_fija_smart({";
    for (std::size_t i=0; i<vec.num_elementos(); ++i){
        fsal << vec.obten(i) << ", ";
    } 
    fsal << "})";
    return fsal;
}
std::istream & operator>>(std::istream & fent, secuencia_fija_smart & vec) {
    double valor = 0.0;
    for(std::size_t i=0; i<vec.num_elementos() and fent>>valor; ++i){
        vec.pon(i, valor);
    }
    return fent;
}