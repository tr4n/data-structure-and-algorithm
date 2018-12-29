#include<cstdio>

main()
{
	int N, M;
	
	scanf("%d%d",&M,&N);	
	
	if(N%2==0) N/=2; else N = N/2+1;
	if(M%2==0) M/=2; else M = M/2+1;
		
	printf("%lld",(unsigned long )M*N);
	
}
