#include <iostream>
#include <vector> 
#include <queue> 
#include <functional>

using namespace std; 


long long road_reperation(int n, int m, vector<vector<int>>& graph) { 
    vector<vector<pair<int,int>>> adj(n+1);   

    for(int i = 0;i<m;i++){                   
        int u = graph[i][0];
        int v = graph[i][1];
        int w = graph[i][2];
        
        adj[u].push_back({v,w}); 
        adj[v].push_back({u,w}); 
    }

    long long result = 0;                     
        
    vector<bool> vis(n+1,false);              
        
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
        
    int count = 0;                           
        
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        int dist = p.first;
        int curr = p.second;
        pq.pop();

        if(vis[curr]) continue;

        vis[curr] = true;
        result += dist;
        count++;                             
            
        for(int i =0;i<adj[curr].size();i++){
            int node = adj[curr][i].first;
            int wt = adj[curr][i].second;
                
            if(!vis[node]){
                pq.push({wt,node});
            }
        }
    }
    if(count != n) return -1;
    

                     
        
    return result;
}


int main(){
    int n ,m;
    cin>> n;
    cin>> m;

    vector<vector<int>> graph(m,vector<int>(3));

    for(int i =0;i<m;i++){                    
        cin>>graph[i][0]>>graph[i][1]>>graph[i][2];
    }

    long long ans = road_reperation(n,m,graph);

    if(ans == -1) cout<<"IMPOSSIBLE\n";       
    else cout<< ans << "\n";

    return 0;
}
