//https://stackoverflow.com/questions/11763590/bfs-implementation

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Adding node pair of a Edge in Undirected Graph 
void addEdge( vector<int> adj[], int u, int v){
    adj[u].push_back(v);  // 1st push_back
    adj[v].push_back(u);  //2nd push_back
    //for Directed Graph use only one push_back i.e., 1st push_back() rest is same 
}
//Traversing through Graph from Node 0 in Adjacency lists way
void showGraph( vector<int>adj[], int N){
    cout<<"Graph:\n";
    for(int i=0; i<N ; i++){
        cout<<i;
        for( vector<int>::iterator itr= adj[i].begin() ; itr!=adj[i].end(); itr++){
        cout<<" -> "<<*itr;
    }
    cout<<endl;
}
}
//Prints Array elements
void showArray(int A[]){
    for(int i=0; i< 7; i++){
        cout<<A[i]<<" ";
    }
}

void BFS( vector<int>adj[], int sNode, int N){

    //Initialization
    list<int>queue; 	//Queue declaration
    int color[N]; 		//1:White, 2:Grey, 3:Black
    int parentNode[N];  //Stores the Parent node of that node while   traversing, so that you can reach to parent from child using this 
    int distLevel[N];   //stores the no. of edges required to reach the node,gives the length of path

    //Initialization
    for(int i=0; i<N; i++){
        color[i] = 1;   	//Setting all nodes as white(1) unvisited
        parentNode[i] = -1; //setting parent node as null(-1)
        distLevel[i] = 0; //initializing dist as 0
    }

    color[sNode] = 2;  		 //since start node is visited 1st so its color is grey(2)
    parentNode[sNode] = -1;  //parent node of start node is null(-1)
    distLevel[sNode] = 0;    //distance is 0 since its a start node
    queue.push_back(sNode);  //pushing start node(sNode) is queue

    // Loops runs till Queue is not empty if queue is empty all nodes are visited
    while( !queue.empty()){

    int v = queue.front();  //storing queue's front(Node) to v
    queue.pop_front();//Dequeue poping element from queue

    //Visiting all  nodes connected with v-node in adjacency list
    for(int i=0; i<adj[v].size() ;i++){

        if( color[ adj[v][i] ] == 1){// if node is not visited, color[node]==1  which is white 
            queue.push_back(adj[v][i]);  //pushing that node to queue
            color[adj[v][i]]=2;  //setting as grey(2)
            parentNode[ adj[v][i] ] = v; //parent node is stored    
			distLevel[ adj[v][i] ] = distLevel[v]+1;  //level(dist) is incremented y from dist(parentNode)            
        }
    }//end of for
    color[v]=3;
    //queue.pop_front();//Dequeue
	}

	printf("\nColor: \n");showArray(color);
	printf("\nDistLevel:\n");showArray(distLevel);
	printf("\nParentNode:\n");showArray(parentNode);
}

int main(){

	int N,E,u,v;//no of nodes, No of Edges, Node pair for edge
	cout<<"Enter no of nodes"<<endl;
	cin>>N;
	vector<int> adj[N];  //vector adjacency lists
	
	cout<<"No. of edges"<<endl;
	cin>>E;
	
	cout<<"Enter the node pair for edges\n";
	for( int i=0; i<E;i++){
	    cin>>u>>v;
	    addEdge(adj, u, v);  //invoking addEdge function
	}
	
	showGraph(adj,N);  //Printing Graph in Adjacency list format
	BFS(adj,0,N);  //invoking BFS Traversal
}
