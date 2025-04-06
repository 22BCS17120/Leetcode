class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>temp(n);
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            temp[i]=i;
            freq[nums[i]]=1;
        }
        int maxi=0,idx=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
                    int val=freq[nums[j]]+1;
                    if(maxi<val){
                        maxi=val;
                        idx=i;
                    }
                    if(freq[nums[i]]<=val){
                        freq[nums[i]]=val;
                        temp[i]=j;
                    }
                }
            }
        }

        vector<int>ans;
        while(idx>=0){
            ans.push_back(nums[idx]);
            if(temp[idx]==idx)break;
            idx=temp[idx];
        }
        return ans;
    }
};