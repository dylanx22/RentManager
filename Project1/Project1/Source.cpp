#include <iostream>
#include <iomanip>
using namespace std;
//Globals
const int SIZE = 5;
int property;
int rent[SIZE];
int* rentp = rent;

//Function Prototypes
void getMenuItem(bool hasMadeFirstSelection);
void selectionSort(int*, int);
void displayMemoryLocations(int*, int);
void enterRents(int*, int);
int sumRents(int*, int);
void displayRents(int*, int);

int main()
{
	int option;
	bool hasMadeFirstSelection = false;
	cout << fixed << showpoint << setprecision(2);


	while (true)
	{

		getMenuItem(hasMadeFirstSelection); // open the menu
		cout << "Please make your selection: ";
		cin >> option; // get input
		cout << endl;
		if (option == 1)
		{
			hasMadeFirstSelection = true;
		}
		while (option != 1 && !hasMadeFirstSelection) // if they didnt press 1 and also havent entered rent data yet, return invalid
		{
			if (option == 6)
			{
				break;
			}
			cout << "Your input was invalid, please try again.\n" << endl;
			cout << "Please make your selection: ";
			cin >> option;
			cout << endl;
			if (option == 1)
			{
				hasMadeFirstSelection = true; // sets the first selection to 1 after they do it.
			}
		}
		if (option == 6)
			break;
		switch (option) // switch for the menu items
		{
		case 1:
			enterRents(rentp, property);
			cout << endl;
			break;

		case 2:
			selectionSort(rentp, property);
			cout << endl;
			break;

		case 3:
			displayMemoryLocations(rentp, property);
			cout << endl;
			break;

		case 4:
			displayRents(rentp, property);
			cout << endl;
			break;
		case 5:
			cout << "The sum is: " << "$" << sumRents(rentp, property) << endl;
			cout << endl;
			break;

		default:
			cout << "Your input was invalid, please try again.\n" << endl; // any other input returns invalid
			break;
		}

	}

	system("Pause");

	return 0;
}

void getMenuItem(bool hasMadeFirstSelection) // menu function
{
	if (hasMadeFirstSelection)
	{
		cout << "Menu Of Options: \n";
		cout << "1. Re-enter rent amounts \n";
		cout << "2. Sort rent data (ascending) \n";
		cout << "3. Display the memory location of the items in the array \n";
		cout << "4. Show all rent amounts \n";
		cout << "5. Sum all rent amounts \n";
		cout << "6. Exit \n";
	}
	else
	{
		cout << "Menu Of Options: \n";
		cout << "1. Enter rent amounts \n";
		cout << "6. Exit \n";
	}

}

void selectionSort(int* rentp, int property) // sorts the data in descending order
{
	int minIndex, index = 0;
	double minValue = 0;
	//sort taxes due
	for (int startScan = 0; startScan < (property - 1); startScan++) {
		minIndex = startScan;
		minValue = rentp[startScan];
		for (index = startScan + 1; index < property; index++) {
			if (rentp[index] < minValue) {
				minValue = rentp[index];
				minIndex = index;

			}
		}
		if (startScan != minIndex) {
			//swap due amount
			double temp = rentp[minIndex];
			rent[minIndex] = rentp[startScan];

		}
	}
	//display addresses and taxes due
	int i = 0;
	cout << "Rent data sorted in ascending order:\n\n";
	for (i = 0; i < property; i++) {
		cout << left << "$" << *(rentp + i) << endl;
	}
	system("pause");
	cout << "\n";
}
void displayMemoryLocations(int *rentp, int properties) // displays the memory location of the array items
{
	int p = 0;
	while (p < properties)
	{
		cout << "The number " << p << " item in the array's memory location is: " << &rent[p];
		p++;
		cout << endl;
	}
}

void enterRents(int* rentp, int pro) // function to enter the data
{

	cout << "Enter number of properties: \n";
	cin >> property;
	cout << "Enter the rental income of your " << property << " properties: \n";
	for (int i = 0, count = 1; i < property; i++, count++)
	{

		cout << "Property " << count << ": $";
		cin >> *(rentp + i);

	}
	cout << endl;
}

void displayRents(int *rentp, int property) // shows all the current data, using pointers
{

	cout << "List of current rent incomes: \n";
	for (int d = 0; d < property; d++)
	{
		cout << "$" << *(rentp + d) << endl;
	}
}
int sumRents(int* rentp, int property) // Calculate sum, using pointers
{
	int d, sum = 0;
	for (d = 0; d < property; d++)
	{
		sum = sum + *(rentp + d);

	}
	return sum;
}