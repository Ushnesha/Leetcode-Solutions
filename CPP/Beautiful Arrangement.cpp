class Solution {
public:
    int count=0;
    void countArrangements(int N, int pos, vector<int> v){
        if(pos>N) {
            count++;
            return;
        }
        for(int i=1;i<=N;i++){
            if(!v[i] && (pos%i==0 || i%pos==0)){
                v[i]=1;
                countArrangements(N,pos+1,v);
                v[i]=0;
            }
        }
        
    }
    int countArrangement(int N) {
        vector<int> v(N+1);
        countArrangements(N,1,v);
        return count;
    }
};
