#include "vector_t.hpp"
#include "sparse_vector_t.hpp"

#include <iostream>
#include <fstream>
using namespace std;

#define V_SZ 10000
#define EPS  1E-3

int main(int argc, char* argv[])
{

	if (argc != 4)
	{
		cerr << "Usage: " << argv[0] << " vector1.txt vector2.txt" << endl;
		return -1;
	}

	ifstream vector1;
	ifstream vector2;
    ifstream vector3;

	vector1.open(argv[1]);
	vector2.open(argv[2]); 
    vector3.open(argv[3]);

	vector_t A;
	sparse_vector_t B;
    sparse_vector_t C;

	A.read(vector1);
	B.read(vector2);
    C.read(vector3);

	A.write(cout);
        cout << endl;
	B.write(cout);
    	cout << endl;
    C.write(cout);
        cout << endl;

    B.write_dense(cout);
        cout << endl;
    C.write_dense(cout);
        cout << endl;

    cout << B.scal_prod(A) << endl;
    cout << A.scal_prod(A) << endl;

    cout << C.scal_prod(B) << endl;

	
	vector1.close();
	vector2.close();
    vector3.close();
}
