class Solution {
public:
    char findTheDifference(string s, string t) {
        int a = 0;
        int b = 0;
        for(char x: s){
            a += x;
        }
        for(char x: t){
            b += x;
        }
        return b-a;
    }
};