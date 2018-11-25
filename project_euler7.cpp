/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
*       type : project_euler7       *
*                                   *
* * * * * * * * * * * * * * * * * * *
*/
#include <bits/stdc++.h>


#define FOR(j,k) for(ll i=j;i<k;i++)
#define FOR1(j,k) for(ll i=j;i<=k;i++)
#define FOR2(j,k) for(ll i=j;i>=k;i--)
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
ul sieve_size(ul n)
{

    if (n < 6)
        return 13;
    if (n >= (~0UL / log(~0UL)))
        return 0;
    ul low  = n;
    ul high = ~0UL - 1;
    do {
        ul mid   = low + (high - low) / 2;
        double        guess = mid / log(mid);

        if (guess > n)
            high = (ul) mid - 1;
        else
            low = (ul) mid + 1;
    } while (low < high);
    return high + 1;
}

ul nthPrime(ul n)
{
    if (!n) return 1;          
    if (!--n) return 2;       

    ul sieveSize = sieve_size(n);
    ul count     = 0;
    ul max_i     = sqrt(sieveSize-1)+1;

    if (sieveSize == 0)
        return 0;

    std::vector<bool> sieve(sieveSize);
    for (ul i = 3;  true;  i += 2) {
        if (!sieve[i]) {
            if (++count == n)
                return i;
            if (i >= max_i)
                continue;
            ul j    = i*i;
            ul inc  = i+i;
            ul maxj = sieveSize - inc;
            do {
                sieve[j] = true;
                if (j >= maxj)
                    break;
                j += inc;
            } while (1);
        }
    }
    return 0;
}

bool isPrime(ll n) 
{  
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    return ((ll)pow(2,n-1))%n==1;
} 


void solve()
{
	ul n;
	cin>>n;
	ul t = nthPrime(n);
	cout<<t<<endl;
}


int main()
{
	desperate_optimization(10);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}