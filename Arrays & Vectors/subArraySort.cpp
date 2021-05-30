#include<iostream>
#include <climits>
#include<algorithm>
#include<vector>

using namespace std;

bool outOfOrder(vector<int> arr, int i){
	int x = arr[i];

	if(i==0){
		return x > arr[1];
	}
	else if(i==arr.size()-1){
		return x < arr[i-1];
	}

	return x > arr[i+1] or x < arr[i-1];
}

pair<int,int> subArraySort(vector<int> arr){
	int smallest = INT_MAX;
	int largest = INT_MIN;
	int n = arr.size();

	for(int i =0; i<n; i++){
		int x = arr[i];
		if(outOfOrder(arr, i)){
			smallest = min(smallest, x);
			largest = max(largest, x);
		}
	}

	if(smallest == INT_MAX){
		return {-1,-1};
	}

	//finding the right index where smallest and largest element lies for the subarray
	int left = 0; //left index
	while(smallest>= arr[left]){
		left++;
	}
	int right = n-1;
	while(largest<= arr[right]){
		right--;
	}

	return {left, right};

}

int main(int argc, char const *argv[])
{
	
	vector<int> arr{1,2,3,4,5,8,6,7,9,10,11};

	auto p = subArraySort(arr);
	cout<<p.first<<" and "<<p.second<<endl;

	return 0;
}