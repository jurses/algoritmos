#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;

namespace AED{
    template <class T>
    class PAP_t{
        private:
            T stack_;
            string topal_;
            short int size_;
            bool salida;
            int i;

        public:
            PAP_t(string cadena):
            topal_(cadena){
                if(topal_.size()%2 == 0)
                    for(i=0; i < topal_.size()/2; i++)
                        stack_.push(topal_[i]);
                else
                    cout << "No es válido." << endl;

            }
            ~PAP_t(){}

            const bool is_pal(){
                for(i; i < topal_.size(); i++){
                    if(stack_.top() == topal_[i]){
                        salida = true;
                        stack_.pop();
                    else
                        return false;
                    }
                }
                return salida;
            }
    };
}
