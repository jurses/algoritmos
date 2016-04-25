#pragma once

#include <cstdio>
#include <cassert>
#include <iostream>

enum       OPERATOR_ID      { PLUS, MINUS, MULTIPLY, DIVIDE, LEFT_PARENTHESIS, RIGHT_PARENTHESIS };
const int  precedence[]   = {    1,     1,        2,      2,                0                    };
const char operator_sym[] = {  '+',   '-',      '*',     '/'                                     };

using namespace std;

namespace AED {

	template <class T>
	class if2pf_t{
	private:
		T stack_;

	public:
		if2pf_t() {}

		~if2pf_t() {}
	
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
						/* … */
					}
					else {
						is >> operador;
						/* … */
					}
				}
			}

			/* … */
		}

		private: 

			const int get_operator_id(char operador)
			{
				int current_operator_id = -1;

				/* … */				

				return current_operator_id;
			}

			void operator_procedure(char operador, ostream& os){
				
				const int current_operator_id = get_operator_id(operador);

				if (current_operator_id == RIGHT_PARENTHESIS)
				{
					/* … */
				}
				else{
					/* … */
				}

			}

       };

}

