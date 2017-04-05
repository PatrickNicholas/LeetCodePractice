class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        double pre=0;
        double cur=1;
        do
        {
            pre=cur;
            cur=(pre+x/pre)/2;
        }while(abs(cur-pre)>0.00001);
        return cur;
    }
};
