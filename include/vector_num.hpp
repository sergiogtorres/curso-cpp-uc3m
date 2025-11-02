

#ifndef VECTORNUM_HPP
#define VECTORNUM_HPP
#include <iostream>
#include <gsl/gsl>

class vector_num {
    public:
        vector_num(std::size_t nelem);

        std::size_t num_elementos() const { return num_elementos_;}

        double obten(std::size_t i) const {Expects(i<num_elementos_); return datos_[i]; }
        void pon(std::size_t i, double x) {Expects(i<num_elementos_); datos_[i] = x; }
    
    private:
        std::size_t num_elementos_;
        double * datos_;
};

std::osttream & operator <<(std::ostream & fsal, const vector_num & vec);
std::istream & operator >>(std::istream & fent, vector_num & vec);

#endif
