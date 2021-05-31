#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;

	//getline function is used to take string as input
	getline(cin,s, '.'); //third parameter is a optional delimiter tells cin to stop taking input at "."
	cout<<s<<endl;

	//Also we can iterate through each character of the string
	for(char ch:s){
		cout<<ch<<", ";
	}

	//we can store multiple strings inside an array
	int  n = 5;
	vector<string> sarr;
	string temp;

	while(n--){
		getline(cin,temp);
		sarr.push_back(temp);
	}

	//Printing each String in the array
	for(string x : sarr){
		cout<<x<<", "<<endl;
	}

	return 0;
}