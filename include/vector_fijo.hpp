#ifndef VECTOR_FIJO_HPP
#define VECTOR_FIJO_HPP

#include <iostream>
#include <vector>
#include <initializer_list>

class vector_fijo {
public:
    // Constructors
    vector_fijo(); // default
    explicit vector_fijo(std::size_t n); // size constructor
    vector_fijo(std::initializer_list<double> lista); // initializer list

    // Copy constructor
    vector_fijo(const vector_fijo& other);
    // Move constructor
    vector_fijo(vector_fijo&& other) noexcept;

    // Copy assignment
    vector_fijo& operator=(const vector_fijo& other);
    // Move assignment
    vector_fijo& operator=(vector_fijo&& other) noexcept;

    // Accessors
    std::size_t num_elementos() const { return datos_.size(); }
    double obten(std::size_t i) const { return datos_.at(i); }
    void pon(std::size_t i, double x) { datos_.at(i) = x; }

private:
    std::vector<double> datos_;
};

// Stream operators
std::ostream& operator<<(std::ostream& os, const vector_fijo& v);
std::istream& operator>>(std::istream& is, vector_fijo& v);

#endif
