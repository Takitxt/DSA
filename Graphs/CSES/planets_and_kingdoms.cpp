#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
  public:
    void dfs1(const vector<vector<int>> &adj, int u, vector<int> &vis, stack<int> &stk) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs1(adj, v, vis, stk);
            }
        }
        stk.push(u);
    }

    void dfs2(const vector<vector<int>> &rev, int u, vector<int> &vis, vector<int> &comp, int id) {
        vis[u] = true;
        comp[u] = id;
        for (int v : rev[u]) {
            if (!vis[v]) {
                dfs2(rev, v, vis, comp, id);
            }
        }
    }

    int kosaraju(const vector<vector<int>> &adj, vector<int> &comp) {
        int n = static_cast<int>(adj.size()) - 1;
        vector<int> vis(n + 1, false);
        stack<int> stk;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs1(adj, i, vis, stk);
            }
        }

        vector<vector<int>> rev(n + 1);
        for (int u = 1; u <= n; u++) {
            for (int v : adj[u]) {
                rev[v].push_back(u);
            }
        }

        vector<int> vis2(n + 1, false);
        int count = 0;
        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();
            if (!vis2[u]) {
                count++;
                dfs2(rev, u, vis2, comp, count);
            }
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    Solution s;
    vector<int> comp(n + 1, 0);
    int k = s.kosaraju(adj, comp);

    cout << k << "\n";
    for (int i = 1; i <= n; i++) {
        cout << comp[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}