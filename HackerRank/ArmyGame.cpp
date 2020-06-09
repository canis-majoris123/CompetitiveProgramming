//https://www.hackerrank.com/challenges/game-with-cells/problem
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  int ans = (n+1)/2;
  ans *= (m+1)/2;
  cout<<ans<<endl;
  return 0;
}

