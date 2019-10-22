// https://codeforces.com/contest/1114/problem/E
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
int q=0;
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int bsearch(int n){
    int l = 0, r = 1000000001;
    int mid = (l+r)/2;
    int y;
    while(l+1<r){
        q++;
        mid = (l+r)/2;
        cout<<"> "<<mid<<"\n"<<flush;
        cin>>y;
        if(y==0){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return l+1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int high = bsearch(n);
    //cout<<high<<flush;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    //cout<<mt_rand();
    //std::random_device device;    
    //std::mt19937 generator(device());
    //std::uniform_int_distribution<int> distribution(1,n);
    //vi b(0);
    int y;
    int x;
    //cout<<"? "<<x<<"\n"<<flush;
    //cin>>y;
    //b.pb(y);
    int g=0;
    //int y;
    while(q<60){
        x = rng()%n+1;
        cout<<"? "<<x<<"\n"<<flush;
        cin>>y;
        g=gcd(g,high-y);
        q++;
    }
    
    //cout<<g<<' '<<flush;
    //sort(all(b));
    //ll g = b[1]-b[0];
    //rep(i,s(b)){
      //  cout<<b[i]<<' ';
    //}
    // rep(i,s(b)){
    //     repa(j,i+1,s(b)){
    //         g=gcd(g,(ll)b[j]-(ll)b[i]);
    //         //cout<<g<<"\n"<<flush;
    //     }
    // }
    cout<<"! "<<high-g*(n-1)<<" "<<g<<flush;
    return 0;
}