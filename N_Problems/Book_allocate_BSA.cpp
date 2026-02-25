#include <bits/stdc++.h>
using namespace std;
bool is_valid(int max_allowed_pages, vector<int> books, int student)
{
    int student_needed = 1;
    int pages = 0;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i] > max_allowed_pages)
            return false;
        if (pages + books[i] <= max_allowed_pages)
        {
            pages += books[i];
        }
        else
        {
            pages = books[i];
            student_needed++;
        }
    }
    return student_needed <= student;
}
int Minimum_pages(vector<int> &books, int student)
{
    int n = books.size();
    if (student > n)
        return -1;
    int minimum_pages = 0;
    int maximum_pages = 0;
    for (int i = 0; i < n; i++)
    {
        maximum_pages += books[i];
    }
    int answer = INT_MAX;
    while (minimum_pages <= maximum_pages)
    {
        int mid = minimum_pages + (maximum_pages - minimum_pages) / 2;

        if (is_valid(mid, books, student))
        {
            maximum_pages = mid - 1;
            answer = min(mid, answer);
        }
        else
            minimum_pages = mid + 1;
    }
    return answer;
}
int main()
{
    int no_of_books;
    cin >> no_of_books;
    vector<int> books(no_of_books);
    for (int i = 0; i < no_of_books; i++)
    {
        cin >> books[i];
    }

    int no_of_students;
    cin >> no_of_students;
    cout << Minimum_pages(books, no_of_students);
}