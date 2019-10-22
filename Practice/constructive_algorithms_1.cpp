// https://codeforces.com/contest/1196/problem/E
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
    	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    	#endif
    	int q;
    	cin>>q;
    	while(q--){
    		int b,w;
    		cin>>b>>w;
    		if(3*(b-1)<(w-4)){
    			cout<<"NO\n";
    			continue;
    		}
    		if(3*(w-1)<(b-4)){
    			cout<<"NO\n";
    			continue;
    		}
    		cout<<"YES\n";
    		if(b<=w){
    			int i=0;
    			while(1){
    				if(b==w || b+1==w)break;
    				cout<<2+2*i<<" "<<3<<"\n";
    				b--;
    				
    				cout<<3+2*i<<" "<<3<<"\n";
    				w--;
    				if(w==0)break;
    				cout<<2+2*i<<" "<<4<<"\n";
    				w--;
    				if(w==0)break;
    				cout<<2+2*i<<" "<<2<<"\n";
    				w--;
    				if(w==0)break;
    				i++;
    				if(b==0)break;
    			}
    			// if(b>0 && w==0){
     
    			// }
    			if(b>0){
    				while(b>0){
    					cout<<2+2*i<<" "<<3<<"\n";
    					cout<<3+2*i<<" "<<3<<"\n";
    					b--;
    					w--;
    					i++;
    				}
    			}
    			if(w==1)cout<<"1 3\n";
    		}
    		else{
    			int i=0;
    			while(1){
    				if(b==w || b==w+1)break;
    				cout<<2+2*i<<" "<<2<<"\n";
    				w--;
    				
    				cout<<3+2*i<<" "<<2<<"\n";
    				b--;
    				if(b==0)break;
    				cout<<2+2*i<<" "<<3<<"\n";
    				b--;
    				if(b==0)break;
    				cout<<2+2*i<<" "<<1<<"\n";
    				b--;
    				if(b==0)break;
    				i++;
    				if(w==0)break;
    			}
    			// if(b>0 && w==0){
     
    			// }
    			if(w>0){
    				while(w>0){
    					cout<<2+2*i<<" "<<2<<"\n";
    					cout<<3+2*i<<" "<<2<<"\n";
    					b--;
    					w--;
    					i++;
    				}
    			}
    			if(b==1)cout<<"1 2\n";	
    		}
    	}
     
    	
    	return 0;
    }