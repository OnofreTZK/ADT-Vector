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

    sc::vector<int> V4(V3);

    std::cout << "[ ";
    for( int i = 0; i < V4.size(); i++ )
    {
        std::cout << V4[i] << " ";
    }
    std::cout << "]\n";


    sc::vector<int> V5 = V4;

    std::cout << "[ ";
    for( int i = 0; i < V5.size(); i++ )
    {
        std::cout << V5[i] << " ";
    }
    std::cout << "]\n";

    sc::vector<int> V6( testArray, testArray + 10 );

    assert( V6.front() == 1 ); // TEST front method
    assert( V6.back() == 10 ); // TEST back method


    std::cout << "\nV6\n[ ";
    for( int i = 0; i < V6.size(); i++ )
    {
        std::cout << V6[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "V6 size = " << V6.size() << "\n";
    std::cout << "V6 capacity = " << V6.capacity() << "\n";
    V6.push_back(11);
    std::cout << "\n";

    std::cout << "[ ";
    for( int i = 0; i < V6.size(); i++ )
    {
        std::cout << V6[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "V6 size after push back = " << V6.size() << "\n";
    std::cout << "V6 capacity after push back = " << V6.capacity() << "\n";

    V6.clear();

    assert( V6.size() == 0 ); // TEST size after clear.
    assert( V6.capacity() == 20 ); // TEST capacity after clear.

    std::cout << "[ ";
    for( int i = 0; i < V6.size(); i++ )
    {
        std::cout << V6[i] << " ";
    }
    std::cout << "]\n";



    sc::vector<int> V7 = V5;

    std::cout << "\nV7\n[ ";
    for( int i = 0; i < V7.size(); i++ )
    {
        std::cout << V7[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "V7 size = " << V7.size() << "\n";
    std::cout << "V7 capacity = " << V7.capacity() << "\n";
    V7.push_front(50);
    std::cout << "\n";

    std::cout << "[ ";
    for( int i = 0; i < V7.size(); i++ )
    {
        std::cout << V7[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "V7 size after push front = " << V7.size() << "\n";
    std::cout << "V7 capacity after push front = " << V7.capacity() << "\n";

    for( int i = 0; i < V7.size(); i++ )
    {
        std::cout << V7[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "V7 size = " << V7.size() << "\n";
    std::cout << "V7 capacity = " << V7.capacity() << "\n";

    V7.pop_back();
    std::cout << "\n";

    std::cout << "[ ";
    for( int i = 0; i < V7.size(); i++ )
    {
        std::cout << V7[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "V7 size after pop back = " << V7.size() << "\n";
    std::cout << "V7 capacity after pop back = " << V7.capacity() << "\n";

    V7.pop_front();
    std::cout << "\n";

    std::cout << "[ ";
    for( int i = 0; i < V7.size(); i++ )
    {
        std::cout << V7[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "V7 size after pop front = " << V7.size() << "\n";
    std::cout << "V7 capacity after pop front = " << V7.capacity() << "\n";

    assert( V7.front() == 1 ); // TEST front
    assert( V7.back() == 10 ); // TEST back

    sc::vector<int> V8(10);

    std::cout << "[ ";
    for( int i = 0; i < V8.size(); i++ )
    {
        std::cout << V8[i] << " ";
    }
    std::cout << "]\n";

    V8.assign(10, 5);

    std::cout << "[ ";
    for( int i = 0; i < V8.size(); i++ )
    {
        std::cout << V8[i] << " ";
    }
    std::cout << "]\n";

    V7.shrink_to_fit();

    assert( V7.size() == V7.capacity() ); // TEST shrinking

    std::cout << "\n>>>V7 size after shrink = " << V7.size() << "\n";
    std::cout << "\n>>>V7 capacity after shrink = " << V7.capacity() << "\n";

    // COMPARE OPERATORS

    assert( V5 == V4 ); // TEST overloading for sc::vector
    assert( V8 != V5 ); // TEST overloading

    sc::vector<int> V9{ 1, 2, 3, 4, 5 };

    std::cout << "[ ";
    for( int i = 0; i < V9.size(); i++ )
    {
        std::cout << V9[i] << " ";
    }
    std::cout << "]\n";
    return 0;
}
