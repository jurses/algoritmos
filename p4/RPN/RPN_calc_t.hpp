#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>


using namespace std;

namespace AED {

	template <class T>
	class RPN_calc_t{
	private:
		T stack_;
        double result;
       double aux1, aux2; 

	public:
		RPN_calc_t() {}

		~RPN_calc_t() {}
        const double compute(istream& is){

        //string token;
        int operando;
        char operador;

        while(!is.eof()){

            is >> ws;
            int c = is.peek();

            if (!cin.eof()) {

                if (isdigit(c)){
                    is >> operando;
                    stack_.push(operando);
                }
                else {
                    is >> operador;
                    operate(operador);
                    /* ... */
                    //pasar a operate() el operador
                }
            }
        }

        result = stack_.top();
        stack_.pop();

        //top
        //result=pop

                /* ... */

        return result;
        }

    private:
        void operate(char operador){
            short int ascii_aux = operador;
            aux1 = stack_.top();
            stack_.pop();
            aux2 = stack_.top();
            switch(operador){
                case 43:stack_.push(aux1 + aux2); break; //'+'
                case 45:stack_.push(aux1 - aux2); break;//'-'
                case 42:stack_.push(aux1 * aux2); break;//'*'
                case 47:stack_.push(aux1 / aux2); break;//'/'
                default : cout << "No conozco el operador:" << ascii_aux << ": " << operador << endl;
            }
        }
    };
}
