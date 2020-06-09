// In the name of Aadi Shakti
// We are nothing and you are everything
// Jai Mata Di

// 40% accepted
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases ;
    cin >> testcases ;
    while(testcases--)
    {
        int n ;
        cin >> n ;
        int arr[n] ;
        long long count5{1} , count10{0};
        for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
        if(arr[0] > 5) cout << "NO\n" ;
        else
        {
            //long long sum = 5 ;
            int flag = 0 ;
            for(int i = 1 ; i < n ; i++)
            {
               if(arr[i] == 10) {
                   count5-- ;
                   if(count5 < 0)
                   {
                       flag = 1 ;
                   }
                   count10++ ;
               }
              else if(arr[i] == 15)
               {
                   if (count5 < 2 and count10 < 1)
                   {
                        flag = 1 ;
                   }

                   if(count10 > 0)
                   {
                       count10-- ;
                   }
                   else if(count5 >= 2) 
                   {
                       count5 -= 2 ;
                   }
                   
               }
               else if (arr[i] == 5) {
                   count5++ ;
               }

               if(flag == 1)
               {
                   break ;
               }
            }
            if(flag) cout << "NO\n" ;
            else cout << "YES\n" ;
        }
        
    }
    return 0 ;
}