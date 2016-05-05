#pragma once

#include <cstdio>
#include <cassert>
#include <iostream>

enum       OPERATOR_ID      { PLUS, MINUS, MULTIPLY, DIVIDE, EXPONENT, LEFT_PARENTHESIS, RIGHT_PARENTHESIS}; //PLUS = 0, MINUS = 1, MULTIPLY = 3...
const int  precedence[]   = {    1,     1,        2,      2,        3,      0                    };
const char operator_sym[] = {  '+',   '-',      '*',     '/',       '^'                          };

using namespace std;

namespace AED {

	template <class T>

	class if2pf_t{

	private:
		T stack_;

        //En C tendríamos que declarar OPERATOR_ID
	public:
		if2pf_t() {}

		~if2pf_t() {
            if(!stack_.empty())
                cout << "La pila no se ha vacíado :(" << endl;
        }
	
		void compute(istream& is, ostream& os)
		{

			int operando;
			char operador;

			while(!is.eof()){

				is >> ws;
				int c = is.peek();

				if (c != EOF) {

					if (isdigit(c)){
						is >> operando;
                        os << operando << " ";
						/* … */
					}
					else {
						is >> operador;
                        operator_procedure(operador, os);
						/* … */
					}
				}
			}
            while(!stack_.empty()){
                os << operator_sym[stack_.top()] << " ";
                stack_.pop();
            }
            os << endl;

			/* … */
		}

		private: 

			const int get_operator_id(char operador) //asigna a cada carácter operador un identificador
			{
				int current_operator_id = -1;
                switch((short int)operador){
                    case 43:current_operator_id = PLUS; break; //'+'
                    case 45:current_operator_id = MINUS; break;//'-'
                    case 42:current_operator_id = MULTIPLY; break;//'*'
                    case 47:current_operator_id = DIVIDE; break;//'/'
                    case 40:current_operator_id = LEFT_PARENTHESIS; break;//'('
                    case 41:current_operator_id = RIGHT_PARENTHESIS; break;//')'
                    case '^':current_operator_id = EXPONENT; break; //'^'
                }
				return current_operator_id;
			}

			void operator_procedure(char operador, ostream& os){

				const int current_operator_id = get_operator_id(operador);
				if (current_operator_id == RIGHT_PARENTHESIS) //A
				{
                    //Si el operador es un cierre de paréntesis, sacar de la pila todos los operadores hasta encontrar un símbolo de apertura de paréntesis enviándolos a la salida.
                    while(!stack_.empty() && stack_.top() != LEFT_PARENTHESIS){
                        os << operator_sym[stack_.top()] << " ";
                        stack_.pop();
                    }
                    if(stack_.empty()){
                        cerr << "la pila está vacía"<< endl;
                        assert(!stack_.empty());
                    }
                    else
                        stack_.pop();
                    }
				}
				else if(stack_.empty() || 
                        current_operator_id == LEFT_PARENTHESIS ||
                        precedence[stack_.top()] <= precedence[current_operator_id] ){ //B

//              la pila está vacía, o
//              el token es un símbolo de apertura de paréntesis, o
//              la precedencia del operador situado en el top de la pila es igual o inferior a la precedencia del operador representado por el token leído,
                    stack_.push(current_operator_id);

					/* … */
				}else{ //C
//              Si no se cumple ninguna de estas tres condiciones anteriores sacar todos los operadores de la pila, añadiéndolos a la salida, hasta que la pila se encuentre vacía o se encuentre un operador de precedencia estrictamente menor, y luego introducir el operador actual en la pila.
                    while(!stack_.empty() ||
                         (precedence[stack_.top()] < precedence[current_operator_id])){
                        if(stack_.top() != LEFT_PARENTHESIS)
                            os << operator_sym[stack_.top()] << " ";

                        stack_.pop();
                    }
                }
            }
       };
}
