// https://codeforces.com/contest/182/problem/D
    #include<bits/stdc++.h>
    using namespace std;
    #define rep(i,n) for(int i=0;i<n;++i)
    #define repa(i,a,n) for(int i=a;i<n;++i)
    #define repr(i,n) for(int i=n-1;i>=0;--i)
    #define repba(i,b,a) for(int i=b;i>=a;--i)
    #define repab(i,a,b) for(int i=a;i<b;++i)
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
    ll mod = 1000000007;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
    ll gcd(ll a,ll b){
    	if(b==0)return a;
    	return gcd(b,a%b);
    }
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	cout.tie(0);
    	// int d,n;
    	// cin>>d>>n;
    	// vi v(n);
    	// rep(i,n){
    	// 	cin>>v[i];
    	// }
    	string s1,s2;
    	cin>>s1>>s2;
    	vi v(0);
    	repa(i,1,s(s1)+1){
    		if(s(s1)%i==0 && s(s2)%i==0)v.pb(i);
    	}
    	int f=0;
    	int c=0;
    	repr(i,s(v)){
    		f=0;
    		rep(j,v[i]){
    			if(s1[j]!=s2[j]){f=1;break;}
    		}
    		rep(j,s(s1)){
    			if(s1[j%v[i]]!=s1[j]){f=1;break;}
    		}
    		rep(j,s(s2)){
    			if(s2[j%v[i]]!=s2[j]){f=1;break;}
    		}
    		if(f==0)c++;
    	}
    	cout<<c;
     
    	return 0;
    }