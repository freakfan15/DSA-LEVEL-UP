/* Given an array and a sum. find if the array has two pairs which result i the given sum 
https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/24429114#overview
*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr, int Sum){
    //logic
    unordered_set<int> s;
    vector<int> result;

    for(int i=0; i<arr.size(); i++){

        int x = Sum - arr[i];
        if(s.find(x)!=s.end()){ //if x is found in the unordered setn
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }

        //insert the current number inside the set
        s.insert(arr[i]);

    }

    return {}; //return empty vector if no pair is found
}

int main(int argc, char const *argv[])
{
    
    vector<int> arr{10,5,2,3,-6,9,11};
    int sum = 4;

    auto p = pairSum(arr, sum);

    if(p.size()==0){
        cout<<"No such pair"<<endl;
    }
    else{
        cout<<p[0]<<","<<p[1]<<endl;
    }

    return 0;
}