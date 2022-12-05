#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void arrangeFirstThree(std::vector<int> &values, int &&newvalue){
    if (values.size() < 3){
        values.push_back(newvalue);
        std::sort(values.begin(), values.end());
    }else{
        for (int i = 0; i <values.size(); i++)
            {
                if (newvalue > values[i]) {
                    values[i] = newvalue;
                    std::sort(values.begin(), values.end());
                    break;
                } 
            }
    }
}

int main(){
   fstream input;

   input.open("input.txt",ios::in); //open a file to perform read operation using file object
   long max_totalcalorie=0;
   int max_calorie_elf=0;
   int elfindex = 0;
   vector<int> max3calories;
   if (input.is_open()){   //checking whether the file is open
      string tp;
      int calorie;
      while(getline(input, tp)){ //read data from file object and put it into string.
        long totalcalorie = 0;
        while(tp != "" && !input.eof()){
          totalcalorie += stoi(tp);
          getline(input, tp);
        }
          
        elfindex++;
        //cout << "Current elf: " << elfindex << " Current elf calorie: " << totalcalorie << endl;
        arrangeFirstThree(max3calories, totalcalorie);
        if (totalcalorie > max_totalcalorie)
        {
            max_totalcalorie = totalcalorie;
            max_calorie_elf = elfindex;
        }   
        
      }
      input.close(); //close the file object.
      cout << "Max total calorie: " << max_totalcalorie << " Max total calorie elf: " << max_calorie_elf << endl;
      int totalmax3 = 0;
      for (auto i: max3calories) {
        cout << i << ' ';
        totalmax3 += i; 
      }
      cout << totalmax3;
   }
}

