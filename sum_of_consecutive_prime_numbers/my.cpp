#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<bool> is_prime(MAX, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false;

    for (size_t i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (size_t j = i*i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    


    int number;

    while (cin >> number && number != 0)
    {
        // cout << number << " is_prime: " << is_prime[number] << endl;


        int count = 0;
        if (is_prime[number])
            count++;
        if (number == 2) {
            cout << count << endl;
            continue;
        }
            
        
        // int mid = number / 2 + 1;

        int lower = 0;
        int sum = 0;
        for (size_t i = 0; primes[i] <= number/2+1; i++) {
            sum += primes[i];

            while (sum > number)
                sum -= primes[lower++];

            if (sum == number)
                count++;
        }

        cout << count << endl;
    }
    

}