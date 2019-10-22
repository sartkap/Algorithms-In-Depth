// https://codeforces.com/contest/340/problem/D
    #include<bits/stdc++.h>
    using namespace std;
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
    vi v(100004);
    vi t(100004,0);
    int n;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
    int bsearch(int r, int key){
        int l = -1;
        while(r-l > 1){
            int m = (r+l)/2;
            if(t[m]>=key){
                r = m;
            }
            else{
                l = m;
            }
        }
        return r;
    }
    int longest(){
        int length = 1;
        t[0]=v[0];
        repa(i,1,n){
            if(v[i]<t[0])t[0]=v[i];
            else if(v[i]>t[length-1]){
                t[length]=v[i];
                length++;
            }
            else{
                t[bsearch(length-1,v[i])] = v[i];
            }
            // rep(j,length){
            //  cout<<t[j]<<" ";
            // }
            // cout<<"\n";
        }
        return length;
    }
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //int n;
        cin>>n;
        
        rep(i,n){
            cin>>v[i];
        }
        cout<<longest();
        return 0;
    }