#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int main()
{

  fstream input;

  input.open("input.txt", ios::in); // open a file to perform read operation using file object

  // empty map container
  map<string, int> gquiz1;
  gquiz1.insert(pair<string, int>("A X", 4)); //1+3
  gquiz1.insert(pair<string, int>("B X", 1)); //1+0
  gquiz1.insert(pair<string, int>("C X", 7)); //1+6
  gquiz1.insert(pair<string, int>("A Y", 8)); //2+6
  gquiz1.insert(pair<string, int>("B Y", 5)); //2+3
  gquiz1.insert(pair<string, int>("C Y", 2)); //2+0
  gquiz1.insert(pair<string, int>("A Z", 3)); //3+0
  gquiz1.insert(pair<string, int>("B Z", 9)); //3+6
  gquiz1.insert(pair<string, int>("C Z", 6)); //3+3

  map<string, int> gquiz2;
  gquiz2.insert(pair<string, int>("A X", 3)); //0+3
  gquiz2.insert(pair<string, int>("B X", 1)); //0+1
  gquiz2.insert(pair<string, int>("C X", 2)); //0+2
  gquiz2.insert(pair<string, int>("A Y", 4)); //3+1
  gquiz2.insert(pair<string, int>("B Y", 5)); //3+2
  gquiz2.insert(pair<string, int>("C Y", 6)); //3+3
  gquiz2.insert(pair<string, int>("A Z", 8)); //6+2
  gquiz2.insert(pair<string, int>("B Z", 9)); //6+3
  gquiz2.insert(pair<string, int>("C Z", 7)); //6+1

  if (input.is_open())
  { // checking whether the file is open
    string tp;
    int totalscore = 0;
    int totalscore2 = 0;
    int currentscore = 0;
    int currentscore2 = 0;
    while (getline(input, tp))
    { 
      currentscore = gquiz1[tp];
      totalscore += currentscore;

      currentscore2 = gquiz2[tp];
      totalscore2 += currentscore2;
    }
    input.close(); // close the file object.
    cout << "Total score 1: " << totalscore <<  endl;
    cout << "Total score 2: " << totalscore2 <<  endl;

  }
}
