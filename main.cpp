#include "VectorTemplate.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
   vector<int> nums1 = {3, 4, 1, 11, 9, 5, 6, 6};
   vector<double> nums2 = {0.0, 1.1, 4.5, 10.5, 7.7, 2.3, 4.0, 3.9};
   vector<string> strings = {"Rachel", "Ross", "Joey", "Chandler", "Monica", "Phoebe"};

   VectorTemplate<int> int_test(nums1);
   VectorTemplate<double> double_test(nums2);
   VectorTemplate<string> string_test(strings);

   //test InsertionSort:
   int_test.InsertionSort();
   unsigned int i;
   for(i = 0; i < int_test.size(); i++) {
      cout << int_test.at(i) << " ";
   }
   
   // output: 1 3 4 5 6 6 9 11
   
   cout << endl;

   double_test.InsertionSort();
   for(i = 0; i < double_test.size(); i++) {
      cout << double_test.at(i) << " ";
   }
   
   // output: 0 1.1 2.3 3.9 4 4.5 7.7 10.5
   
   cout << endl;

   string_test.InsertionSort();
   for(i = 0; i < string_test.size(); i++) {
      cout << string_test.at(i) << " ";
   }
   cout << endl;
   
   //output: Chandler Joey Monica Phoebe Rachel Ross

   //add some new elements to get it unsorted
   int_test.setVector(1);
   int_test.setVector(3);
   int_test.setVector(2);
   int_test.setVector(2);
   int_test.setVector(8);
   int_test.setVector(87);
   int_test.setVector(3);
   int_test.setVector(7);

   //test binary search for int vector
   cout << int_test.BinarySearch(1) << endl;  // 1
   cout << int_test.BinarySearch(97) << endl; // 0
   cout << int_test.BinarySearch(87) << endl; // 1
   cout << int_test.BinarySearch(3) << endl;  // 1
   cout << endl;

   //repeat for double vector
   double_test.setVector(3.14);
   double_test.setVector(2.71);
   double_test.setVector(9.8);
   double_test.setVector(7.77);

   cout << double_test.BinarySearch(2.71) << endl;        // 1
   cout << double_test.BinarySearch(1.11) << endl;        // 0
   cout << double_test.BinarySearch(10.5) << endl;        // 1
   cout << double_test.BinarySearch(11.8) << endl;        // 0
   cout << double_test.BinarySearch(1.1) << endl << endl; // 1

   //repeat for string vector
   string_test.setVector("Andy");
   string_test.setVector("April");
   string_test.setVector("Ron");
   string_test.setVector("Ben");

   cout << string_test.BinarySearch("Ron") << endl;            // 1
   cout << string_test.BinarySearch("Andy") << endl;           // 1
   cout << string_test.BinarySearch("Michael") << endl;        // 0
   cout << string_test.BinarySearch("Rachel") << endl << endl; // 1

   //test getVector()
   for(unsigned int j = 0; j < string_test.getVector().size(); j++) {
      cout << string_test.getVector().at(j) << " ";
   }
   
   //output: Chandler Joey Monica Phoebe Rachel Ross Andy April Ron Ben
   
   cout << endl;

   return 0;
}
