// https://codeforces.com/contest/1167/problem/D
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
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;
    	string t(n,'0');
    	int cur=0;
    	rep(i,n){
    		if(s[i]==')'){
    			cur--;
    		}
    		if(cur%2==1){
    			t[i]='1';
    		}
    		else{
    			t[i]='0';
    		}
    		if(s[i]=='('){
    			cur++;
    		}
     
    	}
    	cout<<t;
     
    	return 0;
    }