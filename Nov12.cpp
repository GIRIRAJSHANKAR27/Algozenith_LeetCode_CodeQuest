/*This solution first sorts items by price, then preprocesses them so each items[i][1] reflects the maximum beauty for items with prices up to items[i][0]. 
For each query, a binary search efficiently finds the maximum beauty of items with prices within the query’s limit, producing the desired result in optimal time.
Solution Intuition:
-Sort Items by Price
-Prefix Maximum Array for Beauty
-Binary Search for Each Query
*/
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector <int> ans(queries.size());
        sort(items.begin(),items.end());
        int maxB= items[0][1];
        for(int i=0;i<items.size();i++){
            maxB=max(maxB,items[i][1]);
            items[i][1]=maxB;
        }
        for(int i=0;i<queries.size();i++){
            ans[i]=binarySearch(items,queries[i]);
        }
        return ans;
    }
    
    int binarySearch(vector<vector<int>>& items, int price){
        int l=0;
        int r= items.size()-1;
        int maxB=0;
        while(l<=r){
            int mid = (l+r)/2;
            if(items[mid][0]> price){
                r=mid-1;
            }
            else{
                maxB= max(maxB,items[mid][1]); // imp
                l= mid+1;
            }
        }
        return maxB;
    }
};
