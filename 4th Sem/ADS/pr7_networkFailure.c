#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define MAX 10
int main()
{
 printf("\nName:ANUP TARONE\nRoll no. : 36\nReg. no. : 20010766\n");
 printf("\n");
 int adj[MAX][MAX];
 int i=0, mask, j, start, n, v;
 int a[50], visited[MAX] = {0};
 int que[MAX]={-1};
 int f=-1, r=-1, k;
 FILE *fp;
 fp = fopen("vertex.txt","r");
 if(fp == NULL)
 {
 printf("\nError in Opening the File\n");
 exit(0);
 }
 else
 {
 while(fscanf(fp,"%d\t",&a[i])!=EOF)
 {
 printf("%d ",a[i]);
 i++;
 }
 }
 printf("\n");
 n = sqrt(i+1);
 printf("\nNo. of Vertices in Graph are: %d\n",n);
 k = 0;
for(i=0; i<n; i++)
 {
 for(j=0; j<n; j++)
 {
 adj[i][j] = a[k];
 k++;
 }
 }
 printf("\n\t\tADJACENCY MATRIX\n");
 for(i=0; i<n; i++)
 {
 for(j=0; j<n; j++)
 {
 printf("%d\t",adj[i][j]);
 }
 printf("\n");
 }
 k = 0;
 start = rand()%n;
 for(mask=0; mask<n; mask++)
 {
 k = 1;
 if(start == mask)
 {
 start = (start+1)%n;
 printf("\nMasked Node is %d", mask);
 }
 visited[mask] = 1;
 visited[start] = 1;
 que[++r] = start;
 while(f<r)
 {
 v = que[++f];
 for(j=0; j<n; j++)
 {
 if(adj[v][j] == 1 && visited[j] == 0)
 {
 que[++r] = j;
 k++;
 visited[j] = 1;
 }
 }
 }
 if(k< n-1)
 {
 printf("\nGraph is not biconnected and the failure node is %d", mask);
 break;
}
 else
 {
 for(j=0,k=0; j<n,k<n; j++,k++)
 {
 visited[j] = 0;
 que[k] = -1;
 }
 f=-1;
 r=-1;
 }
 }
 if(mask == n)
 printf("\nNo single failure node and Graph is biconnected");
 return 0;
}