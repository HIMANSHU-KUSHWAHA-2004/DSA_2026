#include <iostream>
#include <vector>
using namespace std;
void Print_subset(vector<int> &arr, vector<int> &answer, int i)
{
    if (i == arr.size())
    {
        for (int j = 0; j < answer.size(); j++)
        {
            cout << answer[j] << " ";
        }
        cout << endl;
        return;
    } // base case
    answer.push_back(arr[i]);

    Print_subset(arr, answer, i + 1); // THIS STEP WILL INCLUDE THE ELEMENET
    answer.pop_back();                // STEP WILL BACKTRACK TO THE PREVIOUS STATE
    Print_subset(arr, answer, i + 1); // THIS STEP WILL EXCLUDE THE ELEMENT
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> answer;
    Print_subset(arr, answer, 0);
}