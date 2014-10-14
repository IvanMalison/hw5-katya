
// over_avg.cpp
//
//	use: calculate number of inputted years
//	that are over the average input year
//	notes: does not accommodate for
//      negative numbers
//	
//	created by: Katya Malison
//	date: 10/12/14
//

#include <iostream>

using namespace std;

const int SPACE = 30001;

const int SENTINEL = 0;

double avg_num(int x[]);

int over_num(int x[], double y);

int main()
{
	int years[SPACE];
	int pos;
	double average;
	int total_over;

	for (pos = 0; pos < SPACE; pos++) {
		cin >> years[pos];
		if (years[pos] == SENTINEL) { 
			break;
		}
	}

	cout << pos << endl;
	
	if (pos >= SPACE) {
		cout << "too much input" << endl;
		return 1;
	}
	
	average = avg_num(years);
       	total_over = over_num(years, average);

	cout << total_over << endl;

	return 0;
}
////////////////////////////////////////////////
////////////////// FUNCTIONS ///////////////////
////////////////////////////////////////////////

// avg_num: return average year
double avg_num(int x[])
{
	double total_sum = 0;
	double  average;
	int pos;

	for (pos = 0; x[pos] != SENTINEL; pos++) {
		total_sum += x[pos];
	}

	average = total_sum / pos;

	return average;
}

// over_num: return number of years over average
int over_num(int x[], double y)
{
	int over_avg = 0;
	int pos;

	for (pos = 0; x[pos] != 0; pos++) {
		if (x[pos] > y) {
			over_avg++;
		}
	}

	return over_avg;
}	
