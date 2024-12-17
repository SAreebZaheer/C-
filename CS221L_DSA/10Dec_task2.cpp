#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, component);
        }
    }
}

vector<vector<int>> findConnectedComponents(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, graph, visited, component);
            components.push_back(component);
        }
    }

    return components;
}

int main() {
    // Example graph (adjacency list representation)
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0, 4},
        {1, 3, 6},
        {2, 7},
        {4, 8},
        {5, 8},
        {6, 7}
    };

    vector<vector<int>> components = findConnectedComponents(graph);

    for (const auto& component : components) {
        cout << "Connected components: ";
        for (int district : component) {
            cout << "District " << district << " -> ";
        }
        cout << endl;
    }

    return 0;
}