#include <iostream>
using namespace std;
int main()
{
    /*THIS IS A BRUTE FORCE APPROCH FOR FINDING THE SUB ARRAY SINCE WE ARE USING THE 3 NESTED LOOP SO TIME COMPLEXITY IS O(n^3)
    BUT USING THE KADANES ALGORITHM WE CAN SETTLE IT TO O(n)*/
    ios::sync_with_stdio(false);
    /*When you disable synchronization, you are telling the program to allow C++ streams (like cin and cout) to operate independently of C streams (like printf and scanf).
    This means that the output from cout will not automatically wait for or be synchronized with the output from printf. They can potentially display data out of order.*/
    cin.tie(nullptr);
    /*THERE IS A THING HAPPEN IN BOTH C AND CPP THAT AFTER USING THE  CIN(INPUT) FUNCTION IT WILL CHECK THAT IS THERE ALSO AN COUT
    FUNCTION IN THE CODE THEN AFTER THE CHECK IT RUN NOW IN THE CP THERE ARE ALOT OF THE TEST CASE SO IT SLOW DONW THE 
    PROGRAM SO WE USE THE cin.tie(nullptr)  TO MAKE IT FAST THIS BREAK THE LINK BETEWEEN THE CIN AND COUT */
    /**/
    int n = 5;
    int arr[5] = {-8, 2, 9, -5, 5};
    int count = 0;
    int maximum_subarraysum = arr[0];
    int max_sum_is = 0;
    for (int start = 0; start < n; start++)
    {

        int current_sum = 0;
        for (int end = start; end < n; end++)
        {
            current_sum += arr[end];
            max_sum_is = max(current_sum, max_sum_is);
            cout << arr[end] << " ";
        }
        cout << "\n";
    }
    cout << max_sum_is;
}