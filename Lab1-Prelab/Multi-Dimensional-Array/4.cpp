int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == x && j == y) {
                sum1 += arr[i][j];
                sum2 += arr[i][j];
            } else if (i + j == x + y) {
                sum1 += arr[i][j];
            } else if (i - j == x - y) {
                sum2 += arr[i][j];
            }
        }
    }
    return abs(sum1 - sum2);
}
