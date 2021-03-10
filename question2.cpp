//Name-Tasfique Enam
//Student ID- 5886429
//Q2

#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

template <class T>
string binarySearch(T a[], int size, T x)
{
	int l=0;
	int h=size-1;

	while(l <= h)
	{
		int m = (l+h)/2;
		if(x<a[m])
		{
			h=m-1;
		}
		else if(x>a[m])
		{
			l=m+1;
		}
		else
		{
			return "FOUND";
		}
	}
	return "NOT FOUND";
}

class Student
{
	private:
		string studentID;
		string studentName;
		string studentgrade;

	public:
		Student()
		{
			studentID = "null";
			studentName = "null";
			studentgrade = "null";
		}
		Student(string studentID) : studentID(studentID)
		{
			studentName = "null";
			studentgrade = "null";
		}
		Student(string studentID, string studentName, string studentgrade) : studentID(studentID), studentName(studentName), studentgrade(studentgrade) {}
		void setStudId(string studentID)
		{
			this->studentID=studentID;
		}
		string getStudId()
		{
			return studentID;
		}
		friend ostream &operator<<(ostream &output, const Student &s)
		{
			output << "Student ID : " << s.studId << ", Student Name : " << s.studName << ", Student Grade : " << s.studGrade << endl;
			return output;
		}
		friend istream &operator>>(istream &input, Student &s)
		{
			cout << "Input student ID, name, grade" << endl;
			input >> s.studId >> s.studName >> s.studGrade;
			return input;
		}
		Student& operator=(const Student &s)
		{
			studentID=s.studentID;
			return *this;
		}
		bool operator<(const Student &s)
		{
			if((studentID.compare(s.studentID)) > 0)
			{
				return true;
			}
			return false;
		}
		bool operator>(const Student &s)
		{
			if((s.studentID.compare(studentID)) < 0)
			{
				return true;
			}
			return false;
		}
		bool operator==(const Student &s)
		{
			if((studentID.compare(s.studentID)) == 0)
			{
				return true;
			}
			return false;
		}
};

class Book
{
	private:
		string title;
		string author;
		double price;

	public:
		Book()
		{
			title = "null";
			author = "null";
			price = 0.0;
		}
		Book(string title) : title(title)
		{
			author = "null";
			price = 0.0;
		}
		Book(string title, string author, double price) : title(title), author(author), price(price) {}
		string getTitle()
		{
			return title;
		}
		friend ostream &operator<<(ostream &output, const Book &b)
		{
			output << "Title : " << b.title << ", Author : " << b.author << ", Price : " << b.price<< endl;
			return output;
		}
		friend istream &operator>>(istream &input, Book &b)
		{
			cout << "Input book title, author, price" << endl;
			input >> b.title >> b.author >> b.price;
			return input;
		}
		Book& operator=(const Book &b)
		{
			title=b.title;
			return *this;
		}
		bool operator<(const Book &b)
		{
			if((title.compare(b.title)) > 0)
			{
				return true;
			}
			return false;
		}
		bool operator>(const Book &b)
		{
			if((b.title.compare(title)) < 0)
			{
				return true;
			}
			return false;
		}
		bool operator==(const Book &b)
		{
			if((title.compare(b.title)) == 0)
			{
				return true;
			}
			return false;
		}
};

int main()
{
	int choice, result;
	const int arraySize = 3;
	int intArr[arraySize] = {2, 5, 7};
	float floatArr[arraySize] = {2.3, 4.3, 6.5};
	char charArr[arraySize] = {'a', 'b', 'c'};

	Student s1("12345", "John", "A");
	Student s2("34322", "Kim", "B");
	Student s3("RR2345", "Jen", "C");
	Student studentArr[arraySize] = {s1, s2, s3};

	Book b1("Dragons", "Ross", 70.6);
	Book b2("Game Of Thrones", "GG Martin", 100.00);
	Book b3("Kill", "Ribbery", 60.5);
	Book bookArr[arraySize] = {b1, b2, b3};

	for(int i=0; i<arraySize; i++)
	{
		cout << studentArr[i];
	}
	for(int i=0; i<arraySize; i++)
	{
		cout << bookArr[i];
	}

	int searchValue;
	float searchValue2;
	char searchValue3;
	string searchValue4;
	string searchValue5;

    cout << "Input a value to search for INT: ";
    cin >> searchValue;
    cout << binarySearch(intArr, arraySize, searchValue) << endl;
    cout << "Input a value to search for FLOAT: ";
    cin >> searchValue2;
    cout << binarySearch(floatArr, arraySize, searchValue2) << endl;
    cout << "Input a value to search for CHAR: ";
    cin >> searchValue3;
    cout << binarySearch(charArr, arraySize, searchValue3) << endl;
    cout << "Enter Student ID to search for : ";
    cin >> searchValue4;
    Student searchStudent(searchValue4);
    cout << binarySearch(studentArr, arraySize, searchStudent) << endl;
    cout << "Enter Book title to search for : ";
    cin >> searchValue5;
    Book searchBook(searchValue5);
    cout << binarySearch(bookArr, arraySize, searchBook) << endl;


	return 0;
}
