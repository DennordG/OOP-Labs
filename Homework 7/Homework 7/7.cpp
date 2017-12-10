#include <iostream>
#include <string>
#include <list>

using namespace std;

// For the friend exercise, we can just take the Book structure outside of Library, make it class and friend her with Library for the same effect:
/*

class Book {
	...

	friend class Library;
};

*/

class Library {
	struct Book {
		string name;
		string year;

		Book() {}

		Book(string name, string year) {
			this->name = name;
			this->year = year;
		}

		static Book read_and_create() {
			Book newBook;

			cout << "Creating a book...\n";

			cout << "Name: ";
			cin >> newBook.name;
			
			cout << "Year: ";
			cin >> newBook.year;

			return newBook;
		}

		void print() const {
			cout << "\nBook:\n";
			cout << "----Name: " << this->name << "\n";
			cout << "----Year: " << this->year << "\n";
		}
	};

	list<Book> lst_of_books;
	size_t nr_books = 0;

public:

	Library(size_t nr_books = 0) {
		this->nr_books = nr_books;

		for (size_t i = 0; i < nr_books; ++i)
			lst_of_books.push_back(Book::read_and_create());
	}

	void print() const {
		cout << "\nPrinting whole library...\n";

		for (const auto& book : lst_of_books)
			book.print();
	}

	void sortByName() {
		lst_of_books.sort([](const auto& lhs, const auto& rhs) { return lhs.name < rhs.name; });
	}

	void sortByYear() {
		lst_of_books.sort([](const auto& lhs, const auto& rhs) { return lhs.year < rhs.year; });
	}
};

int main() {
	Library library(5);

	library.print();

	cout << "\n---- Library sorted by name: ---- \n";
	library.sortByName();
	library.print();
	cout << string(37, '-') << "\n";

	cout << "\n---- Library sorted by year: ---- \n";
	library.sortByYear();
	library.print();
	cout << string(37, '-') << "\n";

	system("pause");

	return 0;
}