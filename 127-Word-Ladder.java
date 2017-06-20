public class Solution {
    public int ladderLength(String start, String end, Set<String> dict) {
      // Use queue to help BFS
      Queue<String> queue = new LinkedList<String>();
      queue.add(start);
      queue.add(null);
      
      // Mark visited word
      Set<String> visited = new HashSet<String>();
      visited.add(start);
      
      int level = 1;
      
      while (!queue.isEmpty()) {
        String str = queue.poll();
        
        if (str != null) {
          // Modify str's each character (so word distance is 1)
          for (int i = 0; i < str.length(); i++) {
            char[] chars = str.toCharArray();
            
            for (char c = 'a'; c <= 'z'; c++) {
              chars[i] = c;
              
              String word = new String(chars);
              
              
              // Put it to the queue
              if (dict.contains(word) && !visited.contains(word)) {
                queue.add(word);
                visited.add(word);
                
                // Found the end word
                if (word.equals(end)) return level + 1;
              }
            }
          }
        } else {
          level++;
          
          if (!queue.isEmpty()) { 
            queue.add(null);
          }
        }
      }
      
      return 0;
    }
    
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> stringSets = new HashSet<String>();
        for (String s: wordList) {
            stringSets.add(s);
        }
        return ladderLength(beginWord, endWord, stringSets);
    }
}
