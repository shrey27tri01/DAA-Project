#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// utility function to print an array
void printArray(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// finding prime factors of a number using Sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<int> primeNums; // vector of prime factors
    bool isPrime[n + 1]; // check number is prime or not
    memset(isPrime, true, sizeof(isPrime)); // true for all numbers

    // 0 and 1 are not prime numbers
    isPrime[0] = false;
    isPrime[1] = false; 
 
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i] == true) {
            
            // We loop through the multiples of i and mark them to false.
            // e.g. if i = 2 then 4, 6, 8,... have to be marked false but not 2.
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
 
    
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            // if given prime number is multiple of n then we add it to the vector
            if(n % p == 0)
                primeNums.push_back(p);
        }
    }
    return primeNums;
}

int main() {
    int n;
    int num;
    cin >> n;
    vector<vector<int>> results;
    
    for(int i = 0; i < n; i++) {
        cin >> num;
        vector<int>isPrimes = sieve(num);
        results.push_back(isPrimes);
    }

    for(int i = 0; i < results.size(); i++) {
        cout << "Case " << i + 1 << ": ";
        printArray(results[i]);
    }
}