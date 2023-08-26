#include <iostream>
#include <thread>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    cout << endl;
    cout << "count: " << thread::hardware_concurrency() << endl;

    return 0;
}
