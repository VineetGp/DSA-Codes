class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle=='':
            return 0
        len1 = len(haystack)
        len2 = len(needle)
        if len1 < len2:
            return -1
        for i in range(len1-len2+1):
            if haystack[i:i+len2] == needle:
                return i
        return -1