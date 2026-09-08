#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
    public:

    bool dfs(vector<vector<int>> &adj,vector<bool> &vis,vector<int> &result,int start,int p){
        vis[start] = true;
        result.push_back(start);

        for(int i =0;i<adj[start].size();i++){
            int node = adj[start][i];
            if(!vis[node]){
                if(dfs(adj,vis,result,node,start)){
                    return true;
                }
                
            }else{
                if(node!=p){
                    int idx = -1;
                    for(int j = 0; j < result.size(); j++){
                        if(result[j] == node){
                            idx = j;
                            break;
                        }
                    }
                    if(idx != -1){
                        result.erase(result.begin(), result.begin() + idx);
                    }
                    result.push_back(node);
                    return true;
                }
            }
            
        }
        result.pop_back();
        return false;


    }


    vector<int> build_roads(int n , int m , vector<vector<int>> &edges){
        vector<vector<int>> adj(n+1);
        for(int i =0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result;
        vector<bool> vis(n+1,false);

        for(int i =0;i<n;i++){
            if(!vis[i]){
                if(dfs(adj,vis,result,i,-1)){
                    return result;
                }
            }
        }
        return result;



    }

};

int main(){

    int n; 
    int m;
    

    cin >> n;
    cin >> m;


    vector<vector<int>> edges;

    for(int i =0;i<m;i++){
        
        int u;
        int v;
        cin >> u ;
        cin >> v ; 
        edges.push_back({u,v}) ;
        
    }
    vector<int> nums = Solution().build_roads(n,m,edges);

    if(nums.size() == 0){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << nums.size() << endl;
        for(int i =0;i<nums.size();i++){
            cout << nums[i];
            if(i < nums.size()-1) cout << " ";
        }
        cout << endl;
    }
   
    return 0;
}