// If a graph contains an odd-length cycle, it cannot be bipartite.

// A graph is bipartite if we can divide its nodes into two sets such that:

// No two adjacent nodes are in the same set.

// Or equivalently: you can color the graph using 2 colors such that no two connected nodes have the same color.

//one can color all the nodes with exactly 2 colors such that no two adjacent nodes have the same color

//A graph is bipartite if and only if it has no odd-length cycle.

// Try coloring the graph with two colors while doing BFS or DFS:

// Color the starting node with color 0.

// Color all its neighbors with color 1.

// Then their neighbors with color 0 again, and so on.

// If there’s no conflict (i.e., no edge between two same-colored nodes), then it’s bipartite.

// An odd-length cycle would force a conflict in two-coloring because you return to the starting point with the same color — hence it cannot be bipartite.

// So, the absence of odd-length cycles guarantees that the graph is 2-colorable, i.e., bipartite.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int n, vector<vector<int>>& adj) {
    vector<int> color(n, -1); // -1 means unvisited

    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u]; // alternate color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; // same color => not bipartite
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n = 5; // number of nodes
    vector<vector<int>> adj(n);

    // Example: no odd cycle (bipartite)
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};
    // adj[4] is isolated

    if (isBipartite(n, adj)) cout << "Graph is bipartite\n";
    else cout << "Graph is NOT bipartite\n";

    return 0;
}
