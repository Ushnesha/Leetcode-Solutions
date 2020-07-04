class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNo(n);
        int i2 = 0, i3 = 0, i5 = 0;
        uglyNo[0]=1;
        int next_mul_of_2 = 2;
        int next_mul_of_3 = 3;
        int next_mul_of_5 = 5;
        int next_ugly_no = 1;
        for(int i = 1; i < n; i++){
            next_ugly_no = min(next_mul_of_2, min(next_mul_of_3, next_mul_of_5));
            uglyNo[i] = next_ugly_no;
            if(next_ugly_no == next_mul_of_2) next_mul_of_2 = uglyNo[++i2]*2;
            if(next_ugly_no == next_mul_of_3) next_mul_of_3 = uglyNo[++i3]*3;
            if(next_ugly_no == next_mul_of_5) next_mul_of_5 = uglyNo[++i5]*5;
        }
        return next_ugly_no;
    }
};