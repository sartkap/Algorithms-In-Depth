// https://codeforces.com/contest/1178/problem/D
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
    #define vil vector<pair<ll,ll> >
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
    // ll p =  998244353;
    int isPrime(int n){
    	int i;
    	if(n==2 || n==3) return 1;
        if (n%2 == 0 || n%3 == 0)
            return 0;
     
        // root = (int)sqrt(n);
     
        for (i=5; i*i<=n; i+=6)
        {
            if (n%i == 0)
               return 0;
        }
     
        for (i=7; i*i<=n; i+=6)
        {
            if (n%i == 0)
               return 0;
        }
     
        return 1;
    }
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	cout.tie(0);
    	int n;
    	cin>>n;
    	int p=-1;
    	repa(i,n,n*(n-1)/2 + 1){
    		// cout<<i<<"\n";
    		if(isPrime(i)){
    			p=i;
    			break;
    		}
    	}
    	if(p==-1){
    		cout<<"-1";
    		return 0;
    	}
    	cout<<p<<"\n";
    	rep(i,n){
    		cout<<i+1<<" "<<(i+1)%n+1<<"\n";
    	}
    	p-=n;
    	int temp=1;
    	while(p>=1){
    		if(p==1){
    			// cout<<n;
    			cout<<temp<<" "<<temp+2<<"\n";
    			p=0;
    			break;
    		}
    		else{
    			cout<<temp<<" "<<(temp+2)<<"\n";
    			cout<<temp+1<<" "<<(temp+3)<<"\n";
    			p-=2;
    			temp+=4;
    		}
    	}
     
    	return 0;
    }