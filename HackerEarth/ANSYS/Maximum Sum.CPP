Problem Statement:

You are provided with a matrix of N*M containing integer values A[i][j]. Your task is to select exactly one integer from each row such that the sum of these integers is maximum. A constraint is imposed on the values that are selected. The matrix is divided into two equal halves based on the number of columns (M is even).

You are not allowed to select two integer values of adjacent rows in the same half. Therefore, if A[i][j] belongs to the first half then A[i+1][k] should belong to the second half. Your task is to determine the maximum sum possible.

Input Format: First line: T represents the number of test cases
For each test case:
First line: Two space-separated integers N and M
Next N lines: M space-separated integers denoted by A[i][j]

Output Format:
For each test case, print a single integer denoting the maximum sum possible.

Constraints:

1 < T < 100  
1 <= N, M <= 500, M is even  
1 <= A[i][j] <= 10^6  

Sample Input:

1
4 4
10 15 2 5
20 4 14 12
10 11 10 2
2 3 4 5

Sample Output:

45


My Code
--------
int solve (vector<vector<int> > A){
    int maxSum1=0;
    for(int i=0;i<A.size();i++){
        int tmpMax=-9999;
        if(i%2==0){
            for(int j=0;j<A[i].size()/2;j++){
                if(A[i][j]>tmpMax){
                    tmpMax=A[i][j];
                }
            }
        }else{
            for(int j=A[i].size()/2;j<A[i].size();j++){
                if(A[i][j]>tmpMax){
                    tmpMax=A[i][j];
                }
            }
        }
        maxSum1+=tmpMax;
    }
    int maxSum2=0;
    for(int i=0;i<A.size();i++){
        int tmpMax=-9999;
        if(i%2!=0){
            for(int j=0;j<A[i].size()/2;j++){
                if(A[i][j]>tmpMax){
                    tmpMax=A[i][j];
                }
            }
        }else{
            for(int j=A[i].size()/2;j<A[i].size();j++){
                if(A[i][j]>tmpMax){
                    tmpMax=A[i][j];
                }
            }
        }
        maxSum2+=tmpMax;
    }
    if(maxSum1>maxSum2){
        return maxSum1;
    }
    else{
        return maxSum2;
    }
}
