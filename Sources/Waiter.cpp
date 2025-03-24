//
// Created by Konrad on 23.03.2025.
//

#include "../Headers/Waiter.h"

Waiter::Waiter(int numberPhilosophers) : numberPhilosophers(numberPhilosophers), forks(numberPhilosophers, true) {}

// Allows a philosopher to request permission to eat
void Waiter::requestToEat(int numberOfPhilosopher) {
    int leftFork = numberOfPhilosopher;
    int rightFork = (numberOfPhilosopher + 1) % numberPhilosophers;

    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [this, leftFork, rightFork] { return forks[leftFork] && forks[rightFork]; });

    // Grant forks to the philosopher
    forks[leftFork] = false;
    forks[rightFork] = false;
}

// Releases the forks after philosopher's eating
void Waiter::releaseForks(int numberOfPhilosopher) {
    int leftFork = numberOfPhilosopher;
    int rightFork = (numberOfPhilosopher + 1) % numberPhilosophers;

    lock_guard<mutex> lock(mtx);

    // Release forks
    forks[leftFork] = true;
    forks[rightFork] = true;

    // Notify waiting philosophers that forks are now available
    cv.notify_all();
}