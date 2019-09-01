#include <iostream>

using namespace std;

void przezWartosc(int wartosc);
void referencjaLwartosc(int& wartosc);
void referencjaConstLwartosc(const int& wartosc);
void referencjaRwartosc(int&& wartosc);

int main()
{
	int obj = 10;
	string przerwa(100, '*');
	cout << "Przez wartosc \nDziala na \"kopii\" obj\n\n";
	cout << "obj = " << obj << endl;
	przezWartosc(obj);
	cout << "obj = " << obj << endl;
	cout << "Przekazuje 20+1 \n";
	przezWartosc(20+1);

	cout << przerwa << "\nPrzez Lwartosc \nZmienia wartosc obj, nie mozna przekazac rvalue\n\n";
	cout << "obj = " << obj << endl;
	referencjaLwartosc(obj);
	cout << "obj = " << obj << endl;
	/*
	Blad	przekazywana wartosc musi byc lvalue

	cout << "Przekazuje 20+2 \n";
	referencjaLwartosc(20 + 2);
	*/

	cout << przerwa << "\nPrzez stala Lwartosc \nStosuje sie do duzych liczb. Nie trzeba ich kopiowac i nie zostana zmienione\n\n";
	cout << "obj = " << obj << endl;
	referencjaConstLwartosc(obj);
	cout << "obj = " << obj << endl;
	cout << "Przekazuje 20+3 \n";
	referencjaConstLwartosc(20 + 3);

	cout << przerwa << "\nPrzez Rwartosc \nNie mozna przekazac lvalue\n\n";
	cout << "obj = " << obj << endl;
	/*
	Blad	przekazywana wartosc musi byc rvalue

	referencjaRwartosc(obj);
	cout << "obj = " << obj << endl;
	*/
	cout << "Przekazuje 20+4 \n";
	referencjaRwartosc(20 + 4);


}

void przezWartosc(int wartosc)
{
	++wartosc;
	cout << "wartosc = " << wartosc << endl;
}

void referencjaLwartosc(int& wartosc)
{
	cout << "wartosc = " << wartosc << endl;
	++wartosc;
}

void referencjaConstLwartosc(const int& wartosc)
{
	cout << "wartosc = " << wartosc << endl;
}

void referencjaRwartosc(int&& wartosc)
{
	cout << "wartosc = " << wartosc << endl;
	++wartosc;
}

