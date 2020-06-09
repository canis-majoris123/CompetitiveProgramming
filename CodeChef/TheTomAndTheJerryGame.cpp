#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0) ;
int32_t main()
{
    fast ;
    int testcases ;
    cin >> testcases ;
    while(testcases--)
    {
        int ts , cnt{0};
        cin >> ts ;
        if(ts % 2 == 0) ts /= 2 ;
        for(int i = 2 ; i <= ts ; i += 2)
        {
            cnt++ ;
        }
        cout << cnt << endl; 
    }
   
}