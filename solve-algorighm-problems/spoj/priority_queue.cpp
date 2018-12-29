#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

main(){
	
	priority_queue <int> pq; 
	 for(int i = 1; i<= 5 ; i++){
	 	int a ; 
	 	cin >> a; 
	 	pq.push(a);
	 }
	 
	 while(!pq.empty()){
	 	cout << pq.top()<< endl;
	 	pq.pop();
	 	
	 }
	
}

