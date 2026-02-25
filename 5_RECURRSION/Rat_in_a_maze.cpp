#include <bits/stdc++.h>
using namespace std;
void Rat_in_a_maze_Path(vector<vector<int>> &maze, int R, int C, string path, vector<string> &answer)
{
    if (R < 0 || C < 0 || R >= maze.size() || C >= maze[0].size() || maze[R][C] == 0 || maze[R][C] == -1)
    {
        return;
    }

    if (R == maze.size() - 1 && C == maze.size() - 1)
    {
        answer.push_back(path);
        return;
    }
    maze[R][C] = -1;
    Rat_in_a_maze_Path(maze, R + 1, C, path + "D", answer); // for going Upward
    Rat_in_a_maze_Path(maze, R, C + 1, path + "R", answer); // for going Right
    Rat_in_a_maze_Path(maze, R - 1, C, path + "U", answer); // for going Downward
    Rat_in_a_maze_Path(maze, R, C - 1, path + "L", answer); // for going Left
    maze[R][C] = 1;
}
void printing(vector<string> answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}};
    vector<string> answer;
    string path = "";
    Rat_in_a_maze_Path(maze, 0, 0, path, answer);
    printing(answer);
}