class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return -1;
        else if( x == 0 || x == 1) return x;

        long int low = 0;
        long int high = x;
        long int mid = low + (high-low)/2;

        while((low < high) && (mid * mid != x)){
            if(mid*mid > x) high = mid;
            else low = mid +1;
            mid = low + (high-low)/2;
        }
        if(mid * mid != x) mid--;
        return mid;
    }
};