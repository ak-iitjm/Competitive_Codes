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

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    FAST_IO;
    
    string s;
    cin>>s;
    int a = 0,b = 0,c = 0,n = s.length();
    loop(i,n){
        if(s[i]=='0') a++;
        else if(s[i]=='1') b++;
        else c++;
    }
    //trace3(a,b,c);
    if(n&1){
        //trace1("Yeah");
        if(a+c+1>b){
            cout<<"00"<<endl;
        }
        if(s[n-1]!='0'){
            if(s[n-1]=='1'){
                if(a<b-1){
                    if(a+c>=b-1){
                        cout<<"01"<<endl;
                    }
                }
                else{
                    if(b+c>=a+1){
                        cout<<"01"<<endl;
                    }
                }
            }
            else{
                if(a<b){
                    if(a+c>=b+1){
                        cout<<"01"<<endl;
                    }
                }
                else{
                    if(b+c>=a+1){
                        cout<<"01"<<endl;
                    }
                }
            }
        }
        if(s[n-1]!='1'){
            if(s[n-1]=='0'){
                if(a<b-1){
                    if(a+c>=b-1){
                        cout<<"10"<<endl;
                    }
                }
                else{
                    if(b+c>=a+1){
                        cout<<"10"<<endl;
                    }
                }
            }
            else{
                if(a<b-2){
                    if(a+c>=b-1){
                        cout<<"10"<<endl;
                    }
                }
                else{
                    if(b+c>=a+3){
                        cout<<"10"<<endl;
                    }
                }
            }
        }
        if(b+c>a+1){
            cout<<"11"<<endl;
        }
    }
    else{
        if(a+c>b){
            cout<<"00"<<endl;
        }
        if(s[n-1]!='0'){
            if(s[n-1]=='1'){
                if(a<b){
                    if(a+c>=b){
                        cout<<"01"<<endl;
                    }
                }
                else{
                    if(b+c>=a){
                        cout<<"01"<<endl;
                    }
                }
            }
            else{
                if(a<b+1){
                    if(a+c>=b+2){
                        cout<<"01"<<endl;
                    }
                }
                else{
                    if(b+c>=a){
                        cout<<"01"<<endl;
                    }
                }
            }
        }
        if(s[n-1]!='1'){
            if(s[n-1]=='0'){
                if(a<b){
                    if(a+c>=b){
                        cout<<"10"<<endl;
                    }
                }
                else{
                    if(b+c>=a){
                        cout<<"10"<<endl;
                    }
                }
            }
            else{
                if(a<b-1){
                    if(a+c>=b){
                        cout<<"10"<<endl;
                    }
                }
                else{
                    if(b+c>=a+2){
                        cout<<"10"<<endl;
                    }
                }
            }
        }
        if(b+c>a){
            cout<<"11"<<endl;
        }
    }
    return 0;
}
