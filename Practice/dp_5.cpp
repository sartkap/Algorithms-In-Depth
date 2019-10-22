// https://codeforces.com/contest/1091/problem/D  
    #include<bits/stdc++.h>
    using namespace std;
    #define rep(i,n) for(int i=0;i<n;i++)
    #define repa(i,a,n) for(int i=a;i<n;i++)
    #define ll long long
    #define ull unsigned long long
    #define vi vector<int>
    #define mp make_pair
    #define vip vector<pair<int,int> >
    #define pb push_back 
    #define po pop_back
    #define fi first
    #define sec second
    ll p = 998244353;
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
        int n;
        cin>>n;
        ll ans =1LL;
        repa(i,2,n+1){
            ans*=i;
            ans%=p;
        }
        //cout<<ans<<"\n";
        //ll x=ans;
        ans*=n;
        //cout<<ans<<"\n";
        ans%=p;
        ll ans2=1LL;
        rep(i,n-1){
            ans2*=(n-i);
            //cout<<ans2<<"**";
            ans2%=p;
            ans=(ans+p-ans2)%p;
        }
        cout<<ans;
        return 0;
    }