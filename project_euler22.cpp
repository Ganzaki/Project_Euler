/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler22      *
*                                   *
* * * * * * * * * * * * * * * * * * *
*/
#include <bits/stdc++.h>


#define FOR(i,j,k) for(ll i=j;i<k;i++)
#define FOR1(i,j,k) for(ll i=j;i<=k;i++)
#define FOR2(i,j,k) for(ll i=j;i>=k;i--)
#define FILL(a,i) memset(a,i,sizeof(a))
#define dbg(...) do{\
	fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_do(__VA_ARGS__);\
}while(0)


using namespace std;


typedef long long ll;
typedef unsigned long ul;
typedef std::string str;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef std::vector<str> vs;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<char> vc;
typedef map<int,int> mii;
typedef map<string,int> msi;

void desperate_optimization(int precision){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(precision);
}


void solve()
{
	ll n;ll q;
	cin>>n;
	str a;
	vs names;
	vs words;
	ll sum = 0;
	ll prod = 1;
	FOR(i,0,n){
		cin>>a;
		names.push_back(a);
	}
	sort(names.begin(), names.end());
	cin>>q;
	FOR(i,0,q){
		cin>>a;
		words.push_back(a);
	}
	FOR(i,0,q){
		sum = 0;
		prod = 1;
		FOR(j,0,words[i].length())
		{
			sum += (words[i][j] - 'A' + 1);
		}
		FOR(j,0,n)
		{
			if(names[j]==words[i])
			{
				prod = sum * (j+1); 
			}
		}
		cout<<prod<<endl;
	}
}


int main()
{
	desperate_optimization(10);
	solve();
	return 0;
}