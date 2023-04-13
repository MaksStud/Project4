#include<iostream>
#include<cassert>
#include<cstdlib>
#include <algorithm>

using namespace std;

template<typename T>

class Arrey {
public:

	Arrey() : size(0), arr(nullptr) {
	}

	Arrey(size_t size) : size(size) {
		this->arr = new T[size];
	}

	~Arrey() {
		delete[] arr;
	}

	T& operator[](int index) {
		assert(index >= 0 && index < size);
		return arr[index];
	}

	size_t gatSize() {
		return size;
	}

	T& operator=(Arrey other) {
		this->size = other.size;
		this->arr = other.arr;
		return *this;
	}

	int search(T value) {

		for (int i = 0; i < size; i++) {
			if (arr[i] == value) { return i + 1; }
		}
	}

	void sort() {
		for (int i = 0; i < size - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < size; j++) {
				if (arr[j] < arr[minIndex]) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				T temp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex] = temp;
			}
		}
	}


private:
	size_t size;
	T* arr;
};

struct Rational {
	int num;
	int denom;

	Rational(int n = 0, int d = 1) {
		num = n;
		denom = d;
	}

	bool operator<(const Rational& other) const {
		return (num * other.denom < other.num * denom);
	}

	void print() const {
		cout << num << "/" << denom;
	}

	bool operator==(const Rational& other) const {
		return (num == other.num && denom == other.denom);
	}

	bool operator!=(const Rational& other) const {
		return !(*this == other);
	}

};

struct Complex {
	double real;
	double imag;

	Complex(double r = 0.0, double i = 0.0) {
		real = r;
		imag = i;
	}

	double mod() const {
		return sqrt(real * real + imag * imag);
	}

	bool operator<(const Complex& other) const {
		return mod() < other.mod();
	}

	void print() const {
		cout << "(" << real << "," << imag << ")";
	}

	bool operator==(const Complex& other) const {
		return (real == other.real && imag == other.imag);
	}

	bool operator!=(const Complex& other) const {
		return !(*this == other);
	}
};



int main() {

	int sizeA = 10;
	Arrey<int> a(sizeA);

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 10 + 1;
	}

	for (int i = 0; i < sizeA; i++) {
		cout << a[i] << ' ';
	}

	cout << endl;
	cout << "Index element (6) = " << a.search(6);
	cout << endl;
	cout << "____________________________________________________" << endl;

	int sizeb = 10;
	Arrey<char> b(sizeb);

	for (int n = 0; n < sizeb; n++) {
		b[n] = 'a' + rand() % 26;
	}

	for (int h = 0; h < sizeb; h++) {
		cout << b[h] << ' ';
	}

	cout << endl;

	cout << b.search('m') << endl;

	cout << "____________________________________________________" << endl;

	int sizeC = 10;
	Arrey<int> c(sizeC);

	srand(time(NULL));
	for (int k = 0; k < 10; k++) {
		c[k] = rand() % 10 + 1;
	}

	for (int a = 0; a < sizeC; a++) {
		cout << c[a] << ' ';
	}

	c.sort();
	cout << endl;
	for (int m = 0; m < sizeC; m++) {
		cout << c[m] << ' ';
	}

	cout << endl;
	cout << "____________________________________________________" << endl;
	cout << endl;

	Arrey<Complex> complexArray(10); // створення масиву Complex
	Arrey<Rational> rationalArray(10); // створення масиву Rational

	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		int r1 = rand() % 10 + 1;
		int r2 = rand() % 10 + 1;
		complexArray[i] = Complex(r1, r2);
		rationalArray[i] = Rational(r1, r2);
	}

	cout << "Complex array: ";
	for (int i = 0; i < complexArray.gatSize(); i++) {
		complexArray[i].print();
		cout << " ";
	}
	cout << endl;

	cout << "Rational array: ";
	for (int i = 0; i < rationalArray.gatSize(); i++) {
		rationalArray[i].print();
		cout << " ";
	}
	cout << endl;

	cout << "Index of (4,5) in complex array: " << complexArray.search(Complex(4, 5)) << endl;
	complexArray.sort();
	cout << "Complex array after sort: ";
	for (int i = 0; i < complexArray.gatSize(); i++) {
		complexArray[i].print();
		cout << " ";
	}
	cout << endl;

	cout << "Index of (3/2) in rational array: " << rationalArray.search(Rational(3, 2)) << endl;
	rationalArray.sort();
	cout << "Rational array after sort: ";
	for (int i = 0; i < rationalArray.gatSize(); i++) {
		rationalArray[i].print();
		cout << " ";
	}
	cout << endl;

	system("pause");
	return 0;

}