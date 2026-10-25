class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int currentSum = 0 ;
        for(int i=0; i<k; i++){
            currentSum += cardPoints[i];
            }
        int maxSum = currentSum;
        int right = n-1;
        for(int left = k-1 ; left >=0 ; left -- ){
                currentSum -= cardPoints[left];
                currentSum += cardPoints[right];
                maxSum = max(currentSum , maxSum);
                right --;
                }
                
        return maxSum;
    }
};