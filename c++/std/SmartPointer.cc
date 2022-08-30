#include <iostream>
#include <algorithm>
#include <memory>
#include "Test.h"
using namespace  std;
int main(int args, const char* argv[])
{
    cout << "Test Begin \n";
    auto shared = std::make_shared<koll::Test>(1, 2);
    cout << "shared poiter counter: " << shared.use_count() << "\n";
    auto shared_incr = shared;
    cout << "shared poiter counter: " << shared.use_count() << "\n";
    auto weak_ptr = std::weak_ptr<koll::Test>(shared);
    cout << "shared poiter counter: " << shared.use_count() << "\n";
    {
        auto t1 = weak_ptr.lock();
        cout << "shared poiter counter: " << shared.use_count() << "\n";
    }
    cout << "shared poiter counter: " << shared.use_count() << "\n";

    int array[] = { 7, 9, 7, 2, 0, 4 }; 
    std::sort(begin(array), end(array), std::less<int>());
    for(auto e:array){
        std::cout << e << " ";
    }
    std::cout << "\n";
}