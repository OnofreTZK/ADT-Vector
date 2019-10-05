#include "../include/vector.h"
#include <cassert>

int main(int argc, char *argv[])
{
//===================================================================
//TESTING INITIALIZERS and SIMPLE METHODS
//===================================================================
    sc::vector<int> V; // default initializer
    sc::vector<int> V2(10); // default initializer.

    assert( V.empty() ); // TEST ( must be empty )
    assert( V2.empty() ); // TEST ( must be empty )

    V.push_back(2); // <vector> push_back method

    std::cout << "\n" << V[0] << "\n";


    int testArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // test array(?) kkkkkk

    sc::vector<int> V3( testArray, testArray + 10 ); // content [first, last ) range initializer

    std::cout << "[ ";
    for( int i = 0; i < 10; i++ )
    {
        std::cout << V3[i] << " ";
    }
    std::cout << "]\n";

    assert( !V3.empty() ); // TEST ( must not be empty )
    assert( V3.full() ); // TEST ( must be full )

    std::cout << "\n>>V size = " << V.size();
    std::cout << "\n>>V2 size = " << V2.size();
    V2.push_back(4);
    std::cout << "\n>>V2 after push_back size = " << V2.size();
    std::cout << "\n>>V3 size = " << V3.size();
    V3.push_back(4);
    std::cout << "\n>>V3 after push_back size = " << V3.size();
    std::cout << "\n";
    return 0;
}
