class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ones=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1) ones++;
        }

        if(ones==0) return 1;

        for(int i=0;i<n;i++){
            if(nums[i]<1 || nums[i]>n) nums[i]=1;
        }

        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x-1]>0) nums[x-1]=-nums[x-1];
        }
        int ans=n+1;
        for(int i=0;i<n;i++) if(nums[i]>0) return i+1;
        return ans;
    }
};
