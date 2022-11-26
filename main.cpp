#include <iostream>
#include <vector>

#include "bloomFilter.h"

using namespace std;

int main() {
	vector<int> data = {0,4,7,10,13,17,21,25,27,33,39,44,47,49,50,54,
  58,62,66,69,71,74,79,82,94};
  double counter = 0;
  bloomFilter *bloom = new bloomFilter();
  //intializing bloom with the values from data 
  for (unsigned i = 0; i < data.size(); i++) {
    bloom->bloomFilterInsert(data.at(i));
  }
  //checking to see if 1-100 are in bloom
  int test = 100;
  for (unsigned i = 0; i < test; i++) {
    if (bloom->check(i)==1){
   //cout << i << " is PROBABLY in the database" << endl;
    counter++;
    }
    //else
     //cout << i << " is DEFINITELY NOT in the database" << endl;
  }
  cout << "Tested set: " << test << endl;
  cout << "False Positive Rate: " << (counter-data.size())/(test) * 100 << "%" << endl;
  cout << "True Positives/All Positives: " << data.size()/counter * 100 << "%";
}