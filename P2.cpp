#include<iostream>
#include<cstring>
#include<cctype>
#include<fstream>

using namespace std;

// Ali Alzurufi
// Date: 02/10/2023
// This program will take user input and verify if the user has created a valid password that meets the requirements
// The password should be at least 8 characters long
// The password should have at least one uppercase and one lowercase letter
// The password should contain at least one digit
// The password cannot be one that has already been used in the past (from passwords in text file)



//Display info for password requirements
void info();


//Function protoypes for password requirements
bool isLength(char []);

bool isUpper(char []);

bool isLower(char []);

bool isDigit(char []);



int main()
{

	//Input file
	ifstream Input("oldpasswords.txt");

	if (Input.is_open())
	{

		//create character arrays for user input and data
		char pass[15];
		char oldPass[15];

		//call info function
		info();


		while (true)
		{
			//Read data into oldPass
			Input >> oldPass;

			// userInput
			cout << "Enter a password: ";
			cin >> pass;


			//if user input is less than 8 characters, display message
			if (!isLength(pass))
			{
				cout << "The password you entered is too short " << endl;
				cout << endl;

			}

			// if user input does not have a capital letter, display message
			else if (!isUpper(pass))
			{
				cout << "The password you entered does not contain an uppercase letter " << endl;
				cout << endl;

			}

			// if user input does not have a lower case letter, display message
			else if (!isLower(pass))
			{
				cout << "The password you entered does not contain a lowercase letter " << endl;
				cout << endl;

			}


			// if user input does not contain a digit, display message
			else if (!isDigit(pass))
			{
				cout << "The password you entered does not contain a number " << endl;
				cout << endl;
			}


			//If user input is not the same as passwrd from data file , print message
			else if(strcmp(pass, oldPass) < 0)
			{
				cout << "You have successfully created a password! " << endl;
				break;
			}


			//If user Input == passwords from data file, print error message and return to the top of the input file to read again
			else
			{
				cout << "The password you entered cannot be the same as a previously used password." << endl;
				cout << endl;

				Input.clear();
				Input.seekg(0, ios::beg);
		
				
			}

		}

		Input.close();
	}


	//Error message if file won't open
	else
	{
		cout << "File has failed to open ";
	}

	return 0;
}




//Function definition for info
void info()
{
	cout << "Create a new password " << endl;
	cout << endl;
	cout << "The password should be at least 8 characters long" << endl;
	cout << "The password should have at least one uppercase and one lowercase letter " << endl;
	cout << "The password should contain at least one digit " << endl;
	cout << "The password cannot be one that has already been used in the past " << endl;
	cout << "---------------------------------------------------------------------------- " << endl;

	cout << endl;
	cout << endl;
}




//Function definition for checking length 
bool isLength(char pass[])
{
	if (strlen(pass) >= 8)
		return true;

	else
		return false;
}



//Function definition for checking uppercase letters
bool isUpper(char pass[])
{
	for (int i = 0; i < strlen(pass); i++)
	{
		if (isupper(pass[i]))
			return true;
	}
	return false;
}


//Function definition for checking lowercase letters
bool isLower(char pass[])
{
	for (int i = 0; i < strlen(pass); i++)
	{
		if (islower(pass[i]))
			return true;
	}

	return false;
}


//Function definition for checking if it contains a number
bool isDigit(char pass[])
{
	for (int i = 0; i < strlen(pass); i++)
	{
		if (isdigit(pass[i]))
			return true;
	}

	return false;
}