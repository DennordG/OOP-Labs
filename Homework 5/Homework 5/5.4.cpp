#include <iostream>
#include <string>

using namespace std;

class Desert {
protected:
	string mainName;
	float sweetness;
	int price;

public:
	Desert(string mainName, float sweetness, int price) {
		this->mainName = mainName;
		this->sweetness = sweetness;
		this->price = price;
	}

	void print() {
		cout << "mainName: " << mainName << "\n";
		cout << "sweetness: " << sweetness << "\n";
		cout << "price: " << price << "\n";
	}
};

class Prajitura : public Desert {
protected:
	string p1;
	float p2;
	int p3;

public:
	Prajitura(string mainName, float sweetness, int price, string p1, float p2, int p3) : Desert(mainName, sweetness, price) {
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;
	}

	void print() {
		Desert::print();
		cout << "p1: " << p1 << "\n";
		cout << "p2: " << p2 << "\n";
		cout << "p3: " << p3 << "\n";
	}
};

class TortAniversare : public Desert {
protected:
	string t1;
	float t2;
	int t3;

public:
	TortAniversare(string mainName, float sweetness, int price, string t1, float t2, int t3) : Desert(mainName, sweetness, price) {
		this->t1 = t1;
		this->t2 = t2;
		this->t3 = t3;
	}
	
	void print() {
		Desert::print();
		cout << "t1: " << t1 << "\n";
		cout << "t2: " << t2 << "\n";
		cout << "t3: " << t3 << "\n";
	}
};

int main()
{
	Desert *d = new Desert("Gem de visine", 3.4f, 10);
	d->print();
	cout << "\n";
	delete d;

	Prajitura *p = new Prajitura("Baclava", 6.5f, 40, "something for p1", 0.2f, 31);
	p->print();
	cout << "\n";
	delete p;

	TortAniversare *t = new TortAniversare("Tort de nunta", 5.4f, 100, "something for t1", 0.3f, 32);
	t->print();
	cout << "\n";
	delete t;

	system("pause");

	return 0;
}