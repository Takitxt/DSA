class Solution {
public:
    bool isAnagram(string s, string t) {
        int lenS= s.length();
        int lenT = t.length();
        int sum =0;
        if(lenS!=lenT){
            return false;
        }

        for(int i=0; i<lenS;i++){
            for(int j=0;j<lenT;j++){
                if(s[i]==t[j]){
                    sum+=1;
                    t[j]= ' ';
                    break;

                }
            }
        }
        if(lenS == sum){
            return true;
        }
        return false;
        
    }
};