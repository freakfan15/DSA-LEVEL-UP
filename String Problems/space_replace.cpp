#include<iostream>
#include<cstring>
using namespace std;

string space_replace(char *s){

	int spaces = 0;
	for(int i = 0; s[i]!='\0'; i++){
		if(s[i]==' '){
			spaces += 1;
		}
	}
	
	int idx = strlen(s) + 2*spaces;
	s[idx] = '\0';

	for(int i = strlen(s)-1; i>=0; i--){
		if(s[i]==' '){
			s[idx-1] = '0';
			s[idx-2] = '2';
			s[idx-3] = '%';
			idx = idx -3;
		}
		else{
			s[idx-1] = s[i];
			idx--;
		}
	}
	
	return s;

}

int main(int argc, char const *argv[])
{
	char input[1000];
	cin.getline(input, 1000);

	space_replace(input);

	cout<<input<<endl;

	return 0;
}