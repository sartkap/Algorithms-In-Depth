// https://www.codechef.com/PRACTICE/problems/GRGUY
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
	if(b==0)return 0;
	return gcd(b,a%b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		int c1,c2;
		c1=INT_MAX;
		c2=INT_MAX;
		if(s1[0]=='#'&& s2[0]=='#'){cout<<"No\n";continue;}
		if(s1[0]=='.'){
			c1=0;
			int cu=1;
			repa(i,1,s1.length()){
				if(s1[i]=='.' && cu==1)continue;
				else if(s2[i]=='.' && cu==2)continue;
				else if(s1[i]=='.' && cu==2){cu=1;c1++;}
				else if(s2[i]=='.' && cu==1){cu=2;c1++;}
				else {cu=-1;break;}
			}
			if(cu==-1){cout<<"No\n";continue;}

		}
		if(s2[0]=='.'){
			c2=0; 
			int cu=2;
			repa(i,1,s2.length()){
				if(s1[i]=='.' && cu==1)continue;
				else if(s2[i]=='.' && cu==2)continue;
				else if(s1[i]=='.' && cu==2){cu=1;c2++;}
				else if(s2[i]=='.' && cu==1){cu=2;c2++;}
				else {cu=-1;break;}
			}
			if(cu==-1){cout<<"No\n";continue;}

		}
		cout<<"Yes\n";
		cout<<min(c1,c2)<<"\n";

	}	
	return 0;
}