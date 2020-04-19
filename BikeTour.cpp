#include<iostream>
#include<vector>

using namespace std;

int main(){
    int testcases, size;
    cin >> testcases;
    for(int i=0; i<testcases; i++){
        cin >> size;
        vector<int> checkpoints(size,0);
        for(int j=0; j<size; j++)
            cin >> checkpoints[j];
        int peaks=0;
        for(int j=1; j<size- 1; j++){
            cout << (checkpoints[j]>checkpoints[j- 1]) << endl;
            if((checkpoints[j]>checkpoints[j- 1]) 
            && (checkpoints[j]>checkpoints[j+ 1]))
                peaks++;
        }
        cout << "Case #" << i+1 
            << ": " << peaks << endl;
    }
    
    return 0;
}