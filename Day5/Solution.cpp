#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


string tp;
int totalscore = 0;
stack<char> crates[9];
string crates_input[9];


// for string delimiter
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main()
{

  fstream input;
  input.open("input.txt", ios::in); // open a file to perform read operation using file object

  crates_input[0] = "PZMTRCN";
  crates_input[1] = "ZBSTND";
  crates_input[2] = "GTCFRQHM";
  crates_input[3] = "ZRG";
  crates_input[4] = "HRNZ";
  crates_input[5] = "DLZPWSHF";
  crates_input[6] = "MGCRZDW";
  crates_input[7] = "QZWHLFJS";
  crates_input[8] = "NWPQS";

  if (input.is_open())
  { // checking whether the file is open


    vector<string> line;
    for (int i = 0; i < 9 ; i++ )
    {
      string str = crates_input[i];
      for(int j = str.length()-1; j >=0 ; j--)
        crates[i].push(str.at(j));
    }
    
    
    int num_moved, from_stack, to_stack = 0;

    while (getline(input, tp))
    { 
      line = split(tp, " ");
      num_moved = stoi(line[1]);
      from_stack = stoi(line[3]);
      to_stack = stoi(line[5]);

      for (int i = 0; i < num_moved ; i++)
      {
        char elem = crates[from_stack-1].top();
        crates[from_stack-1].pop();
        crates[to_stack-1].push(elem);
      }
    }

    input.close(); // close the file object.
    char out[9];
    for (int i = 0; i < 9 ; i++)
    {
      out[i] = crates[i].top();
    }
    cout << "Answer: " << out <<  endl;

  }
}
