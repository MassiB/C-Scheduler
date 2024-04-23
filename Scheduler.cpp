/**
 * @file Scheduler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Scheduler.hpp"

Scheduler::Scheduler() {}

Scheduler::~Scheduler() {
    this->stop();
    for (auto &t : m_threads){
        if (t.joinable())
            t.join();
    }
    m_threads.clear();
}

void Scheduler::scheduleTask(std::function<void()> task, const int interval_ms) {
    std::thread t([=](){
        while (running) {
            task();
            std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
        }
    });
    m_threads.push_back(std::move(t));
}

void Scheduler::start() {
    running = true;
}

void Scheduler::stop() {
    running = false;
}