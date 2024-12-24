int findTheWinner(int n, int k) {
    int winner = 0; // Base case: when there's only one person
    for (int i = 2; i <= n; ++i) {
        winner = (winner + k) % i;
    }
    return winner + 1; // Convert 0-indexed to 1-indexed
}