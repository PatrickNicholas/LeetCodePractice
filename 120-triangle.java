public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int height = triangle.size();
        int[] res = new int[height + 1];
        while (--height >= 0) {
            for (int i = 0; i <= height; ++i) {
                res[i] = Math.min(res[i], res[i+1]) + triangle.get(height).get(i);
            }
        }
        return res[0];
    }
}
