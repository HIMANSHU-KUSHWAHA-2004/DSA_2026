#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &graph, vector<int> &visited, int node)
{
    visited[node] = 1;

    for (auto i : graph[node])
    {
        if (!visited[i])
        {
            DFS(graph, visited, i);
        }
    }
}

vector<vector<int>> Adjancy_List_Maker(vector<vector<int>> &graph, int v)
{
    vector<vector<int>> Maker(v + 1);

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (graph[i - 1][j - 1] == 1 && i != j)
            {
                Maker[i].push_back(j);
            }
        }
    }

    return Maker;
}

int No_of_province(vector<vector<int>> &graph, int v)
{
    vector<int> visited(v + 1, 0);
    vector<vector<int>> Boka = Adjancy_List_Maker(graph, v);

    int count = 0;

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            count++;
            DFS(Boka, visited, i);
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> matrix = {
        {0,1,1,0,0,0},
        {1,0,0,1,1,0},
        {1,0,0,1,0,0},
        {0,1,1,0,0,1},
        {0,1,0,0,0,0},
        {0,0,0,1,0,0}
    };

    int n = matrix.size();

    cout << "Number of Provinces: " << No_of_province(matrix, n);

    return 0;
}