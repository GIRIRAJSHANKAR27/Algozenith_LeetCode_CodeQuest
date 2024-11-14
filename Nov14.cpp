/*
Date: November 14, 2024
Problem: Minimized Maximum of Products Distributed to Any Store
Difficulty: Medium
Time Complexity: O(m log(max(quantities))) where m is the number of products in quantities
Space Complexity: O(1)
The code calculates the minimized maximum quantity of items any store will receive by using binary search to find the smallest possible "maximum quantity" that can be fairly distributed across stores.
Steps:
1) Binary Search Range Initialization: Calculates the search range based on total products and the maximum product quantity.
2) Binary Search on Maximum Quantity per Store: Uses binary search on the possible maximum quantity, adjusting based on feasibility.
3) Feasibility Check (`isPossible` function): Determines if a target maximum quantity per store (`mid`) can be achieved within store limits.
4) Adjusting Search Range: Continuously narrows down the answer by checking mid-values.
*/
class Solution {
public:
    bool isPossible(int n,vector<int>&quantities,int mid){
        int stores=0;
        for(auto x:quantities){
            stores+=x/mid;
            if(x%mid) stores++;
            if(stores>n) return 0;
        }
        return stores<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxi=0;
        long long sum=0;
        for(auto x:quantities){
            sum+=x;
            maxi=max(maxi,x);
        }
        int s=sum/n,e=maxi,ans=-1;
        if(s==0) s=1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(n,quantities,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
