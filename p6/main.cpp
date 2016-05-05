#include <cstdio>
#include <iostream>

#include "stack/stack_l_t.hpp"
#include "if2pf/if2pf_t.hpp"
#include "RPN/RPN_calc_t.hpp"

using namespace std;
using namespace AED;

typedef stack_l_t<int> stack_lista;

int main(void){
    ostream& os;

    if2pf_t<stack_lista> if2pf;
    RPN_calc_t<stack_lista> calculadora_vector;

    if2pf.compute(cin, os);
	cin.clear();
	cin.seekg(0, ios::beg);
    
    const int result_vector = calculadora_vector(if2pf.compute(cin, os));

//	cout << "Calculadora vector: " << result_vector << endl;

	cin.clear();
	cin.seekg(0, ios::beg);

    return 0;
};
