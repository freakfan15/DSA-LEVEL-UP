/*
Sample Input
------------
3
92 022
82 12
77 13
2 false numeric
Sample Output
-------------
82 12
77 13
92 022
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

string extractStringAtKey(string str, int key){
	char *s = strtok((char*)str.c_str(), " "); //As strtok() fn accepts char arrays so type casting str tp char*

	while(key>1){
		s = strtok(NULL, " ");
		key--;
	}
	return (string)s; //s is char* so again typecasting it back to string
}

int stringToInt(string s){
	int res = 0;
	int p = 1;
	for(int i =s.length()-1; i>=0; i--){
		res+= (s[i]-'0')*p;
		p = p*10;
	}

	return res;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2){
	string key1 = s1.second;
	string key2 = s2.second;

	return stringToInt(key1) < stringToInt(key2);
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2){
	string key1 = s1.second;
	string key2 = s2.second;
	
	return key1 < key2;	
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	cin.get(); //to consume to the extra \n

	string temp;
	vector<string> v;
	for(int i = 0; i<n; i++){
		getline(cin, temp);
		v.push_back(temp);
	}

	int key;
	string reversal, ordering;
	cin>>key>>reversal>>ordering;

	//1. Extract keys for comparison and store them
	vector<pair<string, string>> vp;

	for(int i =0; i<n; i++){
		vp.push_back({v[i], extractStringAtKey(v[i], key)});
	}

	//2. Sorting
	if(ordering=="numeric"){
		sort(vp.begin(), vp.end(), numericCompare);
	}
	else{
		sort(vp.begin(), vp.end(), lexicoCompare);
	}

	//3. Reversal
	if(reversal=="true"){
		reverse(vp.begin(), vp.end());
	}

	//4. Finally print the strings only
	for(int i=0;i<n;i++){
		cout<< vp[i].first << endl;
	}


	return 0;
}