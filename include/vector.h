#ifndef VCTR_H
#define VCTR_H

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <iterator>

namespace sc {

    template< typename T >

    class vector
    {

        private:
            T *m_data; // array
            size_t m_capacity; // logical capacity
            size_t m_end; // logical index

        public:

            // CONSTRUCTORS and DESTRUCTORS

            // default constructor.
            vector( size_t cap=0 )
            {
                m_data = new T[ cap ];

                m_capacity = cap;
                m_end =0;

            }

            // range content constructor
            template< typename InputIt >

            vector( InputIt first, InputIt last )
            {
                size_t distance = std::distance( first, last );

                m_data = new T[distance];

                m_capacity = distance;

                m_end =0;

                for( int i = 0; i < distance ; i++ )
                {
                    m_data[i] = *(first);
                    m_end++;
                    first++;
                }
            }

            vector( const vector & other )
            {
                
            }

            // clear elements in array( change logical index ).
            void clear()
            {
                m_end = 0;
            }

            // Check the free space in array.
            bool empty() const
            {
                return m_end == 0;
            }

            bool full() const
            {
                return m_end == m_capacity;
            }
            //===============================

            // default destructor
            ~vector()
            {
                delete[] m_data;
            }

            size_t size() { return m_capacity; }
            //===================================================================



            // CLASS ITERATOR ===================================================

            class iterator
            {
                private:
                    T *ptr;

                public:

                    // Basic pointer arithmetic is hardly used here.
                    // default iterator constructor
                    iterator( T * pt=nullptr ) : ptr{ pt } {}

                    // default copy construtor ( Itr ptr2( ptr ) )
                    iterator( const iterator & ) = default;

                    // default destructor
                    ~iterator( void ) = default;

                    // assign operator ( it = it2 )
                    iterator& operator=( iterator& rhs ) // right hand side
                    { this->ptr = rhs.ptr; return *this; }

                    // operator 'pointer to'( *it = value )
                    T& operator*( void ){ return *ptr; };

                    // sum operator +
                    T& operator+( size_t offset ) const{ return iterator( ptr + offset ); }
                    // normal pointer increment is accepted.
                    // return a new iterator using contructor pointer + integer value.

                    // INCREMENTS ( ++it and it++ )
                    // ++it
                    T& operator++( void ) { ptr++; return *this; }

                    // it++
                    T& operator++( int )
                    {
                        iterator temp_clone( *this );
                        ptr++;
                        return temp_clone;
                    }

                    bool operator==( const iterator & rhs )
                    { return this->ptr == rhs.ptr; }

                    bool operator!=( const iterator & rhs )
                    { return this->ptr != rhs.ptr; }






            };
            //=================================================================



            // INDEX OPERATOR [] ==============================================

            // without verification

            T & operator[]( size_t index )
            {
                return m_data[index];
            }

            const T & operator[]( size_t index ) const
            {
                return m_data[index];
            }

            // with verification

            T & at( size_t index )
            {
                if( index >= m_capacity )
                  throw std::out_of_range("Position out of range!\n");

                return m_data[index];
            }

            const T & at( size_t index ) const
            {
                if( index >= m_capacity )
                  throw std::out_of_range("Position out of range!\n");

                return m_data[index];
            }


            // SPACE MANIPULATION============================================

            // reserve space in memory( allocating ).
            void reserve( size_t ncap )
            {

                if( m_capacity == 0 )
                {
                    ncap = 1;
                    m_capacity = 1;
                }

                T * temp = new T[ncap];


                for( int i = 0; i < m_capacity; i++ )
                {
                    temp[i] = m_data[i];
                }

                delete[] m_data;

                m_data = temp;

                m_capacity = ncap;
            }

            // Insert element in last position and increase logical index.
            void push_back( const T & element )
            {
                if( full() )
                {
                    reserve( 2 * m_capacity );
                }

                this->m_data[ m_end++ ] = element;
            }
    };
}

#endif
