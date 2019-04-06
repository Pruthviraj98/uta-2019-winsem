#include<iostream>
#include<queue>
using namespace std;

void printBFS(int** edges, int n, int SV, bool* visited){
	queue<int>pending;
	pending.push(SV);
	
	while(!pending.empty()){
		int currentVertex=pending.front();
		pending.pop();
		cout<<currentVertex;
		for(int i=0;i>n;i++){
			if(i==currentVertex){
				continue;
			}
			if(edges[currentVertex][i]==1 && visited[i]!=true){
				pending.push(i);
				visited[i]=true;
			}
		}
	}
}

void BFS(int** edges, int n){
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(visited[i]){
			continue;
		}
		printBFS(edges, n, i, visited);
	}
	delete []visited;
}

void printDFS(int** edges, int n, int SV, bool* visited){
	cout<<SV<<endl;
	visited[SV]=true;
	
	for(int i=0;i<n;i++){
		if(i==SV){
			continue;
		}
		if(edges[SV][i]==1){
			if(visited[i]){
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}
}

void DFS(int** edges, int n){
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(visited[i]){
			continue;
		}
		printDFS(edges, n, i, visited);
	}
	delete[] visited;
}

int main(){
	int n, e;
	cin>>n>>e;
	int** edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	
	for(int i=0;i<e;i++){
		int fv;
		int sv;
		cin>>fv>>sv;
		edges[fv][sv]=1;
		edges[sv][fv]=1;
	}
	
	DFS(edges, n);
	BFS(edges, n);
	
	for(int i=0;i<n;i++){
		delete[] edges[i];
	}
	delete [] edges;
}
