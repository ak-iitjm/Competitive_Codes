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
    typedef pair<int,pair<ll,char>> plic;
    typedef pair<ll,pii> plii;
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

vector<plic> graph[1001];
ll mindist[1001][1001];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    FAST_IO;

    int t;
    cin>>t;
    while(t--){
    	int n,m,s,t;
    	cin>>n>>m>>s>>t;
    	rep(i,n){
    		graph[i].clear();
    		rep(j,n){
    			mindist[i][j] = LONG_MAX;
    		}
    	}
    	rep(i,m){
    		int u,v;
    		ll w;
    		char c;
    		cin>>u>>v>>w>>c;
    		graph[u].pb({v,{w,c}});
    		graph[v].pb({u,{w,c}});
    	}
    	ll ans = LONG_MAX;
    	priority_queue<plii,vector<plii>,greater<plii>> pq;
    	pq.push({0ll,{s,t}});
    	mindist[s][t] = 0;
    	while(!pq.empty()){
    		plii tp = pq.top();
    		//trace1(tp.sc.sc);

    		pq.pop();
    		ll cst = tp.fr;
    		int u = tp.sc.fr,v=tp.sc.sc;
    		if(cst>mindist[u][v]){
    			continue;
    		}
    		if(u==v){
    			ans = min(ans,cst);
    			//trace3(u,v,ans);
    			continue;
    		}
    		for(auto i:graph[u]){
    			int u1 = i.fr;
    			char c1 = i.sc.sc;
    			ll e1 = i.sc.fr;
    			for(auto j:graph[v]){
    				int v1 = j.fr;
    				char c2 = j.sc.sc;
    				ll e2 = j.sc.fr;
    				if(u1==v){
    					ans = min(ans,cst + e1);
    					//trace3(u1,v,ans);
    					continue;
    				}
    				if(c1==c2&&mindist[u1][v1]>cst+e1+e2){
    					mindist[u1][v1] = cst+e1+e2;
    					pq.push({mindist[u1][v1],{u1,v1}});
    				}
    			}
    			//trace1(c1);
    		}
    	}
    	if(ans==LONG_MAX){
    		cout<<"-1"<<endl;
    	}
    	else cout<<ans<<endl;
    }

    return 0;
}
