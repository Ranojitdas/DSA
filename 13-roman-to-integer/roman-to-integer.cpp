class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'I'){
                if(s[i+1] == 'V' or s[i+1]=='X'){
                    sum+=0;
                }else{
                    sum += 1;
                }
            }else if(s[i]=='V'){
                if(i>0 and s[i-1] == 'I'){
                    sum+=4;
                }else{
                     sum+=5;
                }
            } else if(s[i]=='X'){
                if(i>0 and s[i-1] == 'I'){
                    sum+=9;
                }else{
                    if(s[i+1] == 'L' or s[i+1]=='C'){
                    sum+=0;
                }else{
                    sum += 10;
                }
                }
            }else if(s[i]=='L'){
                if(i>0 and s[i-1] == 'X'){
                    sum+=40;
                }else{
                    sum+=50;
                }  
            }else if(s[i]=='C'){
                if(i>0 and s[i-1] == 'X'){
                    sum+=90;
                }else{
                    if(s[i+1] == 'D' or s[i+1]=='M'){
                    sum+=0;
                }else{
                    sum += 100;
                }
                }
                
            }else if(s[i]=='D'){
                if(i>0 and s[i-1] == 'C'){
                    sum+=400;
                }else{
                    sum+=500;
                }
            } else if(s[i]=='M'){
                if(i>0 and s[i-1] == 'C'){
                    sum+=900;
                }else{
                    sum+=1000;
                }
            }
        }
        return sum;
    }
};