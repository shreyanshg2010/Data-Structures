#include <stdio.h> 
#include <string.h> 

char text[100]; 
int min(int a, int b) 
{ 
	int res = a; 
	if(b < a) 
		res = b; 
	return res; 
} 

void findLongestPalindromicString() 
{ 
	int N = strlen(text); 
	if(N == 0) 
		return; 
	N = 2*N + 1; //Position count 
	int L[N]; //LPS Length Array  
	int C = 0; //centerPosition 
	int R = 0; //centerRightPosition 
	int i = 0; //currentRightPosition 
	int iMirror; //currentLeftPosition 
	int maxLPSLength = 0; 
	int maxLPSCenterPosition = 0; 
	int start = -1; 
	int end = -1; 
  memset(L,0,sizeof(L));
	for (i = 1; i < N; i++) 
	{ 
		iMirror = 2*C-i;  
		if(R-i > 0) 
			L[i] = min(L[iMirror], R-i); 
		while ( ((i + L[i]) < N && (i - L[i]) > 0) && 
			( ((i + L[i] + 1) % 2 == 0) || 
			(text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] ))) 
		{ 
			L[i]++; 
		} 

		if(L[i] > maxLPSLength) // Track maxLPSLength 
		{ 
			maxLPSLength = L[i]; 
			maxLPSCenterPosition = i; 
		} 

		if (i + L[i] > R) 
		{ 
			C = i; 
			R = i + L[i]; 
		} 
	} 
	start = (maxLPSCenterPosition - maxLPSLength)/2; 
	end = start + maxLPSLength - 1; 
	printf("LPS of string is %s : ", text); 
	for(i=start; i<=end; i++) 
		printf("%c", text[i]); 
	printf("\n"); 
} 

int main() 
{ 

	strcpy(text, "babcbabcbaccba"); 
	findLongestPalindromicString(); 


	return 0; 
} 
