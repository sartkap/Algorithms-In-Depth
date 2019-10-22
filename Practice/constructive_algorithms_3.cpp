// https://codeforces.com/contest/319/problem/B    
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
    int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	cout.tie(0);
    	int n;
    	cin>>n;
    	int x = 200000;
    	vi v(n+1);
    	repa(i,1,n+1)cin>>v[i];
    	stack<int> st;
    	st.push(0);
    	vi l(n+1);
    	l[0]=x;
    	repa(i,1,n+1){
    		l[i]=1;
    		while(st.size()>0 && v[i]>v[st.top()]){
    			l[i]=max(l[i],l[st.top()]+1);
    			st.pop();
    		}
    		st.push(i);
    	}
    	int ans=0;
    	repa(i,1,n+1){
    		if(l[i]<x)ans=max(ans,l[i]);
    	}
    	cout<<ans;
     
     
    	return 0;
    }