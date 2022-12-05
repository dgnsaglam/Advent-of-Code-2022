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


  if (input.is_open())
  { // checking whether the file is open
    string tp;
    int totalscore, totalscore2 = 0;
    string elf1, elf2;
    int elf1_min, elf1_max, elf2_min, elf2_max = 0;
    int comma_pos;
    int hyp_pos;
    
    while (getline(input, tp))
    { 
      comma_pos = tp.find(",");
      elf1 = tp.substr(0,comma_pos);
      hyp_pos = elf1.find("-");
      elf1_min = stoi(elf1.substr(0,hyp_pos));
      elf1_max = stoi(elf1.substr(hyp_pos+1,elf1.length()-hyp_pos-1));

      elf2 = tp.substr(comma_pos+1,tp.length()-comma_pos-1);
      hyp_pos = elf2.find("-");
      elf2_min = stoi(elf2.substr(0,hyp_pos));
      elf2_max = stoi(elf2.substr(hyp_pos+1,elf2.length()-hyp_pos-1));

      //if ((elf1_min >= elf2_min && elf1_max <= elf2_max) || (elf2_min >= elf1_min && elf2_max <= elf1_max) )
      //  totalscore ++;

      if ((elf1_min <= elf2_min && elf1_max >= elf2_min) || (elf2_min <= elf1_min && elf2_max >= elf1_min) )
        totalscore2 ++;
    }

    input.close(); // close the file object.
    //cout << "Total score 1: " << totalscore <<  endl;

    cout << "Total score 2: " << totalscore2 <<  endl;


  }
}
