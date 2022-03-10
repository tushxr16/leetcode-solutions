class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;int i=0,j=0;
        while(i<nums1.size()&& j<nums2.size()){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }else if(nums1[i]==nums2[j]){
                v.push_back(nums1[i]);i++;
                v.push_back(nums2[j]);j++;
            }else{
                v.push_back(nums2[j]);j++;
            }
        }
        while(i<nums1.size()){v.push_back(nums1[i]);i++;}
        while(j<nums2.size()){v.push_back(nums2[j]);j++;}
        double m;
        if(v.size()%2==0){
            m = v[v.size()/2]+v[(v.size()/2) -1];
            m = m/2;
        }
        else 
            m = v[v.size()/2];
        return m;
    }
};