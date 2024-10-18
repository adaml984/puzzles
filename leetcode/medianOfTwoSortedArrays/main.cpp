#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int size = nums1.size();
        int mid = size / 2;

        if(size % 2 == 0) {
            result = (nums1[mid-1] + nums1[mid]) / 2.0;
        }else {
            result = (nums1[mid]);
        }

        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 7};
    double result = Solution().findMedianSortedArrays(nums1, nums2);
    cout<<result<<endl;
    return 0;
}
