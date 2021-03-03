#ifndef VECTORTEMPLATE_H
#define VECTORTEMPLATE_H

#include <vector>
#include <iostream>

template<typename T>
class VectorTemplate {
private:
   std::vector<T> vect;
public:
   VectorTemplate(std::vector<T> v) {vect = v;}
   void setVector(T val) {vect.push_back(val);} //append val to vect
   std::vector<T> getVector() {return vect;}

   long long unsigned int size() {return vect.size();}
   T at(int pos) {return vect.at(pos);}
   void erase(int first, int last) {vect.erase(vect.begin() + first, vect.begin() + last);}

   void InsertionSort() {
      unsigned int i, j;
      for(i = 1; i < vect.size(); i++) { //start at second element
         j = i;
         while(j > 0 && vect.at(i) < vect.at(j - 1)) { // ** loop backward until we find the position of the leftmost item not less than our current unsorted element, or until we get to the zeroth position
            j--;
         }
         if(j != i) { //if the item needs to be moved to the left to be sorted,
            T temp = vect.at(i);
            vect.erase(vect.begin() + i); //take out the item,
            vect.insert(vect.begin() + j, temp); //and move it to the position we found at **
         }
      }
   }

   bool BinarySearch(T val) {
      VectorTemplate<T> temp_vect(vect);
      temp_vect.InsertionSort(); //sort a copy of the instance vector

      while(temp_vect.size() > 1) {
         int mid_pos = (int)(temp_vect.size() / 2);
         if(val == temp_vect.at(mid_pos)) { //if middle element is our query element
            return true;
         }
         else {
            if(val > temp_vect.at(mid_pos)) { //if our query element will be in right half,
               temp_vect.erase(0, mid_pos); //remove left half
            }
            else {
               temp_vect.erase(mid_pos, (int)(temp_vect.size())); //if query element will be in left half, remove right half
            }
         }
         if(temp_vect.size() == 1) { //if we only have one element left, and that element is our query element, return true
            if(temp_vect.at(0) == val) {
               return true;
            }
         }
      }
      return false;
   }
};

#endif // VECTORTEMPLATE_H
