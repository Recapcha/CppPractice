#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    int arr[] = {2, 6, 7};

    cout << arr[1] << endl;

    cout << *(arr + 1) << endl;

    return 0;
}