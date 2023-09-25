#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// #define int long long
#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define print_any(vec)     \
    for (auto value : vec) \
        cout << value << " ";
#define next_line cout << endl;

const int N = 1e5 + 2, MOD = 1e9 + 7;

#include <iostream>

// Function to perform floor division of two number arrays
void floorDivision(int num1[], int len1, int num2[], int len2, int result[], int &resultLen)
{
    int carry = 0;
    int i = 0;
    int j = 0, k  = 0; // Initialize j to 0

    // Check if the divisor is zero
    if (len2 == 1 && num2[0] == 0)
    {
        std::cout << "Division by zero is not allowed." << std::endl;
        resultLen = 0;
        return;
    }

    // Remove leading zeros from the dividend
    while (i < len1 && num1[i] == 0)
    {
        i++;
    }

    // Initialize the result array
    resultLen = len1 - i;
    for (int l = 0; l < resultLen; l++)
    {
        result[l] = 0;
    }

    // Perform floor division
    while (i < len1)
    {
        int currentDigit = num1[i] + carry * 10;

        // Check if the divisor can be subtracted
        if (j < len2 && currentDigit >= num2[j])
        {
            carry = currentDigit % num2[j];
            currentDigit /= num2[j];
            result[k++] = currentDigit; // Add the quotient to the result
        }
        else
        {
            // Append a zero to the result
            result[k++] = 0; // Add a zero to the result
            carry = currentDigit;
        }

        i++;
        if (j < len2)
        {
            j++; // Increment j if it's within bounds
        }
        else
        {
            // Reset j to 0 if it goes beyond the bounds of num2
            j = 0;
        }
    }

    // Remove leading zeros from the result
    while (resultLen > 0 && result[0] == 0)
    {
        for (int l = 0; l < resultLen - 1; l++)
        {
            result[l] = result[l + 1];
        }
        resultLen--;
    }
}

// Function to print an array of digits
void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

int main()
{
    // Define the arrays representing the numbers
    int num1[] = {4, 0, 2, 8, 0};
    int len1 = 5;
    int num2[] = {4, 1};
    int len2 = 2;

    // Initialize the result array
    int result[100]; // You can adjust the size as needed
    int resultLen = 0;

    // Perform floor division
    floorDivision(num1, len1, num2, len2, result, resultLen);

    // Output the result
    std::cout << "Floor division result: ";
    printArray(result, resultLen);

    return 0;
}
