#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
bool is_valid(vector<int> Board, int N, int mid)
{
    int painter_req = 1;
    int board_planks = 0;
    for (int i = 0; i < Board.size(); i++)
    {
        if (board_planks + Board[i] <= mid)
        {
            board_planks += Board[i];
        }
        else{
            painter_req++;
            board_planks = Board[i];
        }
    }
    return painter_req <= N;
}
int Minimum_time(vector<int> board, int N)
{
    int max_time = 0;
    int min_time = INT_MIN;
    for (int i = 0; i < board.size(); i++)
    {
        max_time += board[i];
        min_time = max(min_time, board[i]);
    }
    /*SINCE WE KNOW THAT THE MINIMUM TIME WOULD BE IN BETWEEN THE MAX TIME AND THE MIN TIME THAT THE MAX TIME IS WHEN
    ALL THE BOARDS ARE PAINT BY THE SINGLE PAINTER AND MIN TIME WHEN WE ASSIGN A PARTICULARE POINTER TO EACH BOARD
    TO PAINT SO MIN_TIME WOULD BE EQUAL TO THE MAX_LENTH BOARD OF THE BOARD*/
    int i = min_time;
    int j = max_time;
    int answer = max_time;
    while (i <= j) 
    {
        int mid = i + (j - i) / 2;
        if (is_valid(board, N, mid))
        {
            answer = min(answer,mid);
            j = mid - 1;
        }
        else
            i = mid + 1;
    }
    return answer;
}
int main()
{
    int No_of_board, No_of_painter;
    cout << "Enter the number of boards: ";
    cin >> No_of_board;
    cout << "Enter the number of painters: ";
    cin >> No_of_painter;
    vector<int> Boards(No_of_board);
    for (int i = 0; i < No_of_board; i++)
    {
        cout << "Enter the time taken by painter to paint board " << i + 1 << " : ";
        cin >> Boards[i];
    }
    if(No_of_board == No_of_painter){
        cout << "Minimum time required to paint all the boards is: " << *max_element(Boards.begin(), Boards.end()) << endl;
    }
    cout << Minimum_time(Boards, No_of_painter);
    return 0;
}
