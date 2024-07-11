#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la " << gcd(a, b);
    return 0;
}