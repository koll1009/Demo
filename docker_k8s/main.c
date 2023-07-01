

#include <unistd.h>
#include <unordered_map>
#include <iostream>
int main(int argc, const char* argv[])
{
    int i = 0;
    std::string exit;
    char** envs = environ;
    for (; *envs; envs++) {
        std::cout << *envs << "\n";
    }
    while (exit.compare("exit")){
        std::cin >> exit;
    }
    return 0;
}