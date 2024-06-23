bool lemonadeChange(int* bills, int billsSize) {
    int i, five, ten, twenty;
    five = 0;
    ten = 0;
    twenty = 0;
    

    if (bills[0] == 20 || bills[0] == 10) {
        return false;
    }

    for (i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five += 1;
        } else if (bills[i] == 10) {
            five -= 1;
            if (five < 0) {
                return false;
            }
            ten += 1;
        } else {
            if (ten == 0) {
                five -= 3;
            } else {
                five -= 1;
                ten -= 1;
            }
            if (ten < 0 || five < 0) {
                return false;
            }
            twenty += 1;
        }
    }

    return true;
}
