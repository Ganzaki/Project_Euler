/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler25      *
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



string findSum(string str1, string str2) 
{ 

	if (str1.length() > str2.length()) 
		swap(str1, str2); 
  
	string str = ""; 
  
	ll n1 = str1.length();ll n2 = str2.length(); 
	ll diff = n2 - n1; 

	ll carry = 0; 

	for (ll i=n1-1; i>=0; i--) 
	{ 

		ll sum = ((str1[i]-'0') + 
				   (str2[i+diff]-'0') + 
				   carry); 
		str.push_back(sum%10 + '0'); 
		carry = sum/10; 
	} 
  

	for (ll i=n2-n1-1; i>=0; i--) 
	{ 
		ll sum = ((str2[i]-'0')+carry); 
		str.push_back(sum%10 + '0'); 
		carry = sum/10; 
	} 

	if (carry) 
		str.push_back(carry+'0'); 
  
	reverse(str.begin(), str.end()); 
  
	return str; 
}

ll a[5100];

void Set()
{
	ll n = 5000;
	string f0("0");
	string f1("1");
	ll i = 2;
	a[0]=0;
	a[1]=1;
	string fn = findSum(f0,f1);
	while(1)
	{
		if(fn.length()>n)
			break;
		if(!a[fn.length()])
			a[fn.length()]=i;
		f0 = f1;
		f1 = fn;
		fn = findSum(f0,f1);
		i++;
	}
	//cout<<i<<endl;
}


void solve()
{
	ll n;
	cin>>n;
	cout<<a[n]<<endl;
}

int main()
{
	desperate_optimization(10);
	Set();
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}