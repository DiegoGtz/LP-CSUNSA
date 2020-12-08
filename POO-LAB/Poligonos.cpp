// Area y Perimetro de los Poligonos: 
// Triángulos, Rectángulo, Cuadrado, Pentágono, Hexágono, Heptágono y Octógono
//CS-UNSA 


#include <iostream>
#include <stdlib.h>
#include <math.h>


using namespace std;



template<class T>

class Poligonos
{
public:
	T _A; //Area
	T _P; //Perimetro 
	T _S; //Semiperimetro 
public:
	Poligonos(){
		this->_A = 0;
		this->_P = 0;	
	}
	virtual T Perimetro()  {return _P; }
	virtual T Area()  {return _A;}
	virtual void print()	
	{
		cout<<"Area : "<<_A<<endl;
		cout<<"Perimetro : "<<_P<<endl;
	}	
};
template <class T>
class Triangulo : public Poligonos<T>{
public:
	T lado1, lado2, lado3; 
public:
	Triangulo(T l1, T l2,T l3){
		lado1 = l1 > 0 ? l1:0;
		lado2 = l2 > 0 ? l2:0;
		lado3 = l3 > 0 ? l3:0;
	}
	T Perimetro() {
		return this->_P = lado1 + lado2 + lado3;
	}
	T Area() {
	    T s = Perimetro()/2;
		return this->_A =sqrt(s*(s-lado1)*(s-lado2)*(s-lado3)) ;
	} 
	void print(){
	     cout << endl << "-------Triangulo-------" << endl
	      << "Lado 1 = " << lado1 << endl
	      << "Lado 2 = " << lado2 << endl
	      << "Lado 3 = " << lado3 << endl;
	}
};

template<class T>
class Cuadrado : public Poligonos<T>
{
public:
	T lado;	
public:
	Cuadrado(){};
	Cuadrado(T l1){
		this->lado = l1 > 0 ? l1:0;
	}
	T Perimetro(){return this->_P = 4*lado;}
	T Area(){return this->_A = pow(lado,2);}
	void print(){
		cout << endl << "-------Cuadrado-------" << endl
	    << "Lado " << lado << endl;
	}	
};

template<class T>
class Rectangulo : public Poligonos<T>
{
public: 
	T lado1, lado2;
public:
	Rectangulo(){};
	Rectangulo(T l1, T l2){
		this->lado1 = l1 > 0 ? l1 :0;
		this->lado2 = l2 > 0 ? l2 :0;
	}
	T Perimetro(){return this->_P = 2*lado1 + 2*lado2;}
	T Area(){return this->_A = lado1*lado2;}
	void print(){
		cout << endl << "-------Rectangulo-------" << endl
	    << "Lado1 " << lado1 << endl
	    << "Lado2 " << lado2 << endl;				
	}
	
};

//Clase para alcular Perimetro y Area de un Pentágono, Hexágono, Heptágono y Octógono
template<class T>
class Poligono_N_Lados : public Poligonos<T>
{
public: 
	T lado;
	T Vertices;
	T apotema;
public:

	Poligono_N_Lados(){};
	Poligono_N_Lados(T l1, T v1, T apo){
		this->lado     = l1 >0 ? l1 :0; //tamanio de los lados 
		this->Vertices = v1 >0 ? v1:0; // para diferenciar que tipo de poligono es 
		apotema        = apo>0 ? apo:0;
	}

	T Perimetro() {return this->_P = Vertices*lado;} //Numero de lados * el tamaño
	//T SemiPerimetro(){return this->_S =this->_P/2;}
	//Calculo del Area de un poligono regular usando
	// A = Perimetro * apotema /2

	T Area(){
		T P = Perimetro();	
		return this->_A = (P*apotema)/2;
	}

	void print(){

		int v = Vertices;
		switch(v)
		{
			case 5: 
				cout << endl << "-------Pentagono Regular-------" << endl
	   			<< " 5 Lados de  : " << lado << endl;
	   			break;
			case 6: 
				cout << endl << "-------Hexagono Regular-------" << endl
	   			<< " 6 Lados de  : " << lado << endl;
	   			break;
			case 7: 
				cout << endl << "-------Heptagono Regular-------" << endl
	   			<< " 7 Lados de  : " << lado << endl;
	   			break;
			case 8: 
				cout << endl << "-------Octogono Regular-------" << endl
	   			<< " 8 Lados de  : " << lado << endl;
	   			break;
	   		default:
	   		    cout<<"No es ninguno Y_Y"<< endl ; 
		}
	}	
};
//
template<class T>
void VerPoligono(Poligonos<T> &_Poligono ){
	_Poligono.print();
    cout << endl <<"Perimetro = " << _Poligono.Perimetro() << endl
            <<"Area = " << _Poligono.Area() << endl;
}

