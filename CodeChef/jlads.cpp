#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , m , k;
int rnk[N];
int arr[N];
int low[N];
vector < int > v[N];
vector < int > topo;
int indeg[N];
void toposort(){
	memset(indeg , 0 , sizeof(indeg));
	for(int i = 1 ; i <= n ; ++i){
		for(int x : v[i]){
			++indeg[x];
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!indeg[i]){
			v[0].emplace_back(i);
			++indeg[i];
		}
	}
	topo.clear();
	queue < int > que;
	while(!que.empty()){
		que.pop();
	}
	que.push(0);
	while(!que.empty()){
		int node = que.front();
		topo.emplace_back(node);
		que.pop();
		for(int next : v[node]){
			--indeg[next];
			if(!indeg[next]){
				que.push(next);
			}
		}
	}
}
set < int > s;
int higgh[N];
void toposort2(){
	s.clear();
	for(int i = 1 ; i <= k ; ++i){
		s.insert(i);
	}
	priority_queue < pair < int , int > > pq;
	while(!pq.empty()){
		pq.pop();
	}
	memset(indeg , 0 , sizeof(indeg));
	for(int i = 0 ; i <= n ; ++i){
		for(int x : v[i]){
			++indeg[x];
		}
	}
	pq.push({k , 0});
	for(int i = 0 ; i <= n ; ++i){
		higgh[i] = k;
		if(rnk[i]){
			higgh[i] = rnk[i];
			s.erase(rnk[i]);
		}
	}
	topo.clear();
	while(!pq.empty()){
		int node = pq.top().second;
		topo.emplace_back(node);
		int high = pq.top().first;
		pq.pop();
		if(high < low[node]){
			printf("-1\n");
			exit(0);
		}
		if(rnk[node] != 0){
			if(low[node] <= rnk[node] && rnk[node] <= high){
				arr[node] = rnk[node];
			}
			else{
				printf("-1\n");
				exit(0);
			}
		}
		else{
			auto it = s.lower_bound(high + 1);
			int val = -1;
			if(it != s.begin()){
				--it;
				val = *it;
			}
			if(val < low[node]){
				arr[node] = high;
			}
			else{
				arr[node] = val;
			}
		}
		if(s.find(arr[node]) != s.end()){
			s.erase(arr[node]);
		}
		for(int next : v[node]){
			--indeg[next];
			higgh[next] = min(higgh[next] , arr[node] - 1);
			if(!indeg[next]){
				pq.push({higgh[next] , next});
			}
		}
	}
}
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , rnk + i);
	}
	for(int i = 1 ; i <= m ; ++i){
		int a , b;
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
	}
	++k;
	rnk[0] = k;
	toposort();
	if(topo.size() != n + 1){
		printf("-1\n");
		return 0;
	}
	for(int i = n ; i >= 0 ; --i){
		int node = topo[i];
		low[node] = 1;
		for(int next : v[node]){
			low[node] = max(low[node] , low[next] + 1);
		}
		if(rnk[node] != 0){
			if(rnk[node] < low[node]){
				printf("-1\n");
				return 0;
			}
			low[node] = rnk[node];
		}
	}
	toposort2();
	if(!s.empty()){
		map < int , int > mp;
		mp.clear();
		for(int i = 1 ; i <= n ; ++i){
			++mp[arr[i]];
		}
		for(int ii = n ; ii >= 1 ; --ii){
			int node = topo[ii];
			if(rnk[node]){
				continue;
			}
			int high = arr[node];
			low[node] = 1;
			for(int next : v[node]){
				low[node] = max(low[node] , arr[next] + 1);
			}
			--mp[arr[node]];
			if(mp[arr[node]] == 0){
				s.insert(arr[node]);
			}
			auto it = s.lower_bound(low[node]);
			if(it != s.end() && *it <= high){
				arr[node] = *it;
				++mp[arr[node]];
				s.erase(arr[node]);
			}
		}
	}
	s.clear();
	for(int i = 1 ; i <= n ; ++i){
		for(int j : v[i]){
			if(arr[i] <= arr[j]){
				printf("-1\n");
				return 0;
			}
		}
		if(rnk[i] != 0 && arr[i] != rnk[i]){
			printf("-1\n");
			return 0;
		}
		s.insert(arr[i]);
	}
	if(s.size() != k - 1){
		printf("-1\n");
		return 0;
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , arr[i] , " \n"[i == n]);
	}
}
