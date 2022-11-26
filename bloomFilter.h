#ifndef BLOOM_FILTER.H
#define BLOOM_FILTER.H

#include <iostream>
#include <bitset>

using namespace std;
/*
bloomFilter(); - default constructor

bloomFilter(int cust_num_vals); allows user to enter how many values will be inside of the bloom filter so other functions can calculate the optimal number of hashes and filter size

bloomFilter(int cust_num_vals, int cust_bloom_sz, int cust_num_hashes, int cust_num_vals); allows for user to enter all the parameters they want to.

bloomFilterInsert(int value) takes in a value and inserts the correct 1s into bloom filter

bloomDoesExist returns true if value might exist and false if it is not found

~~~~
bloomVec is the bit array/vector that can be sized with resize from within a constructor
numHashes is the number of hashes that will be performed on an input
numVals is how many values are stored in the bloom filter
hashFunc1 is a hash function
hashFunc2 is another unique hash function

~~~~
-Could add functions that calculate error rate
-We could demonstrate false positive with stress test
-could add more hash functions
*/


class bloomFilter {
	public:
		bloomFilter();
		//bloomFilter(int cust_num_vals);
		// bloomFilter(int cust_num_vals, int cust_bloom_sz, int cust_num_hashes, int cust_num_vals); 

		void bloomFilterInsert(int value);
		bool check(int value);
    void printVec(); //testing function, you can remove in final product
	private:
		//vector<int> bloomVec;
		int bloomSize;
		int numHashes;
		//int numVals; 
		int hashFunc1(int value);
		int hashFunc2(int value);
		bitset<2048> bit;

};
#endif