int main()
{



	cout<<"Area y Perimetro de Poligonos"<< endl;  

	int a , b ;
	do{
		cout<<"****************************************"<<endl;
		cout<<"1- Triangulo \n";
		cout<<"2- Cuadrado \n";
		cout<<"3- Rectangulo \n";
		cout<<"4- Pentagono \n";
		cout<<"5- Hexagono \n";
		cout<<"6- Heptagono \n";
		cout<<"7- Octogono \n";
		cout<<"0- Salir \n \n";
		cin>>a;

		switch(a)
		{
			case 0: 
				cout<<"Salir"<< endl;
				return 0;
			case 1:{
				cout<<"*********Triangulo*************"<<endl;
				cout<<"Ingrese los lados del triangulo "<< endl;

				double l1, l2,l3 ;

				cout<<"Lado 1 " << endl;
				cin>> l1;
				cout<<"Lado 2 " << endl;
				cin>> l2;
				cout<<"Lado 3 " ;
				cin>> l3;

				Triangulo<double> _triangulo(l1,l2,l3);
				VerPoligono(_triangulo);
			}
				break;
			case 2:{
			  	cout<<"*********Cuadrado*************"<<endl;
			  	cout<<"Ingrese los lados del triangulo "<< endl;

			  	double l1;
				cout<<"Lado 1 " << endl;
				cin>> l1;

				Cuadrado<double> _cuadrado(l1);
				VerPoligono(_cuadrado);
				}
			  	break;
			case 3:{
				cout<<"*********Rectangulo*************"<<endl;
				cout<<"Ingrese los lados del Rectangulo "<< endl;
				double l1, l2;

				cout<<"Lado 1 " << endl;
				cin>> l1;
				cout<<"Lado 2 " << endl;
				cin>> l2;
				Rectangulo<double> _Rectangulo(l1,l2);
				VerPoligono(_Rectangulo);
				}

				break;
			case 4:{
				cout<<"*********Pentagono Regular*************"<<endl;

				cout<<"Ingrese los lados del Pentagono Regular "<< endl;
				double l1, apotema;
				cout<<"Lado  " << endl;
				cin>> l1;
				cout<<"Apotema  " << endl;
				cin>> apotema;

				Poligono_N_Lados<double> _Pentagono(l1,5,apotema); // lado, lados, apotema
				VerPoligono(_Pentagono);

				}


				break;
			case 5: {

				cout<<"*********Hexagono Regular*************"<<endl;

				cout<<"Ingrese los lados del Hexagono Regular "<< endl;
				double l1, apotema;
				cout<<"Lado  " << endl;
				cin>> l1;
				cout<<"Apotema  " << endl;
				cin>> apotema;

				Poligono_N_Lados<double> _Hexagono(l1,6,apotema); // lado, lados, apotema
				VerPoligono(_Hexagono);
			}
				
				break;
			case 6:{
				cout<<"*********Heptagono Regular*************"<<endl;

				cout<<"Ingrese los lados del Hexagono Regular "<< endl;
				double l1, apotema;
				cout<<"Lado  " << endl;
				cin>> l1;
				cout<<"Apotema  " << endl;
				cin>> apotema;

				Poligono_N_Lados<double> _Heptagono(l1,7,apotema); // lado, lados, apotema
				VerPoligono(_Heptagono);
			
			}
				break;	
			case 7:
			{
				cout<<"*********Octogono Regular*************"<<endl;

				cout<<"Ingrese los lados del Octogono Regular "<< endl;
				double l1, apotema;
				cout<<"Lado  " << endl;
				cin>> l1;
				cout<<"Apotema  " << endl;
				cin>> apotema;

				Poligono_N_Lados<double> _Octogono(l1,8,apotema); // lado, lados, apotema
				VerPoligono(_Octogono);
			}
				
				break;
			default:
				return main();
				break;
		}




	}while( a != 7);
	system("pause");
	return main(); 



	

	/*cout<<"Area y Perimetro de los siguientes Poligonos"<<endl;
	cout<<endl;

	Triangulo<double> fig1(3,5,4);
	VerPoligono(fig1);

	Cuadrado<double> fig2(3);
	VerPoligono(fig2);

	Rectangulo<double> fig3(2,3);
	VerPoligono(fig3);


	Poligono_N_Lados<double> fig4(6,8,4); // lado, lados, apotema
	VerPoligono(fig4);*/
	//return 0;
}
