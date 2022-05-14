//
// Created by K0M0D4 on 14.05.2022.
//

#include "App.hpp"

#include <iostream>

namespace cmt {
    App::App() {
        getMode();
        getInput();
        getKey();
        (mode == 'c') ? cipher() : decipher();
        output();
    }

    void App::getMode() {
        std::cout << "Mode(c/d):\n";
        std::string ans{};
        std::cin >> ans;
        mode = ans.front();
    }

    void App::getInput() {
        std::cout << "Data to " << ((mode == 'c') ? "cipher" : "decipher")
            << ":\n";
        std::cin >> data;
    }

    void App::getKey() {
        std::cout << "Key(max. 64):\n";
        std::cin >> key;
        if(key > 64) key = 64;
    }

    void App::cipher() {
        for(int32_t c{0}; c < data.length(); c++) {
            if (c % 3 == 2) {
                data.insert(c, "x");
            } else {
                data[c] = int(data.at(c)) + key;
            }
        }
    }

    void App::decipher() {
        for(int32_t c{(int32_t)data.length()}; c > 0; c--) {
            if(c % 3 == 2) {
                data.erase(c, 1);
            }
        }
        for(int32_t c{0}; c < data.length(); c++) {
            data[c] = int(data.at(c)) - key;
        }
    }

    void App::output() {
        std::cout << "Output: " << data << "\n";
    }
}