#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <array>

using namespace std;

const unsigned int BUFFER_SIZE = 14;
char marker[BUFFER_SIZE];
char current;
int totalscore = 0;

int main()
{

  fstream input;
  input.open("input.txt", ios::in); // open a file to perform read operation using file object

  if (input.is_open())
  { // checking whether the file is open

    int char_index = 0;
    
    while (input.get(current))
    { 
      marker[char_index % BUFFER_SIZE] = current;
      if (char_index >= BUFFER_SIZE-1){
        std::set<char> buffer(marker, marker+BUFFER_SIZE);
        if (buffer.size() == BUFFER_SIZE){
          break;
        }
      }
        
      char_index ++;
    }
    input.close(); // close the file object.

    int count_of_chars = char_index + 1;
    cout << "Answer: " << count_of_chars <<  endl;
  }
}
