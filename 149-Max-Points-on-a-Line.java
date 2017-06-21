/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
public class Solution {
    public int maxPoints(Point[] points) {
        if (points.length == 0)
            return 0;
        //Arrays.sort(points, new PointComparator());
        int max = 0;
        for (int i = 0; i < points.length; ++i) {
            System.out.println("for " + String.valueOf(i));
            HashMap<Rational, Integer> hash = new HashMap<Rational, Integer>();
            int tan90 = 0;
            int times = 1;
            int curmax = 0;
            for (int j = 0; j < points.length; ++j) {
                if (i == j) continue;
                Point x = points[i], y = points[j];
                if (equal(x, y)) {
                    times = times + 1;
                    continue;
                }
                
                System.out.println("  ->" + String.valueOf(j));
                if (x.x == y.x) {
                    System.out.println("    tan(90)");
                    curmax = Math.max(curmax, ++tan90);
                } else {
                    Rational rational = new Rational(y.y-x.y, y.x-x.x);
                    System.out.println("    " + rational.toString());
                    Integer count = hash.get(rational);
                    if (count == null) {
                        count = 0;
                    }
                    hash.put(rational, count+1);
                    curmax = Math.max(curmax, count+1);
                }
            }
            max = Math.max(curmax + times, max);
        }
        return max;
    }
    
    public boolean equal(Point x, Point y) {
        return x.x == y.x && y.y == x.y;
    }
    
    class PointComparator implements Comparator<Point>{  
 
        @Override  
        public int compare(Point o1, Point o2) {  
            if (o1.x == o2.x) return o1.y - o2.y;
            return o1.x - o2.x ;
        }  
    }  
    
    public static class Rational {
        private int numerator = 0;      //分子
        private int denominator = 0;    //分母
        
        public Rational(int n, int d) {
            int g = gcd(n, d);
            this.numerator = n / g;
            this.denominator = d / g;
        }
        
        public static int gcd(int a, int b) {
            if (b == 0) return a;
            else return gcd(b, a % b);
        }
        
        public boolean equals(Object o) {
            if (o == null || !(o instanceof Rational)) return false;
            Rational other = (Rational) o;
            return numerator == other.numerator && denominator == other.denominator;
        }
        
        public int hashCode() {
            return numerator*denominator; // doesn't matter if some keys have same hash code
        }
        
        public String toString() {
            return String.valueOf(numerator) + "/" + String.valueOf(denominator);
        }
    }
}
