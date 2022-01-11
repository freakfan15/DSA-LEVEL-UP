#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int s, int e){
    vector<int> temp;
    int mid = (s+e)/2;
    int i=s, j=mid+1;
    while(i<=mid and j<=e){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    //copy rest of the elements
    while(i<=mid){
       temp.push_back(arr[i++]); 
    }
    while(j<=e){
        temp.push_back(arr[j++]);
    }

    //Copy elements from temp array to original array
    int k = 0;
    for(int idx=s; idx<=e; idx++){
        arr[idx] = temp[k++];
    }
}

void mergeSort(vector<int> &arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr,s,e);
}

int main()
{

    vector<int> arr{10,5,2,0,7,6,4};
    int n = arr.size();
    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<" ";
    }

return 0;

}