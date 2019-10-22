// https://codeforces.com/contest/1174/problem/D
    #include<bits/stdc++.h>
    using namespace std;
    #define rep(i,n) for(int i=0;i<n;i++)
    #define repa(i,a,n) for(int i=a;i<n;i++)
    #define repr(i,n) for(int i=n-1;i>=0;i--)
    #define repba(i,b,a) for(int i=b;i>=a;i--)
    #define repab(i,a,b) for(int i=a;i<b;i++)
    #define ll long long
    #define ull unsigned long long
    #define vi vector<int>
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
     
    int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	cout.tie(0);
    	ll n,x;
    	cin>>n>>x;
    	ll a = 1<<n;
    	//cout<<a;
    	vi v(0);
    	bool t[1<<n + 3]={false};
     
    	if(a<=x){
    		rep(i,a-1){
    			v.pb(i+1);
    		}
    	}
    	else{
    		t[x]=true;
    		rep(i,a-1){
    			if(t[i+1])continue;
    			t[i+1]=true;
    			t[(i+1)^x]=true;
    			v.pb(i+1);
    		}
    	}
    	vi b(0);
    	if(s(v)>0)b.pb(v[0]);
    	repa(i,1,s(v)){
    		b.pb(v[i]^v[i-1]);
    	}
    	cout<<s(b)<<"\n";
    	rep(i,s(b)){
    		cout<<b[i]<<" ";
    	}
    	return 0;	
    }