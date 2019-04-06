#include <iostream>
#include<queue>
using namespace std;
void checkBFS(int**edges, int n, int SV, int endV, bool* visited){

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

void checkDFS(int** edges, int n, int SV, int endv, bool* visited, bool flag=false){

  if(flag==true){
    return;
  }
  	cout<<SV<<endl;
	visited[SV]=true;
	
	for(int i=0;i<n;i++){
		

      	if(i==SV){
			continue;
		}
      
		if(edges[SV][i]==1){
          if(i==endv){
            visited[endv]=true;
            flag=true;
          }
          if(visited[i]=true){
				continue;
			}
			checkDFS(edges, n, i, endv, visited);
		}
		
	}
}

int main() {
int n, e;
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

   bool* visited=new bool[n];
    for(int i=0;i<n;i++){
      visited[i]=false;
    }  
  
  int v1, v2;
  cin>>v1>>v2;
	checkBFS(edges, n, v1, v2, visited);
  if(visited[v2]){
 	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
  	visited[i]=false;
	}  
    checkDFS(edges, n, v1, v2, visited);
  }
  if(visited[v2]){
    cout<<true;
  }else{
    cout<<false;
  }
  
  delete []visited;
  
    for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
  return 0;
}

