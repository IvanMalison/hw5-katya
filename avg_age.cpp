//
// avg_age.cpp
//
//	use: print average age of people with
//	inputted name
//	
//	created by: Katya Malison
//	date: 10/13/14
//

#include <iostream>

using namespace std;

const int SENTINEL = -1;
const int SPACE = 50001;
const int CUR_YEAR = 2014;

double find_target(int years[], string names[], string target);

int main()
{
	int years[SPACE];
	string names [SPACE];
	string target_name;
       	int pos;
	double avg_year;

	for (pos = 0; pos < SPACE; pos++) {
		cin >> years[pos] >> names[pos];
		if (years[pos] == SENTINEL) {
			break;
		}
	}

	if (pos >= SPACE) {
        	cout << "too much input" << endl;
                return 1;
	}

	cout << "Enter a name: ";
	cin >> target_name;

	avg_year = find_target(years, names, target_name);

	if (avg_year == 0) {
		cout << "name not found" << endl;
	}
	else {
		cout << "average age = " << (CUR_YEAR - avg_year) << endl;
	}

	return 0;
}
///////////////////////////////////////////////////////////////////
/////////////////////////// FUNCTIONS /////////////////////////////
///////////////////////////////////////////////////////////////////

// find_target: identify all people with inputted name,
// return average year of birth
double find_target(int years[], string names[], string target)
{
	int pos;
       	int target_count = 0;
	double years_sum = 0;
	double target_avg;

	for (pos = 0; years[pos] != SENTINEL; pos++) {
		if (names[pos] == target) {	// identify people
			target_count++;		// with target name	
			years_sum += years[pos];
		}
	}
	
	if (target_count == 0) {	// name not stored 
		return 0;
	}
	else {

	target_avg = (years_sum / target_count);	
	}					

	return target_avg;

}
