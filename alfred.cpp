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

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // freopen("error.txt","w",stderr);
    // #endif

    FAST_IO;
    int n;
    cin>>n;
    //cout<<n<<endl;
    int low = 1,high = (n>>1) + 1,flow,fhigh,ans;
    high =(high-1)%n + 1;
    cout.flush();
    cout<<"1 "<<low<<endl;
    cout.flush();
    cin>>flow;
    cout<<"1 "<<high<<endl;
    cout.flush();
    cin>>fhigh;
    bool found = false;
    flow = flow - fhigh;
    fhigh = -flow;
    while(!found){
        // if(flow==1||flow==-1||flow==0){
        //     break;
        // }
        if(flow==INT_MAX){
            cout<<"1 "<<low<<endl;
            cin>>flow;
            cout.flush();
        }
        if(fhigh==INT_MAX){
            cout<<"1 "<<high<<endl;
            cin>>fhigh;
            cout.flush();
        }
        int mid = (high+low)>>1;
        mid = (mid-1)%n + 1;
        int fmid1,fmid2;
        cout.flush();
        cout<<"1 "<<mid<<endl;
        cout.flush();
        cin>>fmid1;
        cout<<"1 "<<(mid + (n>>1) - 1)%n + 1<<endl;
        cout.flush();
        cin>>fmid2;
        fmid1 = fmid1 - fmid2;
        if(fmid1==1||fmid1==-1||fmid1==0){
            found = true;
            ans = mid;
            break;
        }
        if(flow==1||flow==-1||flow==0){
            found = true;
            ans = low;
            break;
        }
        if(fhigh==1||fhigh==-1||fhigh==0){
            ans = high;
            break;
        }
        if(fhigh>0&&fmid1<0||fhigh<0&&fmid1>0){
            low = mid;
            flow = fmid1;
        }
        else{
            high = mid;
            fhigh = fmid1;
        }
    }
    cout<<"2 "<<ans<<' '<<ans+(n>>1);
    return 0;
}
