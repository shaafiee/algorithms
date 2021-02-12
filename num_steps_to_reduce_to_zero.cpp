class Solution {
public:
    int doSteps (int num, int steps) {
        if (num > 1) {
            if (num%2 == 0) {
                steps++;
                num = num / 2;
            } else {
                num--;
                steps++;
            }
            if (num > 1) {
                steps = doSteps(num, steps);
            } else {
                steps++;
                return steps;
            }
        } else {
            steps++;
            return steps;
        }
        return steps;
    }
    
    int numberOfSteps (int num) {
        if (num == 0) {
            return 0;
        }
        return doSteps(num, 0);
    }
};
