/*
 * File: main.cpp
 * Purpose: Print even and odd numbers using multithreading
 * Author: Meena
 * Date: 24-Jun-2025
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int counter = 0;
std::mutex mtx;
std::condition_variable cv;
bool isEvenTurn = true;

void printEven() {
    while (counter <= 10) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [](){ return isEvenTurn; });

        if (counter <= 10 && counter % 2 == 0) {
            std::cout << "Even: " << counter << std::endl;
            counter++;
            isEvenTurn = false;
            cv.notify_all();
        }
    }
}

void printOdd() {
    while (counter <= 10) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [](){ return !isEvenTurn; });

        if (counter <= 10 && counter % 2 != 0) {
            std::cout << "Odd: " << counter << std::endl;
            counter++;
            isEvenTurn = true;
            cv.notify_all();
        }
    }
}

int main() {
    std::thread evenThread(printEven);
    std::thread oddThread(printOdd);
    evenThread.join();
    oddThread.join();
    return 0;
}
