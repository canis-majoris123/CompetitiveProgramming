// In the name of Aadi Shakti

#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define fast std::ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0) ;

void solve()
{
    int arr[2][2] ;
    for(int i = 0 ; i < 2 ; i++)
    {
        for(int j = 0 ; j < 2; j++)
        {
            cin >> arr[i][j] ;
        }
    }
    int brr[2][2] ;
    for(int i = 0 ; i < 2 ; i++)
    {
        for(int j = 0 ; j < 2; j++)
        {
            cin >> brr[i][j] ;
        }
    }   
    
    int mul[2][2] = {0} ;
    for(int i = 0; i < 2 ; i++)
    {
        for(int j = 0 ; j < 2 ; j++)
        {
            for(int k = 0 ; k < 2 ; k++)
            {
                mul[i][j] += arr[i][k] * brr[k][j] ;
            }
        }
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0 ; j < 2 ; j++ )
        {
            cout << mul[i][j] << " " ;
        }
        cout << endl ;
    }
}

int32_t main()
{
    int testcase  = 1 ;
    while(testcase--)
    {
        solve();
    }
    return 0 ;
}