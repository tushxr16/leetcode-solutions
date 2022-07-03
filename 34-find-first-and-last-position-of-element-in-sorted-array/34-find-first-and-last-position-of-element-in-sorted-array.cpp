class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int lo = 0, hi = arr.size()-1, found_low = -1, found_high = -1, mid;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(arr[mid]>target){
                hi = mid-1;
            }else if(arr[mid]<target){
                lo = mid+1;
            }else{
                found_low = mid;
                hi = mid-1;
            }
        }
        lo = 0, hi = arr.size()-1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(arr[mid]>target){
                hi = mid-1;
            }else if(arr[mid]<target){
                lo = mid+1;
            }else{
                found_high = mid;
                lo = mid+1;
            }
        }
        return {found_low,found_high};
    }
};