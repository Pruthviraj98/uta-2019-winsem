#include<iostream>
#include<queue>
using namespace std;

void BFS(int**edges, int n, int SV){
	bool visited[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	visited[SV]=true;
	queue<int> pending;
	pending.push(SV);
	while(!pending.empty()){
		int currentVertex=pending.front();
		pending.pop();
		for(int i=0;i<n;i++){
			if(i==currentVertex){
				continue;
			}
			if(edges[currentVertex][i]==1 && visited[i]!=true){
				pending.push(i);
				visited[i]=true;
			}
		}
	}
	delete []visited; 
}

void DFS(int** edges, int n, int SV, bool* visited){
	cout<<SV<<endl;
	visited[SV]=true;
	
	for(int i=0;i<n;i++){
		
		if(i==SV){
			continue;
		}
		if(edges[SV][i]==1){
			if(visited[i]==true){
				continue;
			}
			DFS(edges, n, i, visited);
		}
		
	}
}


int main(){
	int n;
	int e;
	cin>>n>>e;
	
	int** edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	
	for(int i=0;i<e;i++){
		int f, s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;		
	}
	
	//////////////////////////
	BFS(edges, n, 0);
	//////////////////////////
	
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
}
