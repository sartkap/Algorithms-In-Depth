// link to the question - https://codeforces.com/contest/1228/submission/61504917
#include<bits/stdc++.h>
// #include &lt;bits/stdc++.h&gt;
// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// use gp_hash_table<int,int,custom_hash> m;
// in place of map
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define repba(i,b,a) for(int i=b;i>=a;--i)
#define repab(i,a,b) for(int i=a;i<b;++i)
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
ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
// This custom_hash is for unordered_map 
// use map<int, int, custom_hash> mp;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
vi v[100005];
vi b(100005);
vi one(100005);
vi two(100005);
vi three(100005);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x,y;
    rep(i,m){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    repa(i,1,n+1){
        if(s(v[i])<2){cout<<-1;return 0;}
    }
    b[1] = 1;
    for(auto x:v[1]){
        one[x] = 1;
    }
    repa(i,1,n+1){
        if(!one[i])b[i]=1;
    }
    // repa(i,1,11){
    //     cout<<b[i]<<' ';
    // }
    repa(i,2,n+1){
        if(b[i]==1){
            for(auto x:v[i]){
                if(b[x]==1){cout<<-1;return 0;}
            }
        }
        // else if(c==0)
    }
    repa(i,2,n+1){
        if(b[i]==0){
            for(auto x:v[i]){
                // if(one[x] == 1){cout<<-1;return 0;}
                two[x] = 1;
            }
            // for(auto x:v[i]){
            //     b[x]=2;
            // }
            
            break;
        }
    }
    repa(i,1,n+1){
        if(!two[i])b[i]=2;
    }
    repa(i,2,n+1){
        if(b[i]==2){
            for(auto x:v[i]){
                if(b[x]==2){cout<<-1;return 0;}
            }
        }
        // else if(c==0)
    }
    
    repa(i,2,n+1){
        if(b[i]==0){
            for(auto x:v[i]){
                if(b[x]==0){cout<<-1;return 0;}
            }
        }
        // else if(c==0)
    }
    int a1,a2,a3;
    a1=a2=a3=0;
    repa(i,1,n+1){
        if(b[i]==1)a1=1;
        else if(b[i]==2)a2=1;
        else if(b[i]==0)a3=1;
    }
        if(a1==0 || a2==0 || a3==0){cout<<-1;return 0;}
    // if()
    int v1=0,v2=0,v3=0;
    repa(x,1,n+1){
        if(b[x]==1)v1++;
        if(b[x]==2)v2++;
        if(!one[x] && !two[x])three[x]=1;
        if(b[x]==0)v3++;
    }
    repa(i,1,n+1){
        for(auto x:v[i]){
            if(b[i]==1 && b[x]==1){cout<<-1;return 0;}
            else if(b[i]==2 && b[x]==2){cout<<-1;return 0;}
            else if((b[i]==0) && (b[x]==0)){cout<<-1;return 0;}
            
        }
    }
    repa(i,1,n+1){
        if(b[i]==1 && s(v[i])!=(v2+v3)){cout<<-1;return 0;}
        if(b[i]==2 && s(v[i])!=(v1+v3)){cout<<-1;return 0;}
        if(b[i]==3 && s(v[i])!=(v2+v3)){cout<<-1;return 0;}
    }
    repa(i,1,n+1){
        if(b[i]==0)cout<<"3 ";
        else cout<<b[i]<<" ";
    }
	return 0;
}