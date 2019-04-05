#include <bits/stdc++.h>
#define  ll unsigned int
#define MAX 4294967296
using namespace std;

ll mark[3125000]; // ll mark[100000000/32]
ll prime[5761460];  /// Have Prime Number Upto 1e8
ll premulti[5761460];
ll nprime;

///Bitwise Sieve for Generating Fast Prime Number

ll setvalue(ll n,ll pos)
{
    return (n|(1<<pos));
}

ll checkvalue(ll n,ll pos)
{
    return (n&(1<<pos));
}

ll primefunction(ll n)
{
    ll i,j;
    ll limit=10000;
     premulti[nprime]=2;
    prime[nprime++]=2;
    for(i=3; i<=n; i+=2)
    {
        if(checkvalue(mark[i>>5],i&31)==0)
        {
             premulti[nprime]=premulti[nprime-1]*i;
            prime[nprime++]=i;
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=(i<<1))
                {
                    mark[j>>5]=setvalue(mark[j>>5],j&31);
                }
            }
        }
    }
}

ll POW (ll a,ll b)
{
    ll ans=1,i;
    for(i=1; i<=b; i++)
    {
        ans*=a;
    }
    return ans;
}
/// Find Maximum power in a prime factorization

ll Power(ll n,ll a)
{
    ll j,x=0;
    for(j=1; ; j++)
    {
        x=n/a;
        if(x==0)
            break;
        n=n/a;
    }
    j--;
    return j;
}


int main()
{
    primefunction(1e8);
   // precalculation();
    ll t,n,caseno=1,x,ans,i,upper;
    scanf("%u",&t);
    while(t--)
    {
        scanf("%u",&n);
        ans=1;
        for(i=0; prime[i]*prime[i]<=n; i++)
        {
            x=Power(n,prime[i]);
            if(x)
            {
                ans*=POW(prime[i],x-1);
            }
        }
        upper = upper_bound(prime, prime+nprime, n) - prime;
        upper--;
        ans*=premulti[upper];
        printf("Case %u: %u\n",caseno++,ans);

    }

    return 0;

}
