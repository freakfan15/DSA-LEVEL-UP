#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};

    //logic
    int index = big.find(small);

    while(index!=-1){
        result.push_back(index);
        index = big.find(small, index+1);
    }

    return result;

}

int main(int argc, char const *argv[])
{
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";

    vector<int> arr;

    arr = stringSearch(bigString, smallString);

    for(auto v: arr){
        cout<<v<<", ";
    }

    return 0;
}
