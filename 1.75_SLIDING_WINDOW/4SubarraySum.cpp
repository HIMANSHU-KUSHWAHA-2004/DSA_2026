#include <iostream>
#include <climits>
using namespace std;
int main()
{
    /*AS WE KNOW HERE WE HAVE TO FIND MAXIMUM SUM OF THE SUBARRAY WHOSE LENTH = 4*/
    int arr[] = {2, 4, 5, 3, 2, 0, 9, 0, 4, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    int j = 0;
    int sum_4 = 0;
    int k = 4;
    int answer = INT_MIN;
    while (j < n)
    {
        sum_4 += arr[j];    //CONDITION THAT WAS GIVEN IN THE QUESTION
        if (j - i + 1 < k)
        /*SO THE SIZE OF THE WINDOW WE WILL USE THE CONDITION j - i + 1 = SIZE_OF_WINDOW*/
        {
            j++;
        }
        else
        {
            
            answer = max(answer, sum_4);
            sum_4 -= arr[i];        // REMOVING THE FIRST ELEMENT OF THE WINDOW
            /*EK INSTANT KE LIYE sum_4 MAI 3 ELEMENET KA HI SUM REH JATA HAI BUT AAGE JAKE ELEMENT ADD HO JATA H*/
            i++;                     
            //HERE WE ARE MOVING THE WINDDOW TO THE RIGHT OR FORWARD
            j++;
        }
    }
    cout << answer;
}