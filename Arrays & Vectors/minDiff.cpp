#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    int minDiff = INT_MAX;
    pair<int, int> p; 

    for(int i =0 ; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            int diff = abs(a[i]-b[j]);
            if(diff < minDiff){
                p = make_pair(a[i], b[j]);
            }
            minDiff = min(minDiff, diff);

        }
    }
    
    return p;
    
}

int main(int argc, char const *argv[])
{
    vector<int> a{23,5,10,17,30};
    vector<int> b{26,134,135,14,19};

    pair<int,int> result = minDifference(a,b);

    cout<<result.first<<", "<<result.second<<endl;

    return 0;
}