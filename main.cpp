class Solution {
    public:
        int isValid(string s) {
            // code here
            int n=s.size(),indx=0,dots=0,nums=0,cnts=0;
            for(int i=0;i<n;i++){
                if((s[i]=='.' || s[i]-48)>=0 && (s[i]-48)<=9){
                    if(indx==i && s[indx]=='0'&&(i+1)!=n && s[i+1]!='.'){
                        return 0;
                    }
                    if(s[i]=='.'){
                        if(nums>255 || nums<0) return 0;
                        dots++;
                        nums=0;
                        indx=i+1;
                        
                    }
                    else{
                        nums=nums*10+(s[i]-48);
                        if(i+1==n|| s[i+1]=='.') cnts++;
                    }
                }else return 0;
            }
            if(dots!=3) return 0;
            if(cnts!=4) return 0;
            return 1;
        }
};
