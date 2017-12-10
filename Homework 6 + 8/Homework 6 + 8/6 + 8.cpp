#include <iostream>
#include <string>

using namespace std;

template<class T>
T lgpow(T nr, int pow) {
	T res = nr / nr;

	while (pow) {
		if (pow & 1) res = res * nr;
		nr = nr * nr;

		pow >>= 1;
	}

	return res;
}

class NumarComplex {
public:

	double re, im;

	NumarComplex(double re = 0.0, double im = 0.0) {
		this->re = re;
		this->im = im;
	}

	friend ostream& operator<< (ostream& os, const NumarComplex& nrC) {
		os << nrC.re << ((nrC.im >= 0.0) ? "+" : "") << nrC.im << "i";
		return os;
	}

	friend NumarComplex operator+ (const NumarComplex& lhs, const NumarComplex& rhs) {
		return NumarComplex(lhs.re + rhs.re, lhs.im + rhs.im);
	}

	friend NumarComplex operator- (const NumarComplex& lhs, const NumarComplex& rhs) {
		return NumarComplex(lhs.re - rhs.re, lhs.im - rhs.im);
	}

	friend NumarComplex operator* (const NumarComplex& lhs, const NumarComplex& rhs) {
		return NumarComplex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.re * rhs.im + lhs.im * rhs.re);
	}

	friend NumarComplex operator/ (const NumarComplex& lhs, const NumarComplex& rhs) {
		return NumarComplex( (lhs.re * rhs.re + lhs.im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im), (lhs.im * rhs.re - lhs.re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im) );
	}

	friend NumarComplex operator^ (const NumarComplex& nr, const int& pow) {
		return lgpow(nr, pow);
	}

	friend NumarComplex operator~ (const NumarComplex& nr) {
		return NumarComplex(nr.re, -nr.im);
	}
};

class Operatii {
public:

	template<class T>
	static void print(const T& nr) {
		cout << nr << "\n";
	}

	template<class T>
	static T sum(const T& lhs, const T& rhs) {
		return lhs + rhs;
	}

	template<class T>
	static T dif(const T& lhs, const T& rhs) {
		return lhs - rhs;
	}

	template<class T>
	static T mul(const T& lhs, const T& rhs) {
		return lhs * rhs;
	}

	template<class T>
	static T div(const T& lhs, const T& rhs) {
		return lhs / rhs;
	}

	template<class T>
	static T pow(const T& nr, const int& putere) {
		return lgpow(nr, putere);
	}
};

int main() {

	NumarComplex z1(1.0, 1.0), z2(2.0, 2.0);
	double x1(3.5), x2(4.7);

	cout << "Suma:\n";
	cout << Operatii::sum(x1, x2) << "\n" << Operatii::sum(z1, z2) << "\n\n";

	cout << "Diferenta:\n";
	cout << Operatii::dif(x1, x2) << "\n" << Operatii::dif(z1, z2) << "\n\n";

	cout << "Inmultire:\n";
	cout << Operatii::mul(x1, x2) << "\n" << Operatii::mul(z1, z2) << "\n\n";

	cout << "Impartire:\n";
	cout << Operatii::div(x1, x2) << "\n" << Operatii::div(z1, z2) << "\n\n";

	cout << "Ridicare la putere:\n";
	cout << Operatii::pow(x1, 2) << "\n" << Operatii::pow(z1, 2) << "\n\n";

	cout << "Conjugare:\n";
	cout << ~z1 << "\n" << ~z2 << "\n\n";

	cout << "\n";
	system("pause");

	return 0;
}