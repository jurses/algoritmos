#pragma once

#include "pair_t.hpp"
#include "vector_pair_t.hpp"
#include "vector_t.hpp"

#include <cmath>

#include <iostream>
#include <iomanip>

using namespace std;

class sparse_vector_t{
private:
	vector_pair_t v_;    // Vector de pares
	int           sz_;   // Tamaño del vector original

public:
	sparse_vector_t(void):
		v_(),
		sz_(0) {}

	sparse_vector_t(const vector_t& v, double eps):
		v_(),
		sz_(v.get_sz()) {
			
		// Cuenta el número de elementos no nulos
		int nz = 0;

		for(int i = 0; i < v.get_sz(); i++)
			if ( is_not_zero(v.get_v(i), eps) )
				nz ++;

		v_.resize(nz);

		nz = 0;

		for(int i = 0; i < v.get_sz(); i++)
			if ( is_not_zero(v.get_v(i), eps) )
			{
				v_.get_set_v(nz).set(i, v.get_v(i));
				nz ++;
			}		

	}

	double scal_prod(const vector_t& v)const{
		double aux = 0.0;

		for(int i=0;i < v_.get_sz(); ++i)
			 aux += v_.get_v(i).get_val() * v.get_v(v_.get_v(i).get_inx());

		return aux;
	}

    double scal_prod(const sparse_vector_t& v)const{
        double aux = 0.0;
        
        for(int i=0; i < v_.get_sz(); ++i)
            for(int j=0; j < v.v_.get_sz(); ++j)
                if (v_.get_v(i).get_inx() == v.v_.get_v(j).get_inx())
                    aux += v_.get_v(i).get_val() * v.v_.get_v(j).get_val();

        return aux;
    }

	~sparse_vector_t(void){}
	
	istream& read(istream& is){

		is >> sz_;

		v_.read(is);

		return is;

	}

	ostream& write_dense(ostream& os) const{
		int aux = 0;

        for(int i=0; i < sz_; i++){
                       
                if(aux < v_.get_sz() && i == v_.get_v(aux).get_inx()){
                    os << v_.get_v(aux).get_val() << " ";
                    aux++;
                }else
                    os << 0.0 << " ";
        }
		
		return os;
	}

	ostream& write(ostream& os) const{
	
		os << "[ " << setw(7) << sz_ << " ";
		v_.write(os);
		os << " ]";

		return os;
	}

private:
	bool is_not_zero(double val, double eps) { return fabs(val) > eps;}

};

