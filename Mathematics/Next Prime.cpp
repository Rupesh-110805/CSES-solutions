#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;

u64 modmul(u64 a, u64 b, u64 m) {
    u64 res = 0;
    a %= m;
    while (b > 0) {
        if (b & 1) {
            res = (res + a) % m;
        }
        a = (a * 2) % m;
        b >>= 1;
    }
    return res % m;
}

u64 modpow(u64 a, u64 d, u64 m){
    u64 r = 1;
    a %= m;
    while(d){
        if(d & 1) r = modmul(r,a,m);
        a = modmul(a,a,m);
        d >>= 1;
    }
    return r;
}

bool isPrime(u64 n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(u64 p: {3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}){
        if(n == p) return true;
        if(n % p == 0) return false;
    }
    
    u64 d = n - 1, s = 0;
    while((d & 1) == 0){ d >>= 1; ++s; }
    
    for(u64 a: {2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL}){
        if(a >= n) continue;
        u64 x = modpow(a,d,n);
        if(x == 1 || x == n - 1) continue;
        bool comp = true;
        for(u64 i = 1; i < s; ++i){
            x = modmul(x,x,n);
            if(x == n - 1){ comp = false; break; }
        }
        if(comp) return false;
    }
    return true;
}

u64 fn(u64 n){
    if(n < 2) return 2;
    u64 c = n + 1;
    if(c % 2 == 0) ++c;
    while(!isPrime(c)) c += 2;
    return c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)) return 0;
    while(t--){
        u64 n; cin >> n;
        cout << fn(n) << "\n";
    }
    return 0;
}

