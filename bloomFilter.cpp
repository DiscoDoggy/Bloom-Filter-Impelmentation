#include "bloomFilter.h"

int bloomFilter::hashFunc1(int val) {
  int hash = val % bloomSize;
  return hash;
}

int bloomFilter::hashFunc2(int val) {
  int hash = ((val+1)*3) % bloomSize;
  return hash;
}

void bloomFilter::bloomFilterInsert(int val) {
  int h1 = hashFunc1(val);
  int h2 = hashFunc2(val);

  bit[h1] = 1;
  bit[h2] = 1;
}

void bloomFilter::printVec() {
  cout << bit.to_string<char,std::string::traits_type,std::string::allocator_type>();
}

bloomFilter::bloomFilter() {
  bloomSize = 2048;
  numHashes = 2;
}

bool bloomFilter::check(int val) {
  int h1 = hashFunc1(val);
  int h2 = hashFunc2(val);
  
  if (bit[h1] == 1 && bit[h2] == 1)
    return true;
  return false;
}

