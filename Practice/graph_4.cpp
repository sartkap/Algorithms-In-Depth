// https://www.codechef.com/PRACTICE/problems/FIRESC
#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define ll long long
#define vi vector<int>
#define pb push_back
#define mk make_pair
bool visited[100003];
vector<int> v[100003];
ll p = 1000000007;
ll mu=1LL;
ll count1=0LL;
void dfs(int u){
    if(visited[u])return;
    visited[u]=true;
    count1++;
    for(auto c:v[u]){
        dfs(c);
    }
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,m;
	cin>>t;
	//mu=1LL;
	while(t--){
	    mu=1LL;
	    cin>>n>>m;
	    int p1,p2;
	    if(m==0){
	        cout<<n<<" "<<1<<"\n";
	        continue;
	    }
	    while(m--){
	        cin>>p1>>p2;
	        v[p1].pb(p2);
	        v[p2].pb(p1);
	    }
	    REP(i,n+1)visited[i]=false;
	    int count=0;
	    /*for(int i=1;i<=n;i++){
	        if(v[i].empty()){visited[i]=true;count++;}
	    }*/
	    for(int i=1;i<=n;i++){
	        if(visited[i]==false){
	            count1=0LL;
	            dfs(i);
	            //cout<<i<<" "<<count1<<" "<<mu<<endl;
	            mu*=count1;
	            mu%=p;
	            count++;
	        }
	    }
	    cout<<count<<" "<<mu<<"\n";
	    REP(i,n+1){
	    v[i].clear();
	    }
	    count1=0LL;
	}
    return 0;
}