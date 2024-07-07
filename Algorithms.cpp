//tairmazriv@gmail.com
//id: 209188382

#include "Algorithms.hpp"
#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <limits>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
using namespace std;


namespace ariel{
    bool Algorithms::isConnected(const Graph& g) {
        size_t n = g.Matrix.size();
        vector<bool> visited(n, false);
        queue<size_t> q;

        // Start BFS traversal from vertex 0
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            size_t curr = q.front();
            q.pop();
            // Visit all adjacent vertices of currrent vertex
            for (size_t i = 0; i < n; ++i) {
                if (g.Matrix[curr][i] != 0 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
    }

    // Check if all vertices are visited
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    return true;
}

    string Algorithms::shortestPath(const Graph& g, int start, int end) {
        size_t n = g.Matrix.size();
        vector<int> distance(n, -1); // Initialize all distances to -1 (unreachable)
        queue<size_t> q;
        vector<size_t> parent(n, numeric_limits<size_t>::max()); // Use max value to represent uninitialized state
        distance[static_cast<size_t>(start)] = 0;
        q.push(static_cast<size_t>(start));

        while (!q.empty()) {
            size_t curr = q.front();
            q.pop();
            for (size_t i = 0; i < n; ++i) {
                if (g.Matrix[curr][i] != 0 && distance[i] == -1) {
                    distance[i] = distance[curr] + 1;
                    parent[i] = curr; // Update parent
                    q.push(i);
                }
            }
        }

        // If end is not reachable, return "-1"
        if (parent[static_cast<size_t>(end)] == numeric_limits<size_t>::max()) {
            return "-1";
        }

        // Construct path string
        string path = to_string(end);
        size_t curr = static_cast<size_t>(end);
        while (curr != static_cast<size_t>(start)) {
            curr = parent[curr];
            path = to_string(curr) + "->" + path;
        }

        return path;
    }
    
    bool Algorithms::checkCycle(size_t node, vector<size_t> adj[], size_t vis[], size_t parent, vector<size_t> &path, size_t &cycleStart, std::unordered_set<size_t> &visitedNodes) {
        vis[node] = 1;
        path.push_back(node);
        visitedNodes.insert(node);

        for (size_t i = 0; i < adj[node].size(); ++i) {
            size_t it = adj[node][i];
            if (!vis[it]) {
                if (checkCycle(it, adj, vis, node, path, cycleStart, visitedNodes)) {
                    return true;
                }
            } else if (it != parent && visitedNodes.find(it) != visitedNodes.end()) {
                // Cycle detected
                cycleStart = it;
                path.push_back(it);
                return true;
            }
        }

        path.pop_back();
        visitedNodes.erase(node);
        return false;
    }

    bool Algorithms::isContainsCycle(const Graph& g) {
        size_t n = g.Matrix.size();
        vector<size_t> adj[n];
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (g.Matrix[i][j] != 0) {
                    adj[i].push_back(j);
                }
            }
        }

        size_t vis[n];
        vector<size_t> path;
        size_t cycleStart = n;
        std::unordered_set<size_t> visitedNodes;

        for (size_t i = 0; i < n; i++) {
            vis[i] = 0;
        }

        for (size_t i = 0; i < n; i++) {
            if (!vis[i]) {
                if (checkCycle(i, adj, vis, static_cast<size_t>(-1), path, cycleStart, visitedNodes)) {
                    // Print the cycle
                    cout << "The cycle is: ";
                    bool cycleStartFound = false;
                    for (size_t j = 0; j < path.size(); ++j) {
                        if (path[j] == cycleStart) {
                            cycleStartFound = true;
                        }
                        if (cycleStartFound) {
                            cout << path[j];
                            if (j < path.size() - 1) {
                                cout << "->";
                            }
                        }
                    }
                    cout << endl;
                    return true;
                }
            }
        }

        return false;
    }
    
    string Algorithms::isBipartite(const Graph& g) {
        size_t n = g.Matrix.size();

        // Create a color array to store colors assigned to each vertex.
        // 0: uncolored, 1: red, -1: blue
        vector<size_t> color(n, 0);

        // Use BFS
        for (size_t i = 0; i < n; ++i) {
            if (color[i] == 0) { // If the vertex is uncolored
                color[i] = 1;  // Assign it red color

                // Perform BFS traversal starting from this vertex
                queue<size_t> q;
                q.push(i);

                while (!q.empty()) {
                    size_t u = q.front();
                    q.pop();

                    // Iterate through neighbors of the currrent vertex
                   for (size_t v = 0; v < n; ++v) {
                        if (g.Matrix[u][v] != 0) { // If there's an edge
                            if (color[v] == 0) { // Only assign color if neighbor is uncolored
                                color[v] = -color[u]; // Assign opposite color to neighbor
                                q.push(v);
                            } else if (color[v] == color[u]) {
                                // If neighbor has the same color as currrent vertex, the graph is not bipartite
                                return "0";
                            }
                        }
                    }
                }
            }
        }

        // If the loop completes without finding conflicts, the graph is bipartite
        string setA = "A={";
        string setB = "B={";

        for (size_t i = 0; i < n; ++i) {
            if (color[i] == 1) {
                setA += to_string(i) + ", ";
            } else {
                setB += to_string(i) + ", ";
            }
        }

        // Remove trailing comma and closing brace
        setA.pop_back();
        setA.pop_back();
        setA += "}";

        setB.pop_back();
        setB.pop_back();
        setB += "}";

        return "The graph is bipartite: " + setA + ", " + setB;
    }

    bool Algorithms::negativeCycle(const Graph& g) {
        const vector<vector<int>>& matrix = g.Matrix;
        size_t n = matrix.size();
        vector<long long> dist(n, numeric_limits<long long>::max());
        vector<int> parent(n, -1);
        
        // Start from vertex 0
        dist[0] = 0;
        
        // Relax edges |V| - 1 times
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t u = 0; u < n; ++u) {
                for (size_t v = 0; v < n; ++v) {
                    if (matrix[u][v] != 0 && dist[u] != numeric_limits<long long>::max() &&
                        dist[u] + matrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + matrix[u][v];
                        parent[v] = static_cast<int>(u);
                    }
                }
            }
        }
        
        // Check for negative-weight cycles
        for (size_t u = 0; u < n; ++u) {
            for (size_t v = 0; v < n; ++v) {
                if (matrix[u][v] != 0 && dist[u] != numeric_limits<long long>::max() &&
                    dist[u] + matrix[u][v] < dist[v]) {
                    // Negative cycle found
                    vector<int> cycle;
                    int x = static_cast<int>(v);
                    for (size_t i = 0; i < n; ++i) {
                        x = parent[static_cast<size_t>(x)];
                    }
                    
                    int y = x;
                    cycle.push_back(y);
                    y = parent[static_cast<size_t>(y)];
                    while (y != x) {
                        cycle.push_back(y);
                        y = parent[static_cast<size_t>(y)];
                    }
                    cycle.push_back(y);
                    
                    // Check if the cycle has at least 3 vertices
                    if (cycle.size() >= 4) {
                        string cycleStr;
                        for (size_t i = cycle.size() - 1; i > 0; --i) {
                            cycleStr += to_string(cycle[i]) + "->";
                        }
                        cycleStr += to_string(cycle[0]);
                        
                        cout << "The negative cycle is: " << cycleStr << endl;
                        return true;
                    }
                }
            }
        }
        
        return false; // No negative cycle found or cycle has less than 3 vertices
    }
}