#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

string S[100];
int A[100],B[100];

void QuickSort(int A[], int x, int y){
	int k = x,v  = A[y] ; 
	
	for(int i =x ;i < y ; i ++){
		if(A[i]<=v){
			swap(A[i],A[k]);
			swap(S[i],S[k]);
			k++;
		}
	}
	swap(A[y],A[k]);
	swap(S[y],S[k]);
	
	if(x<k) QuickSort(A,x,k-1);
	if(k<y) QuickSort(A,k,y);
	
	
	
	
}

main()
{
	freopen("inTime.txt","r",stdin);
	freopen("outTime.txt","w",stdout);
	int N =10;
//	cin >> N; 
/*
	for(int i =1  ;i <= N ;i ++)
	{
		cin >> S[i];	
	}	
	for(int i =1 ;i <= N; i++) cin >> A[i];
	*/
	S[1]="THCD-IT1110-LTBT";
S[2]="THCD-IT1110-TN";
S[3]="NHAPMON-IT2000-LTBT";
S[4]="NHAPMON-IT2000-TN";
S[5]="CTDL-IT3010-LTBT";
S[6]="XSTK-MI2020-BT";
S[7]="QS-MIL1130-BT";
S[8]="GDTC-PE1030";
S[9]="VLDC-PH1130-BT";
S[10]="VLDC-PH1130-TN";

for(int i =1 ;i <= 100 ;i ++) B[i] = 0;
A[1]=97451;
A[2]=666230;
A[3]=97450;
A[4]=666303;
A[5]=97583;
A[6]=97464;B[6]= 97465;
A[7]=97219;B[7]=92983;
A[8]=93134;
A[9]=97467;B[9] = 97469;
A[10]=668939;

	int x; 
	while(scanf("%d",&x)!=EOF)
	{
		for(int j = 1 ;j <= N ;j ++)
		{
			if(A[j]==x|| B[j]==x)
			{
				cout << S[j] << endl;
			//	break;
			}
		}
	}
	
	
}



