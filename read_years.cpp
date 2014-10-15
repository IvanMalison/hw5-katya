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
  int last_read = 0;
  for (int pos = 0; last_read != SENTINEL; pos++) {
    if (pos >= SPACE) {
      cout << "too much input" << endl;
      return 1;
    }
    cin >> last_read;
    years[pos] = last_read;
  }
  print_seq(years);
  cout << "avg = " << average(years) << endl;
  return 0;
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
  double nums_sum = 0;
  double nums_avg = 0;

  for (pos = 0; nums[pos] != SENTINEL; pos++) {
    nums_sum += nums[pos];
  }

  nums_avg = (nums_sum / pos);      

  return nums_avg;

}
