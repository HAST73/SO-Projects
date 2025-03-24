//
// Created by Konrad on 23.03.2025.
//

#include <iostream>
#include <vector>
#include "../Headers/Waiter.h"
#include "../Headers/Philosopher.h"

using namespace std;

int main() {
    // Define the number of philosophers
    int numberPhilosophers;
    cout<<"Welcome to a program where you can solve a philosopher's problem!"<<endl;
    cout<<"First of all, you have to choose a number of philosophers: "<<endl;
    cin>>numberPhilosophers;

    // Create the waiter, who manages fork access
    Waiter waiter(numberPhilosophers);
    vector<Philosopher> philosophers;

    // Creating philosopher objects
    for (int i = 0; i < numberPhilosophers; i++) {
        philosophers.emplace_back(i, waiter);
    }

    // Starting philosopher threads
    for (auto& philosopher : philosophers) {
        philosopher.start();
    }

    // Waiting for all philosopher threads to finish
    for (auto& philosopher : philosophers) {
        philosopher.join();
    }
    return 0;
}
