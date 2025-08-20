class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9+7;
    int findPower(ll a, ll b){
        if(b == 0) return 1;

        ll half = findPower(a,b/2);
        ll result = (half * half) % MOD;

        if(b % 2 == 1){
            result = (result * a)%MOD;
        }

        return result;
    }
    int countGoodNumbers(ll n) {
        return (ll)findPower(5,(n+1)/2) * findPower(4,n/2)%MOD;
    }
};