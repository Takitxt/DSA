#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Intentionally naive BFS solution for LC 947 (Most Stones Removed with Same Row or Column).
// This version is deliberately inefficient and likely to TLE on large inputs.
// It checks all stones for every popped node instead of using row/col maps.

class Solution {
public:
	int removeStones(vector<vector<int>>& stones) {
		int n = static_cast<int>(stones.size());
		if (n == 0) return 0;

		vector<int> visited(n, 0);
		int components = 0;

		for (int i = 0; i < n; ++i) {
			if (visited[i]) continue;
			components++;

			queue<int> q;
			q.push(i);
			visited[i] = 1;

			while (!q.empty()) {
				int u = q.front();
				q.pop();

				// Naive neighbor discovery: scan all stones every time.
				for (int v = 0; v < n; ++v) {
					if (visited[v]) continue;
					if (stones[u][0] == stones[v][0] || stones[u][1] == stones[v][1]) {
						visited[v] = 1;
						q.push(v);
					}
				}
			}
		}

		return n - components;
	}
};

// Example usage (not required by LeetCode, kept minimal)
int main() {
	vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
	Solution s;
	cout << s.removeStones(stones) << "\n";
	return 0;
}
