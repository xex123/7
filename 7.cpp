#include <iostream>
#include <vector>
#include <random>

using namespace std;

void dfs(const vector<vector<int>>& graph, int v, vector<bool>& visited) {
    visited[v] = true;

    cout << v << " ";

    for (int u = 0; u < graph.size(); ++u) {
        if (graph[v][u] == 1 && visited[u] == false) {
            dfs(graph, u, visited);
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int num_vertices;
    cout << "Введите количество вершин: ";
    cin >> num_vertices;

    if (num_vertices <= 0) {
        cerr << "Количество вершин должно быть больше 0." << endl;
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);

    vector<vector<int>> adjacency_matrix(num_vertices, vector<int>(num_vertices));
    for (int i = 0; i < num_vertices; ++i) {
        for (int j = i; j < num_vertices; ++j) {
            if (i == j) {
                adjacency_matrix[i][j] = 0;
            }
            else {
                adjacency_matrix[i][j] = adjacency_matrix[j][i] = distrib(gen);
            }
        }
    }

    cout << "Матрица смежности:" << endl;
    for (int i = 0; i < num_vertices; ++i) {
        for (int j = 0; j < num_vertices; ++j) {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Результат: ";

    vector<bool> visited(num_vertices, false);

    for (int i = 0; i < num_vertices; ++i) {
        if (!visited[i]) {
            dfs(adjacency_matrix, i, visited);
        }
    }



    return 0;
}