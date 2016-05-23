#include <iostream>
#include "tree_t.hpp"

using namespace std;
using namespace AED;


int main(void)
{
	tree_t<double> tree;

	int input_sz;
	double input_val;

	cin >> input_sz;

	for(int i = 0; i < input_sz; i++){

		cin >> input_val; 
		tree.insert(input_val);
	}

	cout << "Árbol ordenado: " << endl;
	tree.write(cout);
	cout << endl;

	cout << "Nivel máximo:" << endl;
	cout << tree.depth() << endl;

    cout << "Total pares:" << endl;
    cout << tree.count_even() << endl;

	return 0;
}
