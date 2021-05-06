#include<stdio.h>
#include <time.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v) {
	for (i=1;i<=n;i++)
	  if(a[v][i] && !visited[i])
	   q[++r]=i;
	if(f<=r) {
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}
void main() {
	int v;
    clock_t start, end;

	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		q[i]=0;
		visited[i]=0;
	}
	printf("\nEnter the adjacency matrix form:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
    start = clock();
	bfs(v);
    end = clock();
    float ti = ((double)(end - start)/CLOCKS_PER_SEC);
	for (i=1;i<=n;i++){
	  if(visited[i])
	   printf("the node %d is reachable\n",i);
    else
        printf("The node %d is not reachable\n",i);
    }
    printf("\nTime taken: %f", ti);
}
