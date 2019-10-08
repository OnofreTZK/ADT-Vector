#include "../include/vector.h"
#include <cassert>

// Author: Tiago Onofre Araujo

int main(int argc, char *argv[])
{
//=============================================================================================
//TESTING INITIALIZERS
//=============================================================================================
    sc::vector<int> V; // default initializer
    sc::vector<int> V2(10); // default initializer.

    assert( V.empty() ); // TEST ( must be empty )
    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - empty test\n";
    assert( V2.empty() ); // TEST ( must be empty )
    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - empty test\n";

    int testArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // test array

    std::cout << "\n>>>testArray = ";
    std::cout << "[ ";
    for( int i = 0; i < 10; i++ )
    {
        std::cout << testArray[i] << " ";
    }
    std::cout << "]\n";

    // Constructor using testArray range.
    sc::vector<int> V3( testArray, testArray + 10); // Range initializer.

    // Printing vector.
    std::cout << "[ ";
    for( int i = 0; i < V3.size(); i++ )
    {
        assert( V3[i] == testArray[i] ); // TEST construction.
        std::cout << V3[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "\x1b[32m[ OK ]\x1b[0m - construction test\n";

    // Constructor using other vector
    sc::vector<int> V4( V3 );

    // Printing vector.
    std::cout << ">>>V4 = ";
    std::cout << "[ ";
    for( int i = 0; i < V4.size(); i++ )
    {
        assert( V4[i] == V3[i] ); // TEST construction.
        std::cout << V4[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "\x1b[32m[ OK ]\x1b[0m - construction test\n";

    // Constructor using initializer list
    sc::vector<int> V5( { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } );

    // Printing vector.
    std::cout << ">>>V5 = ";
    std::cout << "[ ";
    for( int i = 0; i < V5.size(); i++ )
    {
        assert( V5[i] == i + 1 ); // TEST construction.
        std::cout << V5[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "\x1b[32m[ OK ]\x1b[0m - construction test\n";

    // Constructor with operator =

    sc::vector<int> V6 = V5; // = other vector.

    // Printing vector.
    std::cout << ">>>V6 = ";
    std::cout << "[ ";
    for( int i = 0; i < V6.size(); i++ )
    {
        assert( V6[i] == V5[i] ); // TEST construction.
        std::cout << V5[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "\x1b[32m[ OK ]\x1b[0m - construction test\n";

    sc::vector<int> V7 = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 }; // = initializer list.

    std::cout << ">>>V7 = ";
    std::cout << "[ ";
    for( int i = 0; i < V7.size(); i++ )
    {
        std::cout << V7[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "\x1b[32m[ OK ]\x1b[0m - construction test\n";

//=============================================================================================
//TESTING COMMON AND EXCLUSIVE DYNAMIC LIST OPERATIONS
//=============================================================================================
    std::cout << "\n\n\n\n";

    std::cout << "### SIZE() test ###"; //****************************
    std::cout << "\n>>>V size is 0 and size() returned: " << V.size();
    assert( V.size() == 0 );
    std::cout << "\x1b[32m[ OK ]\x1b[0m - method size() test\n";
    std::cout << "\n>>>V2 size is 0 and size() returned: " << V2.size();
    assert( V2.size() == 0 );
    std::cout << "\x1b[32m[ OK ]\x1b[0m - method size() test\n";
    std::cout << "\n>>>V3 size is 10 and size() returned: " << V3.size();
    assert( V3.size() == 10 );
    std::cout << "\x1b[32m[ OK ]\x1b[0m - method size() test\n";
    std::cout << "\n>>>V4 size is 10 and size() returned: " << V4.size();
    assert( V4.size() == 10 );
    std::cout << "\x1b[32m[ OK ]\x1b[0m - method size() test\n";
    std::cout << "\n>>>V5 size is 10 and size() returned: " << V5.size();
    assert( V5.size() == 10 );
    std::cout << "\x1b[32m[ OK ]\x1b[0m - method size() test\n";
    std::cout << "\n>>>V6 size is 10 and size() returned: " << V6.size();
    assert( V6.size() == 10 );
    std::cout << "\x1b[32m[ OK ]\x1b[0m - method size() test\n";
    std::cout << "\n>>>V7 size is 10 and size() returned: " << V7.size();
    assert( V7.size() == 10 );
    std::cout << "\x1b[32m[ OK ]\x1b[0m - method size() test\n";
    std::cout << "\n\n\n\n";

    std::cout << "### CLEAR() test ###"; //****************************

    std::cout << "\n\n>>>V7 before clear()\n ";
    std::cout << ">>>V7 size() = " << V7.size();
    std::cout << "\n[ ";
    for( int i = 0; i < V7.size(); i++ )
    {
        std::cout << V7[i] << " ";
    }
    std::cout << "]\n";

    V7.clear();
    assert( V7.size() == 0 );
    assert( V7.capacity() == 10 ); // TEST clear withou delete space
    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - method clear() test\n";

    std::cout << "\n\n>>>V7 after clear()\n";
    std::cout << ">>>V7 size() = " << V7.size();
    std::cout << "\n[ ";
    for( int i = 0; i < V7.size(); i++ )
    {
        std::cout << V7[i] << " ";
    }
    std::cout << "]\n\n\n\n\n";

    std::cout << "### PUSH e POP test ###"; //****************************

    sc::vector<int> vec = V6;

    //PUSH_BACK-------------------------------------------------------------------------
    // Printing vector
    std::cout << "\n\n>>> vec = [ ";
    for( int i = 0; i < vec.size(); i++ )
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "\n>>vec size = " << vec.size();
    std::cout << "\n>>vec capacity = " << vec.capacity();
    vec.push_back(21);
    std::cout << "\n>>vec size after push_back = " << vec.size();
    std::cout << "\n>>vec capacity after push_back = " << vec.capacity();


    std::cout << "\n\n>>> vec after push_back = [ ";
    for( int i = 0; i < vec.size(); i++ )
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n\n\n";

    //PUSH_FRONT-------------------------------------------------------------------------
    // Printing vector
    std::cout << "\n\n>>> vec = [ ";
    for( int i = 0; i < vec.size(); i++ )
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "\n>>vec size = " << vec.size();
    std::cout << "\n>>vec capacity = " << vec.capacity();
    vec.push_front(-1);
    std::cout << "\n>>vec size after push_front = " << vec.size();
    std::cout << "\n>>vec capacity after push_front = " << vec.capacity();


    std::cout << "\n\n>>> vec after push_front = [ ";
    for( int i = 0; i < vec.size(); i++ )
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n\n\n";

    //POP_BACK-------------------------------------------------------------------------
    // Printing vector
    std::cout << "\n\n>>> vec = [ ";
    for( int i = 0; i < vec.size(); i++ )
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "\n>>vec size = " << vec.size();
    std::cout << "\n>>vec capacity = " << vec.capacity();
    vec.pop_back();
    std::cout << "\n>>vec size after pop_back = " << vec.size();
    std::cout << "\n>>vec capacity after pop_back = " << vec.capacity();


    std::cout << "\n\n>>> vec after pop_back = [ ";
    for( int i = 0; i < vec.size(); i++ )
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n\n\n";

    //POP_FRONT-------------------------------------------------------------------------
    // Printing vector
    std::cout << "\n\n>>> vec = [ ";
    for( int i = 0; i < vec.size(); i++ )
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "\n>>vec size = " << vec.size();
    std::cout << "\n>>vec capacity = " << vec.capacity();
    vec.pop_front();
    std::cout << "\n>>vec size after pop_front = " << vec.size();
    std::cout << "\n>>vec capacity after pop_front = " << vec.capacity();


    std::cout << "\n\n>>> vec after pop_front = [ ";
    for( int i = 0; i < vec.size(); i++ )
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n\n";
    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - push_back(value) test\n";
    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - push_front(value) test\n";
    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - pop_back() test\n";
    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - pop_front() test\n\n\n";

    std::cout << "### FRONT e BACK test ###"; //****************************

    std::cout << "\n\n>>>vec front is 1 and front() returned = " << vec.front();
    std::cout << "\n\n>>>vec back is 10 and back() returned = " << vec.back();

    assert( vec.front() == 1 );
    assert( vec.back() == 10 );

    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - front() test\n\n\n";
    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - back() test\n\n\n";

    std::cout << "\n\n\n";


    std::cout << "### ASSIGN test ###"; //****************************

    sc::vector<int> vec2(10);

    std::cout << "\n\n>>> vec2 = [ ";
    for( int i = 0; i < vec2.size(); i++ )
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << "]\n\n";

    vec2.assign( 10, 5 );
    assert( vec2.size() == 10 );
    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - assign() test\n\n\n";

    std::cout << "\n\n>>> vec after assign = [ ";
    for( int i = 0; i < vec2.size(); i++ )
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << "]\n\n\n\n";

    std::cout << "### SHRINK TO FIT and AT test ###"; //****************************

    std::cout << "\n>>vec size() = " << vec.size();
    std::cout << "\n>>vec capacity() = " << vec.capacity();

    vec.shrink_to_fit();
    assert( vec.size() == vec.capacity() ); // TEST shrinking
    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - shrink_to_fit() test\n\n\n";

    std::cout << "\n>>>vec size after shrink = " << vec.size() << "\n";
    std::cout << "\n>>>vec capacity after shrink = " << vec.capacity() << "\n";

    try {
        vec.at(5) = 6;
    }
    catch( const std::out_of_range & e )
    {
        std::cout << ">>> Exceção capturada! Msg = " << e.what() << std::endl;
    }


    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - at() test\n\n\n\n";

    std::cout << "### COMPARE test ###"; //****************************

    assert( vec == V5 ); // TEST overloading for sc::vector
    assert( vec != vec2 ); // TEST overloading

    std::cout << "\n\x1b[32m[ OK ]\x1b[0m - operator == and != overloadind test\n\n\n\n";



//=============================================================================================
//TESTING OPERATIONS WITH ITERATORS
//=============================================================================================

    std::cout << "===================================\n";
    std::cout << ">>>Iterator Operations testing zone\n";
    std::cout << "===================================\n\n";

    sc::vector<int> VEC3{ 1, 2, 3, 5, 6, 7, 8, 9, 10 };
    sc::vector<int> VEC4 = { 8, 8, 8, 8, 8, 8, 8, 8, 8 };

    //--------------------------------------------------------------------------------------
    //assign - initializer list
    std::cout << "VEC3:\n[ ";
    for( int i = 0; i < VEC3.size(); i++ )
    {
        std::cout << VEC3[i] << " ";
    }
    std::cout << "]\n";

    VEC3.assign( { 1, 2, 8, 0, 34, 56, 78, 94, 100 } );

    std::cout << "VEC3:\n[ ";
    for( int i = 0; i < VEC3.size(); i++ )
    {
        std::cout << VEC3[i] << " ";
    }
    std::cout << "]\n"; 

    //--------------------------------------------------------------------------------------
    //assign - range
    std::cout << "VEC3:\n[ ";
    for( int i = 0; i < VEC3.size(); i++ )
    {
        std::cout << VEC3[i] << " ";
    }
    std::cout << "]\n";

    VEC3.assign(VEC4.begin(), VEC4.end());

    std::cout << "VEC3:\n[ ";
    for( int i = 0; i < VEC3.size(); i++ )
    {
        std::cout << VEC3[i] << " ";
    }
    std::cout << "]\n"; 

    //--------------------------------------------------------------------------------------
    //erase - range
    std::cout << "VEC3:\n[ ";
    for( int i = 0; i < VEC3.size(); i++ )
    {
        std::cout << VEC3[i] << " ";
    }
    std::cout << "]\n";

    VEC3.erase(VEC3.begin(), VEC3.end());

    std::cout << "VEC3:\n[ ";
    for( int i = 0; i < VEC3.size(); i++ )
    {
        std::cout << VEC3[i] << " ";
    }
    std::cout << "]\n"; 

    //--------------------------------------------------------------------------------------
    //erase - pos
    sc::vector<int> VEC5(vec);
    std::cout << "VEC5:\n[ ";
    for( int i = 0; i < VEC5.size(); i++ )
    {
        std::cout << VEC5[i] << " ";
    }
    std::cout << "]\n";

    VEC5.erase(VEC5.begin() + 4);

    std::cout << "VEC5:\n[ ";
    for( int i = 0; i < VEC5.size(); i++ )
    {
        std::cout << VEC5[i] << " ";
    }
    std::cout << "]\n"; 

    //--------------------------------------------------------------------------------------
    //insert - initializer list
    std::cout << "VEC5:\n[ ";
    for( int i = 0; i < VEC5.size(); i++ )
    {
        std::cout << VEC5[i] << " ";
    }
    std::cout << "]\n";

    VEC5.insert( VEC5.begin() + 4, { 2, 23, 67, 89 } );

    std::cout << "VEC5:\n[ ";
    for( int i = 0; i < VEC5.size(); i++ )
    {
        std::cout << VEC5[i] << " ";
    }
    std::cout << "]\n";

    //--------------------------------------------------------------------------------------
    //insert - range
    std::cout << "VEC5:\n[ ";
    for( int i = 0; i < VEC5.size(); i++ )
    {
        std::cout << VEC5[i] << " ";
    }
    std::cout << "]\n";

    VEC5.insert( VEC5.begin() + 4, VEC4.begin(), VEC4.begin() + 4);

    std::cout << "VEC5:\n[ ";
    for( int i = 0; i < VEC5.size(); i++ )
    {
        std::cout << VEC5[i] << " ";
    }
    std::cout << "]\n";

    return 0;
}
