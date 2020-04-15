#include <iostream>
#include <vector>
#include<map>

using namespace std;

void Sum(vector<int> v, int n){
    map<int, int> ans;
    for(int i=0; i<v.size(); i++){
        int el=v[i];
        int tar=n-el;
        for(int j=i+1; j<v.size(); j++){
            if(v[j]==tar && ans[v[j]]==0 && ans[v[i]]==0){
                ans[v[j]]++;
                cout << "(" << el << ", " << v[j] << ")" << endl;
            }
        }
    }
}

int main(){
  Sum({1,3,1,3,2,2}, 4);
  return 0;
}
