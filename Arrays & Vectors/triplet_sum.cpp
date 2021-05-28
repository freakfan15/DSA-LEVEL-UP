#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int targetSum){
	int n = arr.size();
	vector<vector<int>> result;

	//sorting the array as below algo works only on sorted array
	sort(arr.begin(), arr.end());

	for(int i = 0; i<=n-3; i++){
		int j = i+1;
		int k = n-1;
		while(j<k){
			int currSum = arr[i];
			currSum+= arr[j] + arr[k];

			if(currSum==targetSum){
				result.push_back({arr[i],arr[j],arr[k]});
				j++;
				k--;
			}
			else if(currSum<targetSum){
				j++;
			}
			else{
				k--;
			}
		}
	}
	return result;	
}

int main(int argc, char const *argv[])
{
	
	vector<int> arr{1,2,3,4,5,6,7,8,9,15};
	int sum = 18;

	auto result = triplets(arr,sum);	

	for(auto v:result){
		for(auto no:v){
			cout<<no<<",";
		}
		cout<<endl;
	}

	return 0;
}