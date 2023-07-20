#include <iostream>

using namespace std;

void digitprint(int num, string names[])
{
    if (num == 0)
    {
        return;
    }
    int digit = num % 10;
    num = num / 10;

    digitprint(num, names);
    cout << names[digit] << endl;
}

int main()
{

    int num;
    cin >> num;

    string names[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    digitprint(num, names);
}