//找出有最大合的子陣列

int maxSubArray(int A[], int n) {
    int i;
    int max, local;
    max = A[0];
    local = 0;
    for (i = 0; i < n; i++) {
        local += A[i];
        if (local < A[i])  //如果前面那坨+A[i]本身小於A[i] 那麼就直接從A[i]開始重新累積
            local = A[i];
        if (local > max)
            max = local;
    }
    return max;
}
