c class Solution {
    public int reverse(int x) {
        int rev = 0;
         while(x!=0)
         {
             if (rev != 0 && Integer.MAX_VALUE / rev < 10
                       && Integer.MAX_VALUE / rev > -10)
                   return 0;
             rev = rev*10 + x%10;
             x = x/10;
         }
         
         return rev;
    }
}
