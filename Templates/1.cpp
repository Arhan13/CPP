#include"bits/stdc++.h"
using namespace std;

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define eb(x) emplace_back(x)
#define mp(a,b) make_pair(a,b)
#define sz(a) int((a).size())
#define mod 1000000007
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define inf LLONG_MAX
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }


void seethis(vector<ll>vect)
{
    for(ll x:vect)
        cout<<x<<" ";
    cout<<"\n";
}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
//LCM
int lcm(int a, int b) {  return a * (b / __gcd(a, b)); }

//For sort by second
bool cmp(const pair<int,int> &a)
{ return a.first<a.second; }

//Tree
/* const int MAXN = 1e5 + 5;
vector<ll> adj[MAXN];*/

//ModPower
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}

int main()
{
	FASTIO;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; //testcases
	while(t--)
	{
		ll n;
		 cin>>n;

		 vector<ll>vect(n);
		 vector<ll>pre(n+1);
		 for(int i=0;i<n;i++)
		 {
			cin>>vect[i];
			pre[i+1]=(pre[i]+vect[i]);
		 }

		 

		 for(int i=1;i<=n;i++)
		 	pre[i]%=n;

		

		 map<ll,ll>mp;

		 for(int i=1;i<=n;i++)
		 {

		 	if(pre[i]==0)
		 	{
		 		cout<<i<<"\n";
		 		for(int j=1;j<=i;j++)
		 		{
		 			cout<<j<<" ";
		 		}
		 		cout<<"\n";
		 		break;
		 	}
		 	else if(mp.find(pre[i])==mp.end())
		 	{
		 		mp[pre[i]]=i;
		 	}
		 	else
		 	{
		 		ll len= i-mp[pre[i]];
		 		cout<<len<<"\n";
		 		for(ll j=mp[pre[i]]+1;j<=i;j++)
		 		{
		 			cout<<j<<" ";
		 		}
		 		cout<<"\n";
		 		break;
		 	}


		 }
		 	
	}

	
	return 0;
}
