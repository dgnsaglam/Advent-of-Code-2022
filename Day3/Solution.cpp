#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{

  fstream input;

  input.open("input.txt", ios::in); // open a file to perform read operation using file object


  if (input.is_open())
  { // checking whether the file is open
    string tp;
    int compartment_size = 0;
    string first_compartment;
    string second_compartment;
    
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v_intersection;
 
    int currentrucksack = 0;
    int total = 0;
    
    while (getline(input, tp))
    { 
      compartment_size = tp.length() / 2;
      first_compartment = tp.substr(0,compartment_size);
      second_compartment = tp.substr(compartment_size, compartment_size);

      v1.clear();
      v2.clear();
      v_intersection.clear();

      for (int i = 0; i < compartment_size; i++){
        int val = first_compartment[i];
        if (val >=97)
          val = val - 96;
        else 
          val = val - 38; 
        v1.push_back(val);

        val = second_compartment[i];
        if (val >=97)
          val = val - 96;
        else 
          val = val - 38; 
        v2.push_back(val);
      }

      std::sort(v1.begin(), v1.end());
      std::sort(v2.begin(), v2.end());
      std::set_intersection(v1.begin(), v1.end(),
                            v2.begin(), v2.end(),
                            std::back_inserter(v_intersection));
      v_intersection.erase( unique( v_intersection.begin(), v_intersection.end() ), v_intersection.end() );
      currentrucksack = 0;
      for(int n : v_intersection){
        //std::cout << n << ' ';
        currentrucksack += n;
      }
      
      total += currentrucksack;

    }
    input.close(); // close the file object.

    cout << "Total : " << total <<  endl;

  }
}
