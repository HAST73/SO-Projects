#include <iostream>
#include <thread>
#include <condition_variable>
#include <vector>

using namespace std;

mutex mtx;
condition_variable cv;
int numberPhilosophers;
int leftFork, rightFork;
bool condition = true;
vector<bool> forks;


void philosopher(int number){
    leftFork = number;
    rightFork = (number + 1) % numberPhilosophers;

    while(condition){
        this_thread::sleep_for(chrono::seconds(3)); //Thinking
        unique_lock<mutex> lock(mtx); // Blocking common resources
        cv.wait(lock, [] {return forks[leftFork] && forks[rightFork];});
    }


}



int main() {
    cout<<"Welcome to a program where you can solve a philosopher's problem!"<<endl;
    cout<<"First of all, you have to choose a number of philosophers: "<<endl;
    cin>>numberPhilosophers;

    vector<thread> philosophers;
    forks.resize(numberPhilosophers, true);

    for (int i = 0; i < numberPhilosophers; i++) {
        philosophers.emplace_back(thread(philosopher, i));
    }

    for (thread& x : philosophers) {
        x.join();
    }







    return 0;
}
