#include<iostream>
#include<stdlib.h>
using namespace std;
int G[10][10];
int V;
int length[10];
int set[10],k,s;

int searchMin(){
	int m = 10000,index;
	for(int l = 0;l < V;l++){
		if(set[l] == 0 && length[l] <= m){
			m = length[l];
			index = l;		
		}
	}
	return index;
}

int main(){
	int i,j;
	cout << "Dijkstra Algorithm\n\n";
	cout << "Enter number of vertices of graph\n";
	cin >> V;
	cout << "Enter graph matrix element\n";
	for(i = 0;i < V;i++){
		for(j = 0;j < V;j++){
			cin >> G[i][j];
		}
	}
	cout << "Enter the source vertex e.g(1 2 3 ....)\n";
	cin >> s;
	
	//Initialization
	for(i = 0;i < V;i++){
		length[i] = 10000;
		set[i] = 0;
	}
	length[s - 1] = 0;
	
	for(i = 0;i < V;i++){
		k = searchMin();
	    set[k] = 1;
	    for(int n = 0;n < V;n++){
	    	if(G[k][n] != 0 && set[n] != 1 && length[n] > (length[k] + G[k][n])){
	    		length[n] = length[k] + G[k][n];
			}
		}
	}
	
	//printing
	for(i = 0;i < V;i++){
		cout << "Vertex : " << i + 1 << " -> " << length[i] << "\n";
	}
	return 0;
}
