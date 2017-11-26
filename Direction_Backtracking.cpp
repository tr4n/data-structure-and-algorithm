#include<iostream>
#include<algorithm>
#include<cstdlib>
#define BEFORE 0
#define AFTER 1
using namespace std; 

int M,N, A[100][100];
int minValue[100][100], maxValue[100][100]; 
int Result[100], Path[100];
int numberRight = 0, numberDown = 0, numberSteps = 0;
int recentValue = 0, recentMaxValue = -1; 
int recentX = 1, recentY = 1; 
int Answer = INT_MIN; 
int number = 0 ; 
int numberDecrease = 0; 

void Init()
{
	cin >> M >> N ; 
	cout << M << " " << N << endl;
	
	for(int i = 1; i <= M ;i ++){
		for(int j =1 ; j <= N ;j ++){
			cin >> A[i][j];
			printf("%4d",A[i][j]);		
		}
		cout << endl;
	}
	
	
	
	for(int i = 0 ;i <= max(M,N) ;i ++){
		minValue[i][0] = minValue[0][i] = minValue[i][N+1] = minValue[M+1][i]=  INT_MAX; 
		maxValue[i][0] = maxValue[0][i] = maxValue[i][N+1] = maxValue[M+1][i]=  INT_MIN;
	}	
	for(int i = M;i >=1 ;i --){
		for(int j =N ;j >=1 ;j --){
			minValue[i][j] = min(A[i][j], min(minValue[i][j+1], minValue[i+1][j]));
			maxValue[i][j] = max(A[i][j], max(maxValue[i][j+1], maxValue[i+1][j]));
		}
	}
	numberSteps = M+N -2; 
	recentValue = A[1][1];
	recentMaxValue = recentValue + minValue[1][1]*(numberSteps);
}

bool checkDecrease(int i, int position){
	int x = recentX, y = recentY; 
	if(i == 0 && numberRight >= N-1 )	return false;
	if(i == 1 && numberDown >= M-1)		return false;	
	if(i == 0){
		if(recentMaxValue > recentValue + A[x][y+1] + maxValue[x][y+1]*(numberSteps - position -1))
			return false; 
	}else{
		if(recentMaxValue > recentValue + A[x+1][y] + maxValue[x+1][y]*(numberSteps - position -1))
			return false; 
	}			
	return true; 	 
}

void Decrease(int i, int position, int mode)
{
	//cout << recentValue << endl;
	if(mode == BEFORE){
			
		if(i == 0){
			numberRight ++;
			recentY ++;	
		}  
		else{
			numberDown ++;
			recentX ++;
		} 
		recentValue += A[recentX][recentY];
		recentMaxValue =max(recentMaxValue , recentValue + minValue[recentX][recentY]*(numberSteps - position -1));
						
	}else if(mode == AFTER){
		
		recentValue -= A[recentX][recentY]; 			
		if(i == 0){
			numberRight --;
			recentY--;
		}else{
			numberDown --;
			recentX --;
		}
		
		
	}

}
void Process()
{
	int x = 1,  y = 1; 
	int value = A[1][1]; 
	for(int i = 1;i <= numberSteps ;i ++){	
		if(Result[i] == 0)	y ++;
		else			x ++;
		value += A[x][y];
	}	
	
	if(value > Answer ){
		
		for(int i = 1 ;i <= numberSteps ;i ++)
		{
			Path[i] = Result[i];	
		}
		Answer = value; 
	}
	number ++;
}

void BackTrack(int position)
{
	if(position == numberSteps + 1){
		
		Process();
		return; 
	}	
	for(int i = 0 ;i <= 1; i ++){
			
		if(!checkDecrease(i,position)) {
			
			numberDecrease ++; 
			continue; 
		}
		
		Result[position] = i; 		
		Decrease(i,position,0);
		BackTrack(position + 1);
		Decrease(i,position,1);		
	}	
}

void ShowAnswer()
{
	cout <<"Answer    : " <<  Answer << endl;
	int x = 1, y = 1;
	
	cout << "Decrease  : " << numberDecrease << " times ." << endl;
	cout << "Caculate  : " << number 		<< " times." << endl;
	cout << "PATH : " << endl; 
	cout <<" (" <<  x << "," <<y << ")" << endl; 
	
	for(int i = 1;i <= numberSteps ;i ++){
		
		if(Path[i] == 0)	y ++;
		else 			x ++;
		cout << " ("<<x << "," <<y << ")| " << A[x][y] << "\n";	
	}	
}


main()
{
	freopen("inDirection.txt","r",stdin);
	Init();
	BackTrack(1);
	ShowAnswer();

	
}
