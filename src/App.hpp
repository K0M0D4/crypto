//
// Created by K0M0D4 on 14.05.2022.
//

#ifndef SC_APP_HPP
#define SC_APP_HPP

#include <string>

namespace cmt {
    class App {
    public:
        App();

    private:
        std::string data{};
        char16_t mode{'c'};
        uint32_t key{};

        void getMode();
        void getInput();
        void getKey();
        void cipher();
        void decipher();
        void output();
    };
}

#endif
