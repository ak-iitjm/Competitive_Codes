#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef long double         ld;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
    typedef vector < vll >  vvll;
    typedef vector < vpii > vvpii;
    typedef set <int>       si;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i <= (b); i ++)
    #define rep(i, n)       for(int i = 1;i<=(n);i++)
    #define loop(i, n)      for(int i = 0;i<(n);i++)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    #define rrep(i, n)      rfl(i, n, 1)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    /* String methods */
    #define dig(i)          (s[i] - '0')
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define fr              first
    #define sc              second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define clr(a)          fill(a, 0)
    #define endl            '\n'
    /* Mathematical */
    #define IINF            0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl
    /* Fast Input Output */
    #define FAST_IO                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 100010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

ll dp[1050][1050];
ll cnt[1050];
ll fact[MAX];
int pos(string s){
    //cout<<s<<endl;
    loop(i,s.length()){
        if(s[i]!='4'&&s[i]!='7') return 0;
    }
    int ans = (1<<(s.length())) - 1 ;
    loop(i,s.length()){
        if(s[i]=='7'){
            ans+=(1<<i);
        }
    }
    //trace1(ans);
    return ans;
}

ll ncr(int n,int r){
    if(r>n) return 0ll;
    ll rf = (fact[r]*fact[n-r])%MOD;
    return (fact[n]*power(rf,MOD-2))%MOD;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    FAST_IO;
    
    ll n,k;
    cin>>n>>k;
    dp[0][0] = 1;
    fact[0] = 1;
    rep(i,100000){
        fact[i] = fact[i-1]*i;
        fact[i]%=MOD;
    }
    rep(i,n){
        string s;
        cin>>s;
        //cout<<s<<endl;
        cnt[pos(s)]++;
        //trace1(pos(s));
    }
    //if(k<=cnt[0]) dp[0][0] = ncr(cnt[0],k);

    //cout<<dp[0][0]<<endl;
    rep(i,1022){
        dp[i][0] = dp[i-1][0];
        rep(j,i){
            dp[i][j] = (dp[i-1][j] + ((dp[i-1][j-1]*cnt[i])%MOD ))%MOD;
        }
    }
    // loop(i,1023){
    //     loop(j,2){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    ll ans = 0;
    loop(i,min(1023ll,k+1)){
        ans = (ans + dp[1022][i]*ncr(cnt[0],k-i))%MOD;
        //trace1(ans);
    }
    cout<<ans<<endl;
    return 0;
}
