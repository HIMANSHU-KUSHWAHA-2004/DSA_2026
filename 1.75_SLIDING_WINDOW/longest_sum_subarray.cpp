#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int j = 0;
    int sum = 0;
    int answer = INT_MIN;
    while (j < n)
    {
        sum += arr[j];
        answer = max(answer, sum);
        if(sum < 0){
            sum = 0;
        }
        j++;
    }
    cout << answer;
}
