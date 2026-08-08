class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //you find the boundaries of the array elements within the two arrays
        // first you calculate total elements
        int total = nums1.size() + nums2.size();
        // you determine smaller array to binary search
        if(nums2.size() < nums1.size()){
                swap(nums1, nums2);
        }
        // find the mid of the array to be binary searched
        int l =0, r = nums1.size();
        int half = (total+1) / 2;
        while(l<=r){
            // initial boundary identifier for smaller array 
            int i = (l+r)/2;
            //initial boundary identifier for larger array
            int j = half - i;

            int Aleft = i > 0 ? nums1[i-1] : INT_MIN;
            int Aright = i < nums1.size() ? nums1[i] : INT_MAX;
            int Bleft = j > 0 ? nums2[j-1] : INT_MIN;
            int Bright = j < nums2.size() ? nums2[j]: INT_MAX;

            if(Aleft <= Bright && Aright >= Bleft){
                if(total % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright))/ 2.0;
            } else if (Aleft > Bright){
                r = i - 1;
            } else {
                l = i + 1;
            }

        }
        return -1;
    }
};
