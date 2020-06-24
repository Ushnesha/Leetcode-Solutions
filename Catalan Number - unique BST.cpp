class Solution {
public:
    unsigned long long nCr(int n, int r){
        unsigned long long res=1;
        r=min(r, n-r);
        for(int i=0;i<r;i++){
            res*=(n-i);
            res/=(i+1);
        }
        return res;   
    }
    
    unsigned long long catalanNumber(int n){
        unsigned long long res = nCr(2*n,n);
         return res/(n+1);  
    }
    
    int numTrees(int n) {
        return catalanNumber(n);
    }
};