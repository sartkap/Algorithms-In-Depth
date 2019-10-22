// https://www.codechef.com/PRACTICE/problems/CSEQ
#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
ll p = 1000003;
ll c[1000004];
ll fastexp(ll x,ll a){
    ll res = 1;
    while(a>0){
        if(a&1){
            res = (res*x)%p;
        }
        a=a>>1;
        x=(x*x)%p;
    }
    return res;
}
ll inverse(ll n){
    return fastexp(n,p-2);
}
ll ncr(ll n,ll r){
    if(n<r)return 0;
    ll ans =  (c[n]*inverse(c[r]))%p;
    ans = ans*inverse(c[n-r])%p;
    return ans;
}
ll ncrac(int n,int r){
    if(n==0 && r==0)return 1;
    return (ncr(n%p,r%p)*ncrac(n/p,r/p))%p;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll l,r,k;
    c[0]=1;
    for(int i=1;i<1000004;i++){
        c[i] = (c[i-1]*i)%p;
    }
    int t;
    cin>>t;
    while(t--){
        cin>>k>>l>>r;
        ll ans = ncrac(r-l+1+k,k);
        ans = (ans + p - 1)%p;
        cout<<ans<<"\n";
    }
    //ll ans = fastexp(n,a);
    //cout<<ans;
	return 0;
}