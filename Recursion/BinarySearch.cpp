#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> vt, int begin, int end, int target)
{
    int mid = begin + int(end - begin) / 2;
    if(vt[mid] == target) return mid;                                                       
    if(vt[mid] < target) return BinarySearch(vt, mid + 1, end, target);
    return BinarySearch(vt, begin, mid, target);
}

int main()
{
    int n, target;
    cin >> n;
    cin >> target;
    vector<int> vt(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vt[i];
    }
    cout << BinarySearch(vt, 0, n - 1, target);
    return 0;
}
