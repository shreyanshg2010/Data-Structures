A group of friends want to buy a bouquet of flowers. The florist wants to maximize his number of new customers and the money he makes. 
To do this, he decides he'll multiply the price of each flower by the number of that customer's previously purchased flowers plus 1.
The first flower will be original price,(0+1)*original price , the next will be (1+1)*original price and so on.

Given the size of the group of friends, the number of flowers they want to purchase and the original prices of the flowers, determine the minimum cost to purchase all of the flowers.

Sample Input 0

3 3
2 5 6
Sample Output 0

13

Sample Input 1

3 2
2 5 6
Sample Output 1

15

Sample Input 2

5 3
1 3 5 7 9
Sample Output 2

29



#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
} 
int main(){
    int i,N,k;
    int c[102],res=0,j=0;
    scanf("%d%d",&N,&k);
    int visit[k];
    for(i=0;i<N;i++)
    scanf("%d",&c[i]);
    for(i=0;i<k;i++)
    visit[i]=0;
    qsort(c,N, sizeof(int), compare);
    for(i=N-1;i>=0;i--){
        res=res+(visit[j]+1)*c[i];
        visit[j]++;
        j=(j+1)%k;
    }
    printf("%d",res);
    return 0;
}


