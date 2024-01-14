/*
 * indices.cpp
 *
 *  Created on: Jan 13, 2024
 *      Author: anutejaswisunkara
 */


#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare the number of elements in the array
    int num;
    cin >> num;

    // Initialize a vector to store the input numbers
    vector<int> arr(num); // Using vector for dynamic size

    // Initialize a vector to store the result (indices of the elements)
    vector<int> result(2, -1); // Initialize with -1

    // Loop to read the elements into the array
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    // Declare and read the target sum
    int target;
    cin >> target;

    // Iterate through the array to find the two numbers that sum to the target
    for (int i = 0; i < num; i++) {
        // Calculate the complement of the current number
        int temp = target - arr[i];

        // Nested loop to find the complement in the array
        for (int j = 0; j < num; j++) {
            // Check if the complement is found and it's not the same element
            if (i != j && temp == arr[j]) {
                result[0] = i; // Store the first index
                result[1] = j; // Store the second index
                break; // Exit the inner loop as we found the pair
            }
        }

        // Check if the pair is found and exit the outer loop
        if (result[0] != -1) break;
    }

    // Output the result
    if (result[0] != -1) {
        cout << result[0] << ", " << result[1];
    } else {
        // Output if no pair is found
        cout << "No valid pair found";
    }

    return 0;
}


