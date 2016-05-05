#include "RPN_calc_t.hpp"

namespace AED{
    template <class T>
//    namespace RPN_calc_t{
        const int RPN_calc_t::compute(istream& is){

        //string token;
        int operando;
        char operador;

        while(!is.eof()){

            is >> ws;
            int c = is.peek();

            if (!cin.eof()) {

                if (isdigit(c)){
                    is >> operando;
                    /* ... */
                    //stack.push(numero);
                    stack_.push(operando);
                }
                else {
                    is >> operador;
                    RPN_calc_t::operate(operador);
                    /* ... */
                    //pasar a operate() el operador
                }
            }
        }

        result = stack_.top()
        stack_.pop()

        //top
        //result=pop

                /* ... */

        return result;
        }

        void RPN_calc_t::operate(char operador){
            aux1 = stack_.top();
            stack_.pop();
            aux2 = stack_.top();
            switch(operador){
                case '+':stack_.push(aux1 + aux2);
                case '-':stack_.push(aux1 - aux2);
                case '*':stack_.push(aux1 * aux2);
                case '/':stack_.push(aux1 / aux2);
                default : cout << "No conozco el operador" << endl;
            }
        }
//    }
}
