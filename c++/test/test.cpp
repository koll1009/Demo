#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
int main(int argc,char* argv[])
{
    ifstream fs;
    fs.open("test.cpp");
    stringstream buf;
    buf << fs.rdbuf();
    std::string content = buf.str();
    cout << content.c_str() << "\n";
    return 0;
}