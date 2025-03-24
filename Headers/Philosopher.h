//
// Created by Konrad on 23.03.2025.
//

#ifndef SO_PROJECTS_PHILOSOPHER_H
#define SO_PROJECTS_PHILOSOPHER_H


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "../Headers/Waiter.h"

using namespace std;

class Philosopher {
private:
    int id;
    Waiter& waiter; // Reference to the waiter managing forks access
    thread philosopherThread;
    static mutex coutMutex;

public:
    Philosopher(int id, Waiter& waiter);
    void live(); // Simulates the philosopher's life cycle
    void start(); // Starts the philosopher's thread
    void join(); // Waits for the philosopher's thread to complete execution
};


#endif //SO_PROJECTS_PHILOSOPHER_H
