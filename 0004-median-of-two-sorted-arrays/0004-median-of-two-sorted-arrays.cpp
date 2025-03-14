#include <limits.h>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>* left = NULL;
        vector<int>* right = NULL;
        
        int nums1Length = nums1.size();
        int nums2Length = nums2.size();
        if (nums1Length < nums2Length) {
            
            left = &nums1;
            right = &nums2;
        }
        else {
            
            left = &nums2;
            right = &nums1;
        }
        
        int resultLeft = 0;
        int resultRight = 0;
        int leftSize = left[0].size();
        int rightSize = right[0].size();
        
        if (leftSize == 0) {
            if (rightSize % 2 == 0) {
            return (right[0][(rightSize - 1) / 2] + right[0][(rightSize-1) / 2 + 1]) / 2.0;
            }
            else return right[0][(rightSize - 1) / 2];
        }
        else if (rightSize == 0) {
            if (leftSize % 2 == 0) {
            return (left[0][(leftSize - 1) / 2] + left[0][(leftSize-1) / 2 + 1]) / 2.0;
            }
            else return left[0][(leftSize - 1) / 2];
        }
        
        int start = 0;
        int end = nums1Length;
        while (start <= end) {
            
            int positionX = (start + end) / 2;
            int positionY = (nums1Length + nums2Length + 1) / 2 - positionX;
            
            int smallLeftValue = positionX == 0 ? INT_MIN : left[0][positionX-1];
            int largeLeftValue = positionX == leftSize ? INT_MAX : left[0][positionX];
            int smallRightValue = positionY == 0 ? INT_MIN : right[0][positionY-1];
            int largeRightValue = positionY == rightSize ? INT_MAX : right[0][positionY];
            
            if (smallLeftValue <= largeRightValue &&
                largeLeftValue >= smallRightValue) {
            
            resultLeft = max (smallLeftValue, smallRightValue);
            resultRight = min (largeLeftValue, largeRightValue);
            break;
            }
            else if (smallLeftValue <= largeRightValue) {
            
            start = positionX + 1;
            }
            else {
            
            end = positionX - 1;
            }
        }
        
        if ((nums1Length + nums2Length) % 2 == 1) {
            
            return resultLeft;
        }
        else {
            
            return (resultLeft + resultRight) / 2.0;
        }
    }
};