// Quick sort in C++

#include <iostream>
#include <vector>
using namespace std;

// function to swap elements
void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

void printArray(vector<int>& data){
  for(auto& t : data){
    cout << t << " ";
  }
  cout << endl;
}


int partition(vector<int>&nums, int left, int right){
  int p = right;
  int i = left ; // i poits the potential pivot position
  for(int j=left; j<right; j++){
    if(nums[j] <= nums[p]){
      
      swap(nums[i], nums[j]);
      i++;
    }
  }
  swap(nums[i],nums[p]);
  return i;
}

void quickSort (vector<int>& nums, int left, int right){
  if(left < right){
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot-1);
    quickSort(nums, pivot+1,right);
  }
}

// Driver code
int main() {
 
  vector<int> data = {8, 7, 6, 1, 0, 9, 2,6,2};
  int n = data.size() -1;
  cout << "Unsorted Array: \n";
  printArray(data);
  
  // perform quicksort on data
  quickSort(data, 0, n );
  
  cout << "Sorted array in ascending order: \n";
  printArray(data);
}