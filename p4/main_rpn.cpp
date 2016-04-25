#include <cstdio>
#include <iostream>


#include "stack_v_t.hpp"
#include "stack_l_t.hpp"

#include <stack>

#include "RPN/RPN_calc_t.hpp"
//#include "PAP/PAP.cpp"

using namespace std;
using namespace AED;

typedef stack_v_t<int> stack_vector;
typedef stack_l_t<int> stack_lista  ;  
typedef stack<int>     stack_stl  ;

bool is_pal(){
    string cadena_ = "CTAGCCTTCCGATC";
    stack_l_t<char> stack_stl;
    bool salida;
    int i = 0;
        if(cadena_.size()%2 == 0)
            for(i=0; i < cadena_.size()/2; i++)
                stack_stl.push(cadena_[i]);
        else
            cout << "No es válido." << endl;

        for(i; i < cadena_.size(); i++){
            if(stack_stl.top() == cadena_[i]){
                    salida = true;
                    stack_stl.pop();
            }else
                return false;
        }
    return salida;
}

int main(void)
{

    if(is_pal())
        cout << "Es palíndromo" << endl;

	RPN_calc_t<stack_vector> calculadora_vector;
	const int result_vector = calculadora_vector.compute(cin);
	cout << "Calculadora vector: " << result_vector << endl;

	cin.clear();
	cin.seekg(0, ios::beg);

	RPN_calc_t<stack_lista> calculadora_lista;
	const int result_lista = calculadora_lista.compute(cin);
	cout << "Calculadora lista:  " << result_lista << endl;

	cin.clear();
	cin.seekg(0, ios::beg);

	RPN_calc_t<stack_stl> calculadora_stl;
	const int result_stl = calculadora_stl.compute(cin);
	cout << "Calculadora stl:    " << result_stl << endl;
    
    //PAP_t<stack> comprueba_ADN(cadena);
	return 0;
}
