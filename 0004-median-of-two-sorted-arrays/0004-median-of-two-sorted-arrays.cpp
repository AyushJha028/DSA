class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int size = m +n;
        int i = 0;
        int j = 0;
        int k = 0;
        int el1 = -1;
        int el2 = -1;
        int id1 = size/2;
        int id2 = (size/2) - 1;

        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                if(k == id1){
                    el1 = nums1[i];
                }
                
                if(k == id2){
                    el2 = nums1[i];
                }
                i++;
                k++;
            }
            else{
                if(k == id1){
                    el1 = nums2[j];
                }

                if(k == id2){
                    el2 = nums2[j];
                }   
                j++;
                k++;
            }
            
        }

        while(i<m){
            if(k == id1){
                el1 = nums1[i];
            }

            if(k == id2){
                el2 = nums1[i];
            }
            i++;
            k++;
        }

        while(j<n){
            if(k == id1){
                el1 = nums2[j];
            }
            
            if(k == id2){
                el2 = nums2[j];
            }
            j++;
            k++;
        }

        if(size%2 == 0){
            return (el1 + el2) / 2.0;
        }

        return el1;
    }
};