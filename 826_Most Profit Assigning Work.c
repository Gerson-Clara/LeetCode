int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    int i, j, totalProfit = 0;

    for ( i = 0; i < workerSize; i++ ) {
        int job = -1;

        for ( j = 0; j < difficultySize; j++ ) {
            if (worker[i] >= difficulty[j]) {
                if (job == -1) {
                    job = j;
                } else {
                    if ( profit[j] > profit[job] ) {
                        job = j;
                    }
                }
            }
        }

        if ( job != -1 ) {
            totalProfit += profit[job];
        }
    }

    return totalProfit;
}
