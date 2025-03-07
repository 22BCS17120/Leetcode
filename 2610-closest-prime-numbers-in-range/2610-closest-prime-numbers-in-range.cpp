class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int minimum = 10000, lastNum = 0;
        int min1, min2, cont, diff;

        if (left == 1) left = 2;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                lastNum = i;
                cont = i;
                break;
            }
        }
        for (int i = cont + 1; i <= right; i++) {
            if (isPrime(i)) {
                diff = i - lastNum;
                if (diff <= 2)
                    return {lastNum, i};
                if (diff < minimum) {
                    minimum = diff;
                    min1 = lastNum;
                    min2 = i;
                }
                lastNum = i;
            }
        }

        if (minimum != 10000)
            return {min1, min2};
        return {-1, -1};
    }

    bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};