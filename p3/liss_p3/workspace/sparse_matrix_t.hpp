#pragma once 
#include <cstdio>
#include <iostream>
#include <cmath>

#include "template_matrix_t.hpp"
#include "vector_pair_t.hpp"
#include "vector_t.hpp"

using namespace std;

typedef matrix_t <double> matrix_double_t;
typedef vector_t<double>     count;

enum Config {COL_CONF, ROW_CONF};

class sparse_matrix_t{
private: 
    int     m_;
    int     n_;
    vector_pair_vp_t M_;
    int     conf_; 
    
public:

    sparse_matrix_t(const matrix_double_t& M, double eps, Config conf):
    m_(M.get_m()),
    n_(M.get_n()),
    M_(),
    conf_(conf)
    {
        
             if (conf==COL_CONF){
                this->m_ = M.get_n();
                this->n_ = M.get_m();
             } else {
                this->m_ = M.get_m();
                this->n_ = M.get_n();
             }
          unsigned int contador_elementos_primer_nivel = 0;
          int contador[this->m_];
          for (unsigned int i = 1; i <= this->m_; i++) {
                int contador_elementos = 0;
                for (unsigned int j = 1; j <= this->n_; j++) {
                  if(fabs(get_matrix_data(M,i,j,conf)) > eps){
                    contador_elementos++;
                  }
                }
                contador[i-1] = contador_elementos;
                if(contador_elementos>0){
                  contador_elementos_primer_nivel++;
                }
          }
          //Redimensionamos el vector base
          M_.resize(contador_elementos_primer_nivel);
          unsigned int base = 0;
          for (unsigned int i = 1; i <= this->m_; i++) {
            if(contador[i-1]!=0){
              M_.get_set_v(base).get_inx() = i;
              M_.get_set_v(base).get_val().resize(contador[i-1]);
              /*
              std::cout << "Base: " << base << std::endl;
              std::cout << "\nINDICE : " << M_.get_set_v(base).get_inx() << std::endl;
              std::cout << "Tamanio minivector: " << M_.get_set_v(base).get_val().get_sz() << std::endl;
              */
            }
            unsigned int inner_base = 0;
            for (unsigned int j = 1; j <= this->n_; j++) {
              if(fabs(get_matrix_data(M,i,j,conf)) > eps){
                M_.get_set_v(base).get_val().get_set_v(inner_base).get_inx() = j;
                M_.get_set_v(base).get_val().get_set_v(inner_base).get_val() = get_matrix_data(M,i,j,conf);
                //std::cout << "(" << j << "," << get_matrix_data(matrix,i,j,conf) << ")" << std::endl;
                inner_base++;
              }
            }
            if(contador[i-1]!=0){
              base++;
            }
          }
    }
    
     void  maximo(void){
      
      //cout << "hola";
      count count_;
      count_.resize(M_.get_sz());
      int i_vector = 0;
      double maximo = 0.0;
      for(int i= 1; i <= M_.get_sz(); i++){
         int tam = M_.get_set_v(i - 1).get_val().get_sz();
         for(int j= 1; j <= tam; j++){
           if ( M_.get_set_v(i -1).get_val().get_set_v(j -1).get_val() > maximo){
             maximo = M_.get_set_v(i - 1).get_val().get_set_v(j - 1).get_val();
            // cout << "bucle j";
             //cout <<  maximo;
           }
        
         }
        count_.get_set_v(i_vector) = maximo;
       i_vector++;
     }
     //cout << " aqui empezara el vector d maximos";
     for (int i= 0; i < count_.get_sz();i++){
       
       cout << count_.get_v(i) << " " ;
     }
     cout << endl;
    }
     
    double get_matrix_data(const matrix_double_t &v, int i, int j, Config conf){
      if (conf==COL_CONF){
        return v.get(j,i);
      }
      return v.get(i,j);
    }
    
    ~sparse_matrix_t()
    {}
    
    
    ostream& write(ostream& os) const{
        
        M_.write(os);
        return os;
        
    }
    void producto(const matrix_double_t &m, sparse_matrix_t &r){
     /* r.M_.resize(M_.get_sz());
      for (int base = 0; base < M_.get_sz(); base++) { // condensada
        double producto = 0.0;
        r.M_.get_set_v(base).get_inx() = M_.get_set_v(base).get_inx();
        r.M_.get_set_v(base).get_val().resize(m.get_n());
        std::cout << "INNER SZ: " << r.M_.get_set_v(base).get_val().get_sz() << std::endl;
        for(int reiteraciones = 0; reiteraciones < m.get_n(); reiteraciones++){
          for (int col = 0; col < M_.get_set_v(base).get_val().get_sz(); col++) { // condensada
            std::cout << M_.get_set_v(base).get_val().get_set_v(col).get_val() << " * " << (m.get(M_.get_set_v(base).get_inx(),M_.get_set_v(base).get_val().get_set_v(col).get_inx())) << "+" << std::endl;
            producto += M_.get_set_v(base).get_val().get_set_v(col).get_val() * (m.get(M_.get_set_v(base).get_inx(),M_.get_set_v(base).get_val().get_set_v(col).get_inx()));
          }
          r.M_.get_set_v(base).get_val().get_set_v(reiteraciones).get_inx()=reiteraciones;
          r.M_.get_set_v(base).get_val().get_set_v(reiteraciones).get_val()=producto;
          std::cout << std::endl;
        }
        std::cout << "producto = " << producto << std::endl;
      }
    }*/
    }
};