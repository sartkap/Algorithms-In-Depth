// https://codeforces.com/contest/1114/problem/D   
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
    ll mod = 1000000007;
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
    	vi v(n);
    	//vi count(5001,0);
    	int c=-1;
    	//cin>>v[0];
    	rep(i,n){
    		cin>>v[i];
    		// if(v[i]==v[i-1])continue;
    		// count[v[i]]++;
    		// if(count[v[i]]%2==0){
    		// 	repr(j,i){
     
    		// 	}
    		// }
    	}
    	vi b(0);
    	b.pb(v[0]);
    	repa(i,1,n){
    		if(v[i]!=v[i-1])b.pb(v[i]);
    	}
    	// rep(i,s(b)){
    	// 	cout<<b[i]<<" ";
    	// }
    	//cout<<endl;
    	int dp[n][n][2];
    	rep(i,n){
    		rep(j,n){
    			rep(k,2){
    			if(i==j)dp[i][j][k]=0;
    			else dp[i][j][k]=1000000;
    		}
    		}
    	}
    	rep(r,n){
    		repr(l,r+1){
    			rep(k,2){
    				if(k)c=v[r];
    				else c=v[l];
    			if(l-1>=0){
    				dp[l-1][r][0]=min(dp[l-1][r][0],dp[l][r][k]+int(v[l-1]!=c));
    			}
    			if(r+1<=n-1){
    				dp[l][r+1][1]=min(dp[l][r+1][1],dp[l][r][k]+int(v[r+1]!=c));
    			}
    		}}
    	}
    	// rep(i,n){
    	// 	rep(j,n){
    	// 		rep(k,2){
    	// 			cout<<dp[i][j][k];
     
    	cout<<min(dp[0][n-1][1],dp[0][n-1][0]);
    	return 0;
    }