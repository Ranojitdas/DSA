int SquaredValue(int a){
    int sum = 0;
    while(a != 0){
    int d = a % 10;
    sum = sum + d*d;
    a = a/10;
    }
return sum;   
}


class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        int res;
        while(fast != 1){
            slow = SquaredValue(slow);
            fast = SquaredValue(fast);
            fast = SquaredValue(fast);

            if(slow == fast){
                if(slow == 1){
                    res = 1;
                    break;
                } else {
                    res = 0;
                    break;
                }
            }
        }

        if(res == 0){
            return false;
        } else return true;
    }
};