#include "vector_fijo.hpp"

// Default constructor
vector_fijo::vector_fijo() : datos_{} {}

// Size constructor
vector_fijo::vector_fijo(std::size_t n) : datos_(n, 0.0) {} // initialize all to 0

// Initializer list constructor
vector_fijo::vector_fijo(std::initializer_list<double> lista) : datos_(lista) {}

// Copy constructor
vector_fijo::vector_fijo(const vector_fijo& other) : datos_(other.datos_) {}

// Move constructor
vector_fijo::vector_fijo(vector_fijo&& other) noexcept : datos_(std::move(other.datos_)) {}

// Copy assignment
vector_fijo& vector_fijo::operator=(const vector_fijo& other) {
    if (this != &other) {
        datos_ = other.datos_;
    }
    return *this;
}

// Move assignment
vector_fijo& vector_fijo::operator=(vector_fijo&& other) noexcept {
    datos_ = std::move(other.datos_);
    return *this;
}

// Stream operators
std::ostream& operator<<(std::ostream& os, const vector_fijo& v) {
    os << "vector_fijo({";
    for (std::size_t i = 0; i < v.num_elementos(); ++i) {
        os << v.obten(i);
        if (i + 1 < v.num_elementos()) os << ", ";
    }
    os << "})";
    return os;
}

std::istream& operator>>(std::istream& is, vector_fijo& v) {
    for (std::size_t i = 0; i < v.num_elementos() && is; ++i) {
        double val;
        if (is >> val) v.pon(i, val);
    }
    return is;
}
