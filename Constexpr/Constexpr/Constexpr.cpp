#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

constexpr double mileNaKilometry(double mil)
{
	return (1.609344 * mil);
}

constexpr long long silnia(int n)
{
	return n > 0 ? n * silnia(n - 1) : 1;
}

constexpr double pi = 3.14159265;
constexpr double stopnieNaRadiany(double stopni)
{
	return pi * stopni / 180;
}
constexpr double sinus(double x)
{
	return x
		- (x * x * x) / silnia(3)
		+ (x * x * x * x * x) / silnia(5)
		- (x * x * x * x * x * x * x) / silnia(7)
		+ (x * x * x * x * x * x * x * x * x) / silnia(9)
		- (x * x * x * x * x * x * x * x * x * x * x) / silnia(11)
		+ (x * x * x * x * x * x * x * x * x * x * x * x * x) / silnia(13)
		- (x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / silnia(15)
		+ (x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / silnia(17)
		- (x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / silnia(19)
		+ (x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / silnia(21);
}

constexpr double tablicaSinusow[] = {
	sinus(stopnieNaRadiany(0)),
	sinus(stopnieNaRadiany(15)),
	sinus(stopnieNaRadiany(30)),
	sinus(stopnieNaRadiany(45)),
	sinus(stopnieNaRadiany(60)),
	sinus(stopnieNaRadiany(75)),
	sinus(stopnieNaRadiany(90)),
	sinus(stopnieNaRadiany(105)),
	sinus(stopnieNaRadiany(120)),
	sinus(stopnieNaRadiany(135)),
	sinus(stopnieNaRadiany(150)),
	sinus(stopnieNaRadiany(165)),
	sinus(stopnieNaRadiany(180)), //b³¹d??
	sinus(stopnieNaRadiany(195)),
	sinus(stopnieNaRadiany(210)),
	sinus(stopnieNaRadiany(225)),
	sinus(stopnieNaRadiany(240)),
	sinus(stopnieNaRadiany(255)),
	sinus(stopnieNaRadiany(270)),
	sinus(stopnieNaRadiany(285)),
	sinus(stopnieNaRadiany(300)),
	sinus(stopnieNaRadiany(315)),
	sinus(stopnieNaRadiany(330)),
	sinus(stopnieNaRadiany(345)),
	sinus(stopnieNaRadiany(360))
};

int main()
{
	constexpr double dystansMile = 60;
	constexpr double dystansKilometry = mileNaKilometry(dystansMile);
	cout << "Dystans 60 mil to " << dystansKilometry << " kilometrow\n";
	
	cout << "Funkcji constexpr mozna uzywac jako zwyklej funkcji \n5 mil = " << mileNaKilometry(5) << " kilometrow\n";

	constexpr long long silnia10 = silnia(10);
	cout << "10! = " << silnia10 << endl;

	cout << "Moj sinus z szeregu Taylora(1 rad) = " << sinus(1) << ", a biblioteczny sinus(1 rad) = " << sin(1) << endl;
	
	int i = 0;
	for (auto element : tablicaSinusow)
	{
		
		cout << "sinus " << i << " stopni = " << element << endl;
		i += 15;
	}
}