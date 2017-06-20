public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0)
            return 0;
        int maxres = 0;
        int max = prices[0], min = prices[0];
        for (int a : prices) {
            if (min > a) {
                maxres = Math.max(maxres, max - min);
                min = a;
                max = a;
            } else if (max < a) {
                max = a;
            }
        }
        maxres = Math.max(maxres, max - min);
        return maxres;
    }
}
