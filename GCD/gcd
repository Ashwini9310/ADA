#include<stdio.h>
#include<stdlib.h>
int r;
int GCD(int m,int n)
{
	if(n==0)
	{
		return m;
	
	}
	else
	r=m%n;
	m=n;
	n=r;
	m=GCD(m,n);
	return m;
}


void main()
{
	int m,n,i,s;
	for(;;)
	{
	printf("enter the two numbers of which gcd have to be found\n");
	scanf("%d%d",&m,&n);
	
	printf("\n1:recurccive\n2:iteration\n3:exit\n");
	printf("Enter the choice\n");
	scanf("%d",&s);
	

	

	switch(s)
	{
	
	case 1:
	m=GCD(m,n);
	printf("GCD  is %d\n",m);
	break;
	case 2:
		while(n!=0)
		{
			r=m%n;
			m=n;
			n=r;
			
		}
		printf("GCD  is %d\n",m);
		break;
		case 3:
			exit(0);
			break;
			default: printf("enter the choice correctly\n");
	}

}
}
