#pragma once

class SmallestNumWithDigitsAndSum {
public:
    int getSmallestNum(int numOfDigits, int sumOfDigits);
};

int SmallestNumWithDigitsAndSum::getSmallestNum(int numOfDigits, int sumOfDigits) {
    --sumOfDigits;

    int multiplier = 1;
    int res = 0;
    for(int i = numOfDigits - 1; i > 0; --i) {
        if(sumOfDigits > 9) {
            res += (multiplier * 9);
            sumOfDigits -= 9;
        }
        else {
            res += (multiplier * sumOfDigits);
            sumOfDigits = 0;
        }
        multiplier *= 10;
    }

    res += (multiplier * (sumOfDigits + 1));
    return res;
}