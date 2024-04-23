/**
 * @file Scheduler.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SCHEDULER_HPP_
#define SCHEDULER_HPP_

#include <functional>
#include <thread>
#include <vector>

class Scheduler final
{
public:
    Scheduler();
    Scheduler(const Scheduler &) = delete;
    Scheduler(Scheduler &&) = delete;
    ~Scheduler();
    Scheduler& operator=(const Scheduler &) = delete;
    Scheduler& operator=(Scheduler &&) = delete;

    void start();
    void stop();
    void scheduleTask(std::function<void()> task, const int interval_ms);

private:
    std::vector<std::thread> m_threads;
    bool running {false};
};

#endif
