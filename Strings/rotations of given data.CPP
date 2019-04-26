#include<bits/stdc++.h> 
using namespace std; 
void printRotatedString(char str[]) 
{ 
	int n = strlen(str); 

	char temp[2*n + 1]; 
	strcpy(temp, str); 
	strcat(temp, str); 
	for (int i = 0; i < n; i++) 
	{ 
		for (int j=0; j != n; j++) 
			printf("%c",temp[i + j]); 
		printf("\n"); 
	} 
} 

int main() 
{ 
	char str[100]; 
  cin>>str;
	printRotatedString(str); 
	return 0; 
} 
