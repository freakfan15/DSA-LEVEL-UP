#include<iostream>
#include<vector>

using namespace std;

int maxSubarraysum(vector<int> arr){
	int n = arr.size();
	int res = arr[0];
	int maxEnding = arr[0];

	for(int i = 1; i<n; i++){
		maxEnding = max(maxEnding + arr[i], arr[i]);
		res = max(res, maxEnding);
	}

	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> arr{-1,2,3,4,-2,6,-8,3};

	cout<<maxSubarraysum(arr)<<endl;

	return 0;
}