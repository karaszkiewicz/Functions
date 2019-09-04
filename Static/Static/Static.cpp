#include <iostream>

using namespace std;

void fun1();
void fun2();

int main()
{
	fun1();
	fun2();
	fun1();
	fun2();
	fun2();
	fun1();
	fun1();
}

void fun1()
{
	static int licznik;
	licznik++;
	cout << "Fun1: licznik = " << licznik << endl;
}

void fun2()
{
	static int licznik = 10;
	licznik++;
	cout << "Fun2: licznik = " << licznik << endl;
}