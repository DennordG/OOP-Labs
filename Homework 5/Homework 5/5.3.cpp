#include <iostream>
#include <string>
using namespace std;

class Form {
private:
	string color;

protected:
	string name;
	void setColor(string color) {
		this->color = color;
	}

	int calculArie() {
		return 0;
	}

	int calculPerimetru() {
		return 0;
	}

public:
	Form(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}

	void setName(string name) {
		this->name = name;
	}

	void showMessage() {
		cout << "mesaj din Form" << endl;
	}

	void printArie() {
		cout << "Can't calculate surface for this class!\n";
	}

	void printPerimetru() {
		cout << "Can't calculate perimeter for this class!\n";
	}
};

class Rectangle :public Form {
protected:
	int width;
	int height;

	int calculArie() {
		return width * height;
	}

	int calculPerimetru() {
		return 2 * (width + height);
	}

public:
	Rectangle(string name, int width, int height) : Form(name) {
		this->width = width;
		this->height = height;
	}

	void setWidth(int width) {
		this->width = width;
	}

	int getWidth() {
		return this->width;
	}

	void showMessage() {
		Form::showMessage();
		cout << "mesaj din Rectangle" << endl;
	}

	void printArie() {
		cout << "Area of rectangle " << this->name << " is: " << this->calculArie() << "\n";
	}

	void printPerimetru() {
		cout << "Perimeter of rectangle " << this->name << " is: " << this->calculPerimetru() << "\n";
	}
};

class Square :public Form {
protected:
	int side;

	int calculArie() {
		return side * side;
	}

	int calculPerimetru() {
		return 4 * side;
	}

public:
	Square(string name, int side) : Form(name) {
		this->side = side;
	}

	void setSide(int side) {
		this->side = side;
	}

	int getSide() {
		return this->side;
	}

	void showMessage() {
		cout << "mesaj din Square" << endl;
	}

	void printArie() {
		cout << "Area of square " << this->name << " is: " << this->calculArie() << "\n";
	}

	void printPerimetru() {
		cout << "Perimeter of square " << this->name << " is: " << this->calculPerimetru() << "\n";
	}
};

int main()
{
	Form *f = new Form("forma 1");
	cout << "forma: " << f->getName() << endl;
	f->showMessage();
	f->printArie();
	f->printPerimetru();
	cout << "\n";

	Rectangle *r = new Rectangle("rectangle 1", 1, 2);
	cout << "rectangle name: " << r->getName() << "\nwidth:" << r->getWidth() << "\n";
	r->showMessage();
	r->printArie();
	r->printPerimetru();
	cout << "\n";

	Square *s = new Square("square 1", 20);
	cout << "square name: " << s->getName() << "\nside:" << s->getSide() << "\n";
	s->showMessage();
	s->printArie();
	s->printPerimetru();
	cout << "\n";

	system("pause");

	return 0;
}