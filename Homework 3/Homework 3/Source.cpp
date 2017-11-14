#include <iostream>
#include <string>
#include <list>

using namespace std;

class Student {
	int mark;
	string name;

	static int nrStudents;

	Student(string name, int mark) {
		++this->nrStudents;

		this->mark = mark;
		this->name = name;
	}

public:

	static Student createStudent(string name, int mark = 8) {
		return Student(name, mark);
	}

	~Student() {
		--nrStudents;
	}

	void print() {
		cout << "Student's name: " << this->name << "\n";
		cout << "Student's mark: " << this->mark << "\n\n";
	}
};

int Student::nrStudents = 0;

int main() {
	
	list<Student> listOfStudents;

	listOfStudents.push_back(Student::createStudent("John", 5));
	listOfStudents.push_back(Student::createStudent("Maria"));

	for (Student student : listOfStudents)
		student.print();

	system("pause");

	return 0;
}