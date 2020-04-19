#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
/*
input: {3,7,2}
10
10%2==0
10%7==0
9
8
7%7==0
7%3==0
6
*/
int main(){
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        int size;
        double day;
        cin >> size >> day;
        vector<double> routes(size,0.);
        for(int route=0; route<size; route++)
            cin >> routes[route];
        
        double lastday=day;
        int route=routes.size()-1;
        while(route>=0){
            double mult = floor(lastday/routes[route]);
            lastday = mult*routes[route];
            route--;
        }
        
        cout << "Case #" << t << ": "
            << lastday << endl;
    }
    
    return 0;
}