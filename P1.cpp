#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

//Ali Alzurufi
//This program will read integers from a data file and classify them as even or odd. It will also find the sum and average of these numbers. 
// Output will be written in another file


//function protoypes

bool checkEven(int);

bool checkOdd(int);



int main()
{
	//initialize variables
	int data, odds = 0, evens = 0, zeros = 0, count = 0, average = 0, sum = 0;

	//Input file
	ifstream Input("Data.txt");

	//output file
	ofstream Output("Output.txt");



	if (Input.is_open())
	{

		//while file is open read values from it and output to new file
		while (Input >> data)
		{
			
			//output data and increment count
			Output << data << " ";
			count++;


			//if there is 10 numbers start a new line
			if (count == 10)
			{
				Output << endl;
				count = 0;
			}

			//check if number is even including zero
			if (checkEven(data))
			{
				evens++;

				if (data == 0)
					zeros++;
			}


			//check if number is odd
			if (checkOdd(data))
				odds++;

			//increment sum
			sum += data;
		}

		
		

		Output << endl;

	
		//print total evens and zeros
		Output << "There are " << evens << " evens, which includes " << zeros << " zeros" << endl;

		//print total odds
		Output << "Total number of odds are: " << odds << endl;

		//print sum
		Output << "The sum of numbers = " << sum << endl;

		//print average
		Output << "The average is " << sum / 43 << endl;

		//close files
		Input.close();
		Output.close();
	}


	//Display error message if file cannot open

	else
	{
		cout << "Error. Failed to open file " << endl;
	}


	return 0;
}



//Function defintion to check whether number is even 
bool checkEven(int data)
{
	return data % 2 == 0;
}


//Function definition to check whether number is odd
bool checkOdd(int data)
{
	return data % 2 != 0;
}