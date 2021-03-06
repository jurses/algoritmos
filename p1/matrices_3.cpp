#include "matrices_3.hpp"

#define MAX_MATRIX_ITEM 100

//========================================================================================
// Métodos privados.
//========================================================================================



vector_inx_t matrix_t::pos(matrix_inx_t i,matrix_inx_t j)
{
	if ((i<1)||(i>m_)||(j<1)||(j>n_)){
		std::cerr << "Error accediendo a matriz"<< std::endl;
		return 0;
        }

	return (i-1)*n_+j-1;


}




void matrix_t::crearMatriz(void) 
{
	M_= new matrix_item_t [m_*n_];	// Crea un vector de mxn elementos. 
   	
	if (M_==NULL)  		// Si ha fallado la reserva de memoria. 
		std::cerr << "Error creando matriz." << std::endl;
}		



void matrix_t::destruirMatriz(void)
{
	if (M_!=NULL){
		delete [] M_;		// Libera la memoria previamente reservada para la matriz.
		M_=NULL;		// Asigna NULL al puntero.
	}

	m_=0;
	n_=0;
}




void matrix_t::redimensiona(matrix_inx_t m,matrix_inx_t n)
{
	destruirMatriz();

	m_=m;
	n_=n;

	crearMatriz();
}




//========================================================================================
// Métodos públicos.
//========================================================================================

bool matrix_t::igual(matrix_item_t a, matrix_item_t b, double precision){
   if (fabs(a - b) < precision)
      return true;
   else
      return false;
}

bool matrix_t::mayor(matrix_item_t a, matrix_item_t b, double precision){
   if (a - b > precision)
      return true;
   else
      return false;
}

bool matrix_t::menor(matrix_item_t a, matrix_item_t b, double precision){
   if (a - b < (-1)*precision)
      return true;
   else
      return false;
}

bool matrix_t::zero(matrix_item_t a, double precision){
   if (fabs(a) < precision)
      return true;
   else
      return false;
}

void matrix_t::trasponer(){
   traspuesta_ = true;
}

void matrix_t::filtra(matrix_t& M, matrix_item_t it, double precision){
   M.redimensiona(m_,n_);
   for(matrix_inx_t i=1; i<=m_; i++)
      for(matrix_inx_t j=1; j<=n_; j++){
         if (igual(it, get_matrix_item(i,j), precision))
            M.set_matrix_item(i, j, get_matrix_item(i,j)); //puede que no haga falta
         else
            M.set_matrix_item(i, j, 0.0);
      }
}

int matrix_t::contar_entre(matrix_item_t a, matrix_item_t b, double precision){
   int aux = 0;
   for(matrix_inx_t i=1; i<=m_; i++)
      for(matrix_inx_t j=1; j<=n_; j++)
         if(menor(a, get_matrix_item(i, j), precision) && mayor(b, get_matrix_item(i, j), precision))
            aux++;

   return aux;
}

matrix_t::matrix_t(matrix_inx_t m,matrix_inx_t n):
M_(NULL),
m_(m),
n_(n),
traspuesta_(false)
{
	crearMatriz();
}	




matrix_t::matrix_t(void):
M_(NULL),
m_(0),
n_(0),
traspuesta_(false)
{}		



matrix_t::~matrix_t(void)
{
	destruirMatriz();
}



void  matrix_t::mostrarMatriz(void)
{

	char aux[80];

   if (!traspuesta_){
      for(int i=1;i<=m_;i++){
      
         std::cout << "|";	
         for(int j=1;j<=n_;j++){
            sprintf(aux," %10.6lf ",get_matrix_item(i,j));
            cout << aux;
         }
         std::cout << " |";
         cout << endl;
      }

      cout << endl;
   }else{
      for(int j=1;j<=n_;j++){
      
         std::cout << "|";	
         for(int i=1;i<=m_;i++){
            sprintf(aux," %10.6lf ",get_matrix_item(i,j));
            cout << aux;
         }
         std::cout << " |";
         cout << endl;
      }

      cout << endl;

   }
}



matrix_item_t matrix_t::get_matrix_item(matrix_inx_t i,matrix_inx_t j)
{
	return M_[pos(i,j)];
}


void matrix_t::set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it)
{
	M_[pos(i,j)]=it;	
}





matrix_inx_t matrix_t::get_m(void)
{
	return m_;
}




matrix_inx_t matrix_t::get_n(void)
{
	return n_;
}




istream& matrix_t::read(istream& is)
{
	int m,n;
	is >> m >> n;

	redimensiona(m,n);

	const int sz=m*n;

	for(int i=0;i<sz;i++)
		is >> M_[i];
	
}



ostream& matrix_t::write(ostream& os)
{
	char aux[80];

	sprintf(aux, " %10d  %10d ",m_,n_);
	os << aux<<endl;

	for(int i=1;i<=m_;i++){
		for(int j=1;j<=n_;j++){
			sprintf(aux," %10.6lf ",get_matrix_item(i,j));
			os << aux;
		}
		os << endl;
	}
}


