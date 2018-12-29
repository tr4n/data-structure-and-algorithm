#include<iostream> 
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#define MAX_vertexS 1998
#define MAX_VALUE 999999999
#define NUM_vertexS (int)(height * width)
using namespace std; 


//int directX[] = {0, -1, -1, -1, 0, 1 , 1 , 1};
//int directY[] = {1, 1, 0, -1, -1, -1, 0, 1};


int directX[] = {0, -1, 0, 1};
int directY[] = {1, 0, -1, 0};

int width = 3, height = 3; 
int startX, startY, targetX, targetY ;  
typedef pair<int, int> edge; 
vector <edge> edgeList[MAX_vertexS] ; 
int d[MAX_vertexS];

inline bool isInBoard(int x, int y , int height, int width){
	return ((x >= 0 && x < height && y >= 0 && y < width));
}
inline int distance (int a, int b, int x, int y){
	return (int) (100*sqrt((x-a)*(x-a) + (y-b)*(y-b)));
}
inline int vertex(int x, int y, int width){
	return (int)(x * width + y);
}


int Dijkstra(int start, int target){
	priority_queue <edge, vector<edge>, greater<edge> > priorityQueue;
    

    for(int i = 0 ;i < NUM_vertexS ;i ++) d[i] = MAX_VALUE; 
    d[start] = 0;
    priorityQueue.push(edge(0, start));

    while (!priorityQueue.empty()){
    	
    	int u=priorityQueue.top().second;
        int  du=priorityQueue.top().first;
        priorityQueue.pop();
        if (du!=d[u]) continue;

        for (int i=0; i < edgeList[u].size() ; i++)
        {
        	int v=edgeList[u][i].second;
            int uv = edgeList[u][i].first;
            if (d[v]>du+uv) {
                d[v]=du+uv;
                priorityQueue.push(edge(d[v], v));
            }
        }
    }
    
    return d[target];
}



main(){
	/*
	
	printf("Enter size of map(Height x Width): ");
	scanf("%d%d", &height, &width);
	printf("Enter start point(startX, startY) = ");
	scanf("%d%d", &startX, &startY);
	printf("Enter start point(startX, startY) = ");
	scanf("%d%d", &targetX, &targetY);	
		printf("Enter map (1 : box , 0 : space) : \n");
	
	int map[height +3 ][width +3];	
	
	for(int i = 0 ;i < height ;i ++){
		for(int j =0 ;j < width ;j ++){
			scanf("%d", &map[i][j]);
		}
	}
	*/
	
	
	height = width = 5; 
	int map[6][6] = {
		{0, 1, 0, 1, 0},
		{0, 0, 1, 0, 1},
		{1, 0, 0, 0, 1},
		{0, 0, 1, 0, 0},
		{1, 0, 1, 1, 0},	
	
	};
	startX = startY = 0; 
	targetX = targetY = 4; 
	printf("Height = 5, Width = 5 \n"); 
	printf("Start : S(0,0) --> Target : T(4,4)\n");
	
	for(int i = 0 ;i < height ;i ++){
		for(int j = 0 ;j < width ;j ++){
			if(i == startX && j == startY){
				printf(" S");
			}else if(i == targetX && j == targetY){
				printf(" T");
			}else if(map[i][j] == 1) printf(" x");
			else printf(" .");
		}
		printf("\n");
	}
	
	

	
	
	for(int i = 0 ;i < height ;i ++){
		for(int j = 0 ;j < width ; j ++){
			int vertexA = vertex(i,j,width);
			for(int dir = 0 ; dir < 4 ; dir ++){
							
				if(map[i + directX[dir]][j + directY[dir]] == 0 
					&& isInBoard(i + directX[dir], j + directY[dir], height, width)){
									
					int distanceAB = distance(i,j, i + directX[dir], j + directY[dir]);
					int vertexB = vertex(i + directX[dir], j + directY[dir], width);					
					edgeList[vertexA].push_back(edge(distanceAB, vertexB));				
				}
				
			}
			
		}
	}
	
	cout << "Length of Path: " << 0.01 *Dijkstra(vertex(startX, startY, width), vertex(targetX, targetY,width));
	
	
	
}
