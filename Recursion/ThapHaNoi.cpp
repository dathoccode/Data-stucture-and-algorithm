#include <iostream>
using namespace std;


void HanoiTower(int n, char source, char destination, char auxiliary)
{
    if(n == 1) 
    {
        cout << "chuyen 1 dia tu cot " << source << " sang cot " << destination << endl;
    }
    else
    {
        HanoiTower(n - 1, source, auxiliary, destination);
        cout << "chuyen 1 dia tu cot " << source << " sang cot " << destination << endl;
        HanoiTower(n - 1, auxiliary, destination, source);
    }
}

int main()
{
    HanoiTower(8, 'A', 'C', 'B');
    return 0;
}