//
// Created by Konrad on 23.03.2025.
//
#include <vector>
#include <mutex>
#include <condition_variable>

#ifndef SO_PROJECTS_WAITER_H
#define SO_PROJECTS_WAITER_H

using namespace std;

class Waiter {
private:
    int numberPhilosophers;
    vector<bool> forks;
    mutex mtx;
    condition_variable cv;

public:
    Waiter(int numberPhilosophers);
    void requestToEat(int numberOfPhilosopher); // Allows a philosopher to request permission to eat
    void releaseForks(int numberOfPhilosopher); // Releases the forks after philosopher's eating
};


#endif //SO_PROJECTS_WAITER_H
