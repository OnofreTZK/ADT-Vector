#include "./vector.h"
#include <cassert>

int main(int argc, char *argv[])
{

    sc::vector<int> V;
    sc::vector<int> V2(10);

    assert( V.empty() );
    assert( V2.empty() );

    V.push_back(2);

    std::cout << V.m_data[0] << "\n";
    return 0;
}
