#include<iostream>
#include <vector>

using namespace std;

/*
Time: O(logn)
*/

int itCount(vector<int> arr){
  int begin, end;
  begin=0; end=arr.size()-1;
  int mid;
  while(begin <= end){
    mid=(begin+end)/2;
    if(arr[mid]==0 && (mid==arr.size()-1 || arr[mid+1]==1))
      return mid+1;
    if(arr[mid]==0){
      begin=mid+1;
    }
    else{
      end=mid-1;
    }
  }
  return 0;
}

int recursive(vector<int> arr, int begin, int end){
  if(begin>end)
    return 0;
  int mid=(begin+end)/2;
  if(arr[mid]==0 && (mid==arr.size()-1 || arr[mid+1]==1))
    return mid+1;
  if(arr[mid]==0)
    return recursive(arr, mid+1, end);
  return recursive(arr, begin, mid-1);
}

int recCount(vector<int> arr){
  return recursive(arr, 0, arr.size()-1);
}

int main(){
  vector<int> arr({});
  cout<< itCount(arr) << endl;
  cout<< recCount(arr) << endl;
  return 0;
}
