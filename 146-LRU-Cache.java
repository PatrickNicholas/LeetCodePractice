public class LRUCache {

    public int capacity;
    public HashMap<Integer, Entry> map;
    public Entry head;
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
    }
    
    private void promote(Entry entry) {
        if (entry == head) 
            return;
        
        Entry prev = entry.prev;
        Entry next = entry.next;
        prev.next = next;
        next.prev = prev;
        
        entry.next = head;
        entry.prev = head.prev;
        head.prev.next = entry;
        head.prev = entry;
        
        head = entry;
    }
    
    public int get(int key) {
        //System.out.println("get:" + String.valueOf(key));
        if (!map.containsKey(key))
            return -1;
        Entry entry = map.get(key);
        promote(entry);
        return entry.value;
    }
    
    private void insert(int key, int value) {
        Entry entry;
        if (map.size() == capacity) {
            entry = head.prev;
            //System.out.println("  replace " + String.valueOf(entry.key) + " with " + String.valueOf(key));
            map.remove(entry.key);
            entry.key = key;
            entry.value = value;
            promote(entry);
        } else {
            entry = new Entry(key, value);
            entry.next = entry;
            entry.prev = entry;
            //System.out.println("  insert " + String.valueOf(entry.key));
            if (head != null) {
                promote(entry);
            }
            head = entry;
        }
        map.put(key, entry);
    }
    
    public void put(int key, int value) {
        //System.out.println("put:" + String.valueOf(key));
        if (!map.containsKey(key)) {
            insert(key, value);
        } else {
            Entry entry = map.get(key);
            entry.value = value;
            promote(entry);
        }
    }
    
    public class Entry {
        int key;
        int value;
        Entry prev;
        Entry next;
        
        public Entry(int k, int v) {
            key = k;
            value = v;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
