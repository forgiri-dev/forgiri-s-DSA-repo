class Solution {
private:
    long long atmost2(string s){
        int a{}, b{}, c{}, l{}, r{};
        long long ctr{}; 
        
        while(r < s.size()){
            switch (s[r]){
                case 'a':
                    a++;
                    break;
                case 'b':
                    b++;
                    break;
                case 'c':
                    c++;
                    break;
            }
            
            while(a > 0 && b > 0 && c > 0){
                if(s[l] == 'a') a--;
                if(s[l] == 'b') b--;
                if(s[l] == 'c') c--;
                l++;
            }
            
            ctr += r - l + 1;
            r++; 
        }
        return ctr;
    }

public:
    int numberOfSubstrings(string s) {
        long long n = s.size(); 
        long long total = (n * (n + 1)) / 2;
        
        return total - atmost2(s);                           
    }
};