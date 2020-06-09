//https://www.hackerrank.com/challenges/find-point/problem
#include<bits/stdc++.h>
using namespace std;
#define aakriti float
int main()
{
    aakriti base, area;
    cin >> base >> area ;
    float height = area / (0.5 * base);
    long long int a = ceil(height);
    cout << a;
}
