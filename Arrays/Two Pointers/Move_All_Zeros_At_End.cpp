# Move Zeros to End

## 🧠 Intuition
Order must be preserved → shift non-zero forward

## ⚡ Pattern
Two Pointer / Compaction

## 🚀 Approach
Track first zero index and replace when non-zero comes

## ❌ Mistakes
Initially thought of extra array

## 💻 Code
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n=arr.size();
        int j=0;;
        
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
};
