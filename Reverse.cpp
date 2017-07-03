class Reverse {
public:
    string reverseString(string iniString) {
        // write code here
        int i,idx=0,n=iniString.size();
        for(i=0;i<n/2;i++){
            swap(iniString[i],iniString[n-i-1]);
        }
        return iniString;
    }
};
