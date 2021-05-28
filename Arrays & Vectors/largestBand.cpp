#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int largestBand(vector<int> arr){
	int n = arr.size();
	unordered_set<int> s;
	//insert data inside a set
	for(int v:arr){
		s.insert(v);
	}

	int largestLen = 1;
	for(auto element:s){
		int parent = element - 1;
		if(s.find(parent)==s.end()){ //means parent is not found
			//find entire band / chain starting from this element
			int next_no = element + 1;
			int cnt = 1;

			while(s.find(next_no)!=s.end()){ // meaning next_no exists in set
				next_no++;
				cnt++;
			}
			largestLen = max(largestLen, cnt);
		}


	}
	return largestLen;

}


int main(int argc, char const *argv[])
{
	vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};
	cout<<largestBand(arr)<<endl;


	return 0;
}