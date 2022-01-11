#include <iostream>
#include <vector>
using namespace std;


int rotatedSearch(vector<int> &arr, int key){
    int n = arr.size();
    int s = 0, e = n-1;
    
    while(s<=e){
        int m = (s+e)/2;
        if(arr[m]==key){
            return m;
        }
        else if(arr[s]<=arr[m]){
            //means left part is sorted
            if(arr[s]<=key and arr[m]>=key){
                //means key lies in left part
                e = m - 1;
            }
            else{
                //key does not lie in left part->search in right part
                s = m + 1;
            }
        }
        else{
            //left is not sorted->right is sorted
            if(arr[m]<=key and arr[e]>=key){
                //means key lies in right part
                s = m + 1;
            }
            else{
                //search in left part
                e= m - 1;
            }
        }
    }
    return -1;

}

int main()
{

    vector<int> arr{4,5,6,7,0,1,2,3};
    int n = arr.size();
    int key;
    cin>>key;
    cout<<rotatedSearch(arr, key);


return 0;

}