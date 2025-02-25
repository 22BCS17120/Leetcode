class Solution {
public:
    int mod = 1000000007; // Define a large prime number for modulo operation to prevent overflow

    int numOfSubarrays(vector<int>& arr) {
        long long sum = 0; // This variable keeps track of the cumulative sum of elements
        int odd = 0; // Counter for subarrays with an odd sum
        int even = 0; // Counter for subarrays with an even sum
        long long ans = 0; // Stores the final answer (count of subarrays with odd sum)

        for (int i = 0; i < arr.size(); i++) { 
            sum += arr[i]; // Update the cumulative sum by adding the current element
            
            if (sum % 2 == 1) { // If the sum is odd
                odd++; // Increment the odd counter
                ans += even + 1; // Any even sum encountered before can form an odd sum with this one
            } else { // If the sum is even
                even++; // Increment the even counter
                ans += odd; // Any previous odd sum can form a new odd subarray with this one
            }
        }

        return ans % mod; // Return the count of subarrays with an odd sum, ensuring it's within mod
    }
};