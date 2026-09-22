class Solution {
public:

vector<int> rowCord = {0,0,1,-1};
vector<int> colCord = {1,-1,0,0};

void bfs(vector<vector<char>>& grid,int i ,int j, int n,int m){
    queue<pair<int,int>> q;
    q.push({i,j});
    grid[i][j]= '0';

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for(int z =0;z<4;z++){
            int newRow = x + rowCord[z];
            int newCol = y + colCord[z];
            if(newRow>=0 && newCol>=0 && newRow <n && newCol <m && grid[newRow][newCol]=='1'){
                q.push({newRow,newCol});
                grid[newRow][newCol] = '0';
            }
        }
    }
}


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count =0;

        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'){
                    
                    bfs(grid,i,j,n,m);
                    count++;
                }

            }
        }
        return count;
    }
};