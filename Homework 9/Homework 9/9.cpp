#include <iostream>
#include <string>

using namespace std;

struct Base_Sound {
	virtual void play() const = 0;
};

struct Animal_Sound : Base_Sound {
	virtual void play() const override {
		cout << "I'm an animal!\n";
	}
};

struct Duck_Sound : Animal_Sound {
	void play() const final {
		__super::play();
		cout << "More specifically, a duck!\n";
		cout << "Quack Quack Quack!\n";
	}
};

struct Horse_Sound : Animal_Sound {
	void play() const final {
		__super::play();
		cout << "More specifically, a horse!\n";
		cout << "Ni-ha-ha-ha!\n";
	}
};

class Animal {
	string name;
	string color;

public:
	
	Animal(string name, string color) {
		this->name = name;
		this->color = color;
	}

	string getName() const {
		return this->name;
	}

	string getColor() const {
		return this->color;
	}

	virtual void reveal() const {
		cout << "\nHello! My name is " << getName() << "!\n";
		cout << "My color is " << getColor() << "!\n";
		cout << "As you can tell, ";
	}
};

class Duck: public Animal {
	Duck_Sound sound;

public:

	Duck(string name, string color) : Animal(name, color) {}

	void reveal() const override {
		__super::reveal();
		sound.play();
	}
};

class Horse : public Animal {
	Horse_Sound sound;

public:

	Horse(string name, string color) : Animal(name, color) {}

	void reveal() const override {
		__super::reveal();
		sound.play();
	}
};

int main() {
	Animal* females[] = { new Duck("Francesca", "white") };
	Animal* males[] = { new Duck("Gustav", "blue + green"), new Horse("Danutz", "brown") };

	for (const Animal* animal : females)
		animal->reveal();

	for (const Animal* animal : males)
		animal->reveal();

	for (const Animal* animal : females)
		delete animal;

	for (const Animal* animal : males)
		delete animal;

	system("pause");

	return 0;
}