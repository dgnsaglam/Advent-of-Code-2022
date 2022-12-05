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
    string rucksacks[3];
    vector<int> v[3];
    vector<int> v_intersection;
    vector<int> vtemp;

    int currentrucksack = 0;
    int total = 0;
    
    while (getline(input, tp))
    { 
      
      rucksacks[0] = tp;
      getline(input, rucksacks[1]);
      getline(input, rucksacks[2]);

    
    
      for (int i = 0; i < 3; i++){
        v[i].clear();
        for (int j = 0; j < rucksacks[i].size(); j++){
            int val = rucksacks[i][j];
            if (val >=97)
            val = val - 96;
            else 
            val = val - 38; 
            v[i].push_back(val);
        }

      }

      for (int i = 0; i < 3; i++){
        v[i].erase( unique( v[i].begin(), v[i].end() ), v[i].end() );
        std::sort(v[i].begin(), v[i].end());
      }

      v_intersection.clear();
      vtemp.clear();      
      std::set_intersection(v[0].begin(), v[0].end(),
                            v[1].begin(), v[1].end(),
                            std::back_inserter(vtemp));
      std::set_intersection(vtemp.begin(), vtemp.end(),
                            v[2].begin(), v[2].end(),
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
