// The program is
// for adjacency matrix representation of the graph


#include <limits.h>//INT_MAX is in this header file

#include <stdio.h>




int main()
{

    int V=9;    
            
            
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };                      
                                       
         
            
            
            
     // Array to store shortest distance from source to any vertex
    int length[V];
    // array to contain the nearest predecessor of any vertex 
    int parent[V];
    // To represent set of vertices included in MST
    int set[V];
   
            
     //prototype of functions      
           
     int searchmin(int length[], int set[],int V);    
     void printSolution(int length[]);   
     void dijkstra(int graph[9][9], int length[], int set[], int parent[], int V,int s);
            
            
            
            
     dijkstra( graph , length  ,   set ,   parent , V, 0);     
    
    // Print the solution
    printSolution( length ); 
 
    return 0;
}
//-----------------------------------------------
 
// A utility function to find the vertex with minimum distance value
//from the set of vertices not yet included in shortest path tree
int searchmin(int length[], int set[],int V)
{
    // Initialize min value
    int min, min_index;
    
    min = INT_MAX;
 
    for (int v = 0; v < V; v++)
    {
        if (set[v] == 0 && length[v] < min)
        {
            min = length[v];
            min_index = v;
        }
    }
    
    return min_index;
}
 //------------------------------------------------------------------
// A utility function to print the constructed distance array
void printSolution(int length[])
{
   int  V=9;
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, length[i]);
}
 
//------------------------------------------------------------------
void dijkstra(int graph[9][9], int length[], int set[], int parent[], int V,int s)
{
    int i,j , v , u;
    
    // INITIALIZATION...
    for ( i = 0; i < V; i++)
    {
        set[i]=0;
        if (graph[s][i] == 0)   
        {     
           length[i] = INT_MAX;
           parent[i] = 0;
        }
        else
        {
           length[i]= graph[s][i];
           parent[i]=s;
        }
    }
    
    set[s]=1; //source vertex is implicitly enumerated with length as 0
    length[s]=0;
    
    //ITERATION...
    for( i= 0; i< (V-1) ;i++)
    {
       
       u=searchmin(length,set,V);
       set[u]=1;
       
       for(v=0;v< V;v++)
       {
          if((set[v]==0)&& ( graph[u][v] != 0))
          {
             if(( length[u] + graph[u][v] )  < (length[v]))
             {
                 
                 length[v]=length[u] + graph[u][v];
                 parent[v]=u;
              }
           }
        }//inner for
        
     }//outer for   
    
 
}
 
//------------------------------------------------------------------

