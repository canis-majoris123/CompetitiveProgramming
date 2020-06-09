#include <bits/stdc++.h>
using namespace std;
int main()
{
      int age[3];
      int cost[3];
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t ;
      cin >> t;
      while(t--){
          bool f = 1;
        for(int i = 0; i < 3 ;++i) cin >> age[i];
        for(int i = 0; i < 3 ;++i) cin >> cost[i];

        for(int i = 0; i < 3 ;++i)
        for(int j = 0; j < 3 ;++j){
            if(i!=j){
                if(age[i] < age[j]){
                    if(cost[i] >= cost[j]) {f = 0; break;}
                }else if(age[i] == age[j]){
                    if(cost[i] != cost[j] ) {f = 0; break;}
                }else{
                    if(cost[i] <= cost[j]) {f = 0; break;}
                }
            }
        }
        if(f) cout << "FAIR\n"; else cout << "NOT FAIR\n";
    }

    }
