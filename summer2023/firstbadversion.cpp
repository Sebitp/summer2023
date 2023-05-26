// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int m){return;}


class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n ,m;

        // bool result = true;
        while(l<=r){
            m = l + (r-l)/2;
            // result = firstBadVersion(temp);
            // if(!isBadVersion(m) && isBadVersion(m-1)){
            //     return m;
            // } else if (!isBadVersion(m) && !isBadVersion(m-1) ){
            //     r = m - 1;
                
            // } else l = m + 1;
            if (isBadVersion(m)){
                r = m-1;
            } else l = m+1;

        }
        return m;
    }
};