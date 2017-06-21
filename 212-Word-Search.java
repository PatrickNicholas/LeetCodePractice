public class Solution {
        Set<String> res = new HashSet<String>();
    
    public List<String> findWords(char[][] board, String[] words) {
        Trie trie = new Trie();
        for (String word : words) {
            trie.insert(word);
        }
        
        int m = board.length;
        int n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, visited, "", i, j, trie);
            }
        }
        
        return new ArrayList<String>(res);
    }
    
    public void dfs(char[][] board, boolean[][] visited, String str, int x, int y, Trie trie) {
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length) return;
        if (visited[x][y]) return;
        
        str += board[x][y];
        if (!trie.startsWith(str)) return;
        
        if (trie.search(str)) {
            res.add(str);
        }
        
        visited[x][y] = true;
        dfs(board, visited, str, x - 1, y, trie);
        dfs(board, visited, str, x + 1, y, trie);
        dfs(board, visited, str, x, y - 1, trie);
        dfs(board, visited, str, x, y + 1, trie);
        visited[x][y] = false;
    }
    
    public static class Trie {
        public Node root = new Node(' ');
        
        public void insert(String str) {
            char [] s = str.toCharArray();
            Node node = root;
            for (int i = 0; i < s.length; ++i) {
                node = node.getChildAt(s[i]);
            }
            node.endPoint = true;
        }
        
        public boolean startsWith(String str) {
            char [] s = str.toCharArray();
            Node node = root;
            for (int i = 0; i < s.length; ++i) {
                if (!node.hasChildAt(s[i]))
                    return false;
                node = node.getChildAt(s[i]);
            }
            return true;
        }
        
        public boolean search(String str) {
            char [] s = str.toCharArray();
            Node node = root;
            for (int i = 0; i < s.length; ++i) {
                if (!node.hasChildAt(s[i]))
                    return false;
                node = node.getChildAt(s[i]);
            }
            return node.endPoint;
        }
        
        public static class Node {
            public boolean endPoint = false;
            public char ch;
            public List<Node> childs;
            
            public Node(char c) {
                ch = c;
                childs = new ArrayList<Node>();
            }
            
            public Node getChildAt(char c) {
                for (Node node : childs)
                    if (node.ch == c)
                        return node;
                Node node = new Node(c);
                childs.add(node);
                return node;
            }
            
            public boolean hasChildAt(char c) {
                for (Node node : childs) 
                    if (node.ch == c)
                        return true;
                return false;
            }
        }
    }
}
