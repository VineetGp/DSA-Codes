class Solution:
    def mySqrt(self, x: int) -> int:
        low = 0
        high = x
        mid = 0
        while(low<=high):
            mid = (low+high)//2
            if mid*mid<=x and (mid+1)*(mid+1)>x:
                return mid
            elif mid*mid<x:
                low = mid+1
            else:
                high = mid-1
        return low