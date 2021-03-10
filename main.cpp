//Name-Tasfique Enam
//Student ID-5886429
//Q1
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class InventoryException : public runtime_error
{
	public:
		InventoryException() : runtime_error("Invalid stock number. Stock number should be between 1111 and 9999") {}; //default constructor
		InventoryException(int quantity) : runtime_error("Invalid quantity. Quantity should not be negative.") {}; //non default
		InventoryException(double price) : runtime_error("Invalid price. Price should not be below RM0 and over RM10000.00.") {}; //non default
};

class Inventory
{
	private:
		int stockNumber;
		int quantity;
		double price;

	public:
		Inventory() //default constructor.
		{
			stockNumber = 0;
			quantity = 0;
			price = 0.0;
		};

		Inventory(int stockNumber, int quantity, double price) : stockNumber(stockNumber), quantity(quantity), price(price) {};
		friend ostream &operator<<(ostream &output, const Inventory &I) //overloaded insertion
		{
			output << "Stock: " << I.stockNumber << ", Quantity: " << I.quantity << ", Price : " << I.price << endl;
			return output;
		}
		friend istream &operator>>(istream &input, Inventory &I) //overloaded extraction.
		{
			cout << "Enter Stock: " << endl;
			input >> I.stockNumber;
            cout << "Enter Quantity : " << endl;
			input >> I.quantity;
			cout << "Enter Price : " << endl;
			input >> I.price;

			if(I.stockNumber < 1111 || I.stockNumber > 9999)
			{
				InventoryException error;
				throw(error);
			}
			else if(I.quantity < 0)
			{
				InventoryException error(I.quantity);
				throw(error);
			}
			else if(I.price < 0 || I.price > 10000)
			{
				InventoryException error(I.price);
				throw(error);
			}
			return input;
		}
};
int main()
{
	int stockNumber;
	int quantity;
	double price;
	InventoryException error;
	Inventory inventory;
	cin >> inventory;

	try
	{
		Inventory(stockNumber, quantity, price);
		cout << inventory;
	}
	catch(runtime_error e)
	{
		cout << "Error" << endl;
		cout << e.what();
	}

	return 0;
}
