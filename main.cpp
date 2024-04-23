/**
 * @file main.cpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2024-04-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Utils.hpp"
#include "Scheduler.hpp"

#include <chrono>
#include <iostream>
#include <memory>


int main (int argc, char** argv)
{
    std::unique_ptr<Scheduler> scheduler = std::make_unique<Scheduler>();
    scheduler->start();

    scheduler->scheduleTask([](){
        std::cout << "Task id: 1 is processing..." << std::endl;
    }, 5);
    scheduler->scheduleTask([](){
        std::cout << "Task id: 2 is processing..." << std::endl;
    }, 10);
    scheduler->scheduleTask([](){
        std::cout << "Task id: 3 is processing..." << std::endl;
    }, 15);
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return (EXIT_SUCCESS);
}
