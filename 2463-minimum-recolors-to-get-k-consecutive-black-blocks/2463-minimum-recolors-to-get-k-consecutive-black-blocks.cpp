class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int w = 0;
        
        // Count 'W' in the first k-sized window
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') w++;
        }
        
        int ans = w;
        
        // Sliding Window
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') w++;
            if (blocks[i - k] == 'W') w--;
            ans = min(ans, w);
        }
        
        return ans;
    }
};