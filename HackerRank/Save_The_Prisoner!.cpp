//https://www.hackerrank.com/challenges/save-the-prisoner/problem
#include<bits/stdc++.h>
using namespace std;
long long int saveThePrisoner(int n, int m, int s)
{
    long long int ans = m % n;
    if (ans != 0 )
     {
            long long int ans2 = (s + (ans- 1));
            if ( ans2 <= n )
            return ( ans2 );
            else
            {
              long long int p = ans2 - n ;
              return (ans+(p-1));
            }
     }
     else
     {
         int p = m/n ;
         return (s-(p-1));
     }

}
int main()
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
         long long int numberofPrisoners, numberofSweets, numberofChair;
         cin >> numberofPrisoners;
         cin >> numberofSweets;
         cin >> numberofChair;
        cout << saveThePrisoner(numberofPrisoners, numberofSweets,numberofChair) << endl;
    }
}
