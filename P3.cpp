#include<iostream>
#include<algorithm>

//Ali Alzurufi
//This program will conduct a survey with user input to see how many movies students have watched. Then it will display total movies, median, mean, and mode



using namespace std;

//Function Protoypes
int *dynamic(int [], int);

int getMode(int[], const int);

double getMedian(int[], const int);







//Main 
int main()
{
	//initiliaze variables
	int numStudents = 0;

	//dynamic allocation
	int *survey = new int[numStudents];
	
	
	//call function with dynamic array
	dynamic(survey, numStudents);


	//delete memory
	delete[] survey;

	return 0;
}







//function definition that returns pointer, and makes calculations
int *dynamic(int survey [], int numStudents)
{
	//initialize variables
	int moviesTotal = 0;

	//Get user Input on amount of students
	//repeat question if user Input < 0
	do
	{
		cout << "How many students were surveyed? ";
		cin >> numStudents;
	} while (numStudents < 0);

	//Dynamic Memory
	survey = new int[numStudents];

	//for loop for amount of movies each student watched
	for (int i = 0; i < numStudents; i++)
	{
		do
		{
			cout << "How many movies did student # " << i + 1 << " watch? ";
			cin >> survey[i];

		} while (survey[i] < 0);


		//increment total
		moviesTotal += survey[i];
	}

	cout << endl;

	//print total movies
	cout << "Total movies: " << moviesTotal << endl;


	//get mean
	double mean = moviesTotal / numStudents;


	//print mean
	cout << "Mean: " << mean << endl;

	//call getMedian functon and set it equal to median variable
	double median = getMedian(survey, numStudents);


	//display Median 
	cout << "Median: " << median;

	cout << endl;


	int mode = getMode(survey, numStudents);

	cout << "Mode: " << mode;

	cout << endl;


	//return pointer
	return survey;
}






//Function Definition for median
double getMedian(int survey [], const int size)
{
	double median = 0.0;

	//quick sorting method
	sort(survey, survey + size);

	//check if odd amount of numbers
	if (size % 2 != 0)
		median = *(survey + (size / 2));

	//check if even amount of numbers
	else
		median = (*(survey + ((size - 1) / 2)) + *(survey + (size / 2))) / 2.0;
	

	return median;

}






//Function Definition for getting the mode
int getMode(int survey[], const int size)
{
	int val = 0, maxCount = 0;

	for (int i = 0; i < size; i++)
	{
		int count = 0;

		for (int j = 0; j < size; j++)
		{
			if (*(survey + j) == *(survey + i))
				count++;
		}

		if (count > maxCount)
		{
			maxCount = count;
			val = *(survey + i);
		}

		else if (maxCount == 1)
			val == -1;
	}


	return val;
}