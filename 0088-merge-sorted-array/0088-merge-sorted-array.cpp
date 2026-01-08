class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int left = m - 1, right = n - 1;
        
        for (int pivot = nums1.size() - 1; left >= 0 && right >= 0; pivot--) {

            if (nums1[left] > nums2[right]) nums1[pivot] = nums1[left--];
            else nums1[pivot] = nums2[right--];
        }
    }
};