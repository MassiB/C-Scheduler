/**
 * @file Utils.hpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2024-04-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>
#include <fstream>
#include <mutex>

static std::mutex logMtx;

void LOG(const char *text) {
    std::lock_guard<std::mutex> guard(logMtx); 
    static std::ofstream output("output.txt");
    if (!output.is_open()) return;

    output << text << std::endl;
    output.close();
}

#endif
