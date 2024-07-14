#include <iostream>

using namespace std;

void DecToBin(int n)
{
    if(n == 1) cout << 1;
    else
    {
        DecToBin(n / 2);
        cout << n % 2;
    }
}

int main()
{
    int n;
    cin >> n;
    DecToBin(n);
    return 0;
}