#include<iostream>
#include<cstring>
#include<vector>
using namespace std;


int main(int argc, char const *argv[])
{
	char ch[1000];
	cin.getline(ch,1000);

	//strtok()
	char *token = strtok(ch, ' ');	

	while(token!=NULL){
		cout<<token<<endl;
		token = strtok(NULL, ' ');
	}


	return 0;
}