//
// read_years.cpp - demo of sentinel
//
//	edited by: Katya Malison
//	date: 10/12/14
//

#include <iostream>
using namespace std;

const int SPACE    = 1000;
const int SENTINEL = -1;

/////////////////////////////////////////////////////////////////////////
///////////////////////////   Interfaces  ///////////////////////////////
/////////////////////////////////////////////////////////////////////////

// print a sequence of numbers
// terminated by a sentinel
void   print_seq(int nums[]);

// returns the average (mean) value
// of the integers in the sequence
double average  (int nums[]);


/////////////////////////////////////////////////////////////////////////
/////////////////////////////   Client  /////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int main()
{
        int years[SPACE];
        int pos = 0;
        int y;
        double avg;

        do {
                cin >> y;
                years[pos] = y;
		pos++;
        } while ((years[pos] != SENTINEL) and (pos < SPACE));
	
	cout << pos << endl;

	if ((pos = SPACE) and (years[SPACE-1] != -1)) {
		cout << "too much input" << endl;
		return 1;
	}
	else {
        print_seq(years);
        avg = average(years);
        cout << "avg = " << avg << endl;

        return 0;
	}
}

/////////////////////////////////////////////////////////////////////////
///////////////////////////   Abstraction ///////////////////////////////
///////////////////////////     Barrier   ///////////////////////////////
/////////////////////////////////////////////////////////////////////////

//////////////////////////  Implementations /////////////////////////////

// print a sequence of numbers
// terminated by a sentinel
void print_seq(int nums[SPACE])
{
        int pos = 0;
        while (nums[pos] != SENTINEL) {
                cout << pos << " " << 
	        nums[pos] << endl;
                pos++;
        }
}

// returns the average (mean) value
// of the integers in the sequence
double average(int nums[SPACE])
{
	int pos;
	double nums_sum;
	double nums_avg;

	for (pos = 0; nums[pos] != SENTINEL; pos++) {
		nums_sum += nums[pos];
	}

	nums_avg = (nums_sum / pos);      

        return nums_avg;

}
