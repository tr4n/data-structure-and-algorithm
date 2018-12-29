#include<iostream>
#include<algorithm>
#include<stack>
using namespacnumberEdgestd; 

typedef pair <int,int> ii; 
int N,M; 
int Answer = 0 ; 
int A[100][100];
int Direct[100][100];

stack<ii> Path; 


main()
{
	freopen("inDirection.txt","r",stdin);
	
	cin >> M >> N; 
	
	for(int i =1 ;i <= M ;i ++){
		for(int j =1 ;j <= N ;j++){
			
			cin >> A[i][j] ; 
		}
	}
	
	for(int i = 0 ;i <= max(M,N) ;i ++){
		
		Direct[i][0] = Direct[0][i] = 0; 
	}
	
	for(int i = 1 ;i <= M ;i ++){
		for(int j = 1;j <= N ;j ++){
			
			Direct[i][j] = A[i][j] + max(Direct[i-1][j] , Direct[i][j-1]);
		}
	}
	cout << "Answer : " << Direct[M][N] << endl;
	
	int i = M, j = N; 
	
	while(i*j ){
		
		Path.push(ii(i,j));
		if(Direct[i][j] == A[i][j] +Direct[i-1][j])		
			i--;		
		else
			j--;	
	}
	
	while(Path.size()){
		
		cout << "( " << Path.top().first << " , " << Path.top().second  << " ) "<< endl;
		Path.pop();
	}
	
	
}
