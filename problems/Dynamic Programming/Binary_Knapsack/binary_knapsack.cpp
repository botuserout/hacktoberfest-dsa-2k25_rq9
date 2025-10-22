/*
 * PR Details:
 * Description of Changes:
 *   This PR implements the 0/1 Knapsack problem using dynamic programming.
 *   The 0/1 Knapsack problem is a classic optimization problem where the goal is to maximize the value of items in a knapsack
 *   without exceeding its weight capacity. Each item can either be taken (1) or not taken (0).
 *   The implementation uses a 2D DP table to store the maximum value achievable with a given number of items and weight capacity.
 *  The time complexity of this solution is O(n*W), where n is the number of items and W is the knapsack capacity.
  The space complexity is also O(n*W) due to the DP table.
  This implementation reads item values, weights, and knapsack capacity from standard input and outputs the maximum value achievable.
 * Author: Rakesh Jena
 */

#include <iostream>
#include <algorithm> // For max()
using namespace std;

// Maximum number of items and knapsack capacity
#define MAX_ITEMS 20
#define MAX_CAPACITY 100

int main()
{
    int n, W;                                // n: number of items, W: knapsack capacity
    int val[MAX_ITEMS], wt[MAX_ITEMS];       // val: item values, wt: item weights
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1]; // DP table to store maximum values

    // Read number of items
    cout << "Enter number of items: ";
    cin >> n;

    // Read item values
    cout << "Enter item values:\n";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    // Read item weights
    cout << "Enter item weights:\n";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    // Read knapsack capacity
    cout << "Enter knapsack capacity: ";
    cin >> W;

    // Build DP table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // Base case: 0 items or 0 capacity
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            // If current item's weight is less than or equal to current capacity
            else if (wt[i - 1] <= w)
                // Choose the maximum between including and excluding the current item
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            // If current item's weight exceeds current capacity, exclude it
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Print the maximum value achievable
    cout << "Maximum value = " << dp[n][W] << endl;

    return 0;
}
