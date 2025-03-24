//
// Created by Konrad on 23.03.2025.
//

#include "../Headers/Philosopher.h"
#include <chrono>

Philosopher::Philosopher(int id, Waiter& waiter) : id(id), waiter(waiter) {}

mutex Philosopher::coutMutex;

void Philosopher::live() {
    while (true) {
        {
            lock_guard<mutex> lock(coutMutex);
            cout << "Philosopher " << id << " is thinking.\n";
        }
        this_thread::sleep_for(chrono::seconds(1));

        // Philosopher requests permission to eat
        waiter.requestToEat(id);

        {
            lock_guard<mutex> lock(coutMutex);
            cout << "Philosopher " << id << " is eating.\n";
        }
        this_thread::sleep_for(chrono::seconds(1));

        // Philosopher releases the forks after eating
        waiter.releaseForks(id);

        {
            lock_guard<mutex> lock(coutMutex);
            cout << "Philosopher " << id << " has finished eating and released forks.\n";
        }
    }
}

// Starts the philosopher's thread
void Philosopher::start() {
    philosopherThread = thread(&Philosopher::live, this);
}

// Waits for the philosopher's thread to complete execution
void Philosopher::join() {
    philosopherThread.join();
}
