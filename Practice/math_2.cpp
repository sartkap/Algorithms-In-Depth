// https://codeforces.com/contest/217/problem/A

    #include<bits/stdc++.h>
    using namespace std;
    #define rep(i,n) for(int i=0;i<n;i++)
    #define repa(i,a,n) for(int i=a;i<n;i++)
    #define repr(i,n) for(int i=n-1;i>=0;i--)
    #define repba(i,b,a) for(int i=b;i>=a;i--)
    #define repab(i,a,b) for(int i=a;i<b;i++)
    #define ll long long
    #define ull unsigned long long
    #define vi vector<ll>
    #define msi map<string,int>
    #define mii map<int,int>
    #define viip vector<pair<pair<int,int> >,int>
    #define mp make_pair
    #define vip vector<pair<int,int> >
    #define pb push_back 
    #define po pop_back
    #define fi first
    #define sec second
    #define all(v) v.begin(),v.end()
    #define rall(v) v.rbegin(),v.rend()
    #define s(v) v.size()
    vi b[1010000];
    bool visited[1010000]={false};
    void dfs(int u){
    	visited[u]=true;
    	for(auto x:b[u]){
    		if(!visited[x])dfs(x);
    	}
     
    }
    int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	cout.tie(0);
    	int n;
    	cin>>n;
     
    	vip v(n);
    	int N = 1001;
    	int size = 1010000;
    	//cout<<visited[]
    	bool t[1010000]={false};
    	rep(i,n){
    		cin>>v[i].fi>>v[i].sec;
    		t[N*v[i].fi+v[i].sec]=true;
    		rep(j,i){
    			if(v[i].fi == v[j].fi || v[i].sec == v[j].sec){
    				b[N*v[i].fi+v[i].sec].pb(N*v[j].fi+v[j].sec);
    				b[N*v[j].fi+v[j].sec].pb(N*v[i].fi+v[i].sec);
     
    			}
    		}
    	}
    	//cout<<b[5][0]<<" ";
    	int count=-1;
    	rep(i,size){
    		if(!visited[i] && t[i]){
    			count++;
    			dfs(i);
    		}
    	}
    	cout<<count;
     
    	
     
    	return 0;	
    }