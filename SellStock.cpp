#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    vector<int> max_prices;
    int ans=0;
    for(int i=prices.size()-1; i>0; i--){
        if(i==prices.size()-1 || prices[i]>max_prices.back())
            max_prices.push_back(prices[i]);
        else
            max_prices.push_back(max_prices.back());
    }
    for(int i=0; i<(int)prices.size()-1; i++){
        if((max_prices[max_prices.size()-i-1]-prices[i])>ans)
            ans = max_prices[max_prices.size()-i-1]-prices[i];
    }
    return ans;
}
    
int main(){
  vector<int> arr(1440,0);
  for(int i=0; i<1440; i++){
    arr[i] = i%20;
  }
  cout << maxProfit(arr) << endl;
  return 0;
}
