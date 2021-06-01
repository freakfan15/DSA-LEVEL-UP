#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string input;
	cout<<"Input String: ";
	getline(cin,input);

	//creating a sstream object and init it with input string
	stringstream ss(input); //this object acts as a buffer and we can take input or output it

	string token;
	vector<string> tokens;
	while(getline(ss,token,' ')){ //takes input from ss object and stores each word separated by space in token object
		tokens.push_back(token);
	}

	//now once we have all token(each word in input string) in tokens vector we can print all
	for(auto token:tokens){
		cout<<token<<", ";
	}



	return 0;
}