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
            size_t m_capacity; // size
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

            // other vector parameter constructor
            vector( const vector & other )
            {
                m_data = new T[other.size()];

                m_end =0;

                m_capacity = other.size();

                for( int i = 0; i < other.size(); i++ )
                {
                    m_data[i] = other[i];
                    m_end++;
                }
            }

            // initializer list parameter constructo
            vector( std::initializer_list<T> ilist )
            {
                m_data = new T[ilist.size()];

                m_capacity = ilist.size();

                m_end =0;

                for( int i = 0; i < ilist.size(); i++ )
                {
                    m_data[i] = *(ilist.begin()+i);
                    m_end++;
                }
            }

            // default destructor
            ~vector()
            {
                delete[] m_data;
            }

            // assign operator constructors
            vector& operator=( const vector& other )
            {
                m_data = new T[other.size()];

                m_end =0;

                m_capacity = other.size();

                for( int i = 0; i < other.size(); i++ )
                {
                    m_data[i] = other[i];
                    m_end++;
                }
            }

            vector& operator=( std::initializer_list<T> ilist )
            {
                m_data = new T[ilist.size()];

                m_capacity = ilist.size();

                m_end =0;

                for( int i = 0; i < ilist.size(); i++ )
                {
                    m_data[i] = ilist[i];
                    m_end++;
                }
            }

            // end of constructors and destructors

            // FILL/ASSIGN
            void assign( size_t count, const T & element )
            {
                if( count > m_capacity )
                {
                    throw std::out_of_range("Number of copies out of range!\n");
                }

                for( int i = 0; i < count; i++ )
                {
                    m_data[i] = element;
                    m_end++;
                }
            }

            // clear elements in array.
            void clear()
            {
                m_end = 0;

                T * temp = new T[m_capacity];

                delete[] m_data;

                m_data = temp;

            }

            // Check space in array.
            bool empty() const
            {
                return m_end == 0;
            }

            bool full() const
            {
                return m_end == m_capacity;
            }

            // access front element
            T& front() { return m_data[0]; }
            const T& front() const { return m_data[0]; }

            // access back element
            T& back() { return m_data[m_end - 1]; }
            const T& back() const { return m_data[m_end - 1]; }

            // Return logical size
            const size_t size() const { return m_end; }

            // Return maximum capacity.
            const size_t capacity() const { return m_capacity; }
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

                    T& operator->( void ){ return *ptr; };

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

                    std::ptrdiff_t operator-( const iterator & rhs ) const{ return ptr - rhs.ptr; }

                    T& operator-( size_t offset ) const{ return iterator( ptr - offset ); }
                    // normal pointer decrement is accepted.
                    // return a new iterator using contructor pointer - integer value.

                    // --it
                    T& operator--( void ) { ptr--; return *this; }

                    // it--
                    T& operator--( int )
                    {
                        iterator temp_clone( *this );
                        ptr--;
                        return temp_clone;
                    }

                    bool operator==( const iterator & rhs )
                    { return this->ptr == rhs.ptr; }

                    bool operator!=( const iterator & rhs )
                    { return this->ptr != rhs.ptr; }






            };


            // CLASS CONST ITERATOR ===========================================

            class const_iterator
            {
                private:
                    const T *ptr;

                public:

                    // Basic pointer arithmetic is hardly used here.
                    // default const iterator constructor
                    const_iterator( const T * pt=nullptr ) : ptr{ pt } {}

                    // default copy construtor ( Itr ptr2( ptr ) )
                    const_iterator( const_iterator & ) = default;

                    // default destructor
                    ~const_iterator( void ) = default;

                    // operator 'pointer to'( *it = value )
                    const T& operator*( void ) const{ return *ptr; };

                    const T& operator->( void ) const{ return *ptr; };

                    // sum operator +
                    T& operator+( size_t offset ) const{ return const_iterator( ptr + offset ); }
                    // normal pointer increment is accepted.
                    // return a new iterator using contructor pointer + integer value.

                    // INCREMENTS ( ++it and it++ )
                    // ++it
                    T& operator++( void ){ ptr++; return *this; }

                    // it++
                    T& operator++( int )
                    {
                        const_iterator temp_clone( *this );
                        ptr++;
                        return temp_clone;
                    }

                    T& operator-( size_t offset )const{ return const_iterator( ptr - offset ); }
                    // normal pointer decrement is accepted.
                    // return a new iterator using contructor pointer - integer value.

                    // --it
                    T& operator--( void ){ ptr--; return *this; }

                    // it--
                    T& operator--( int )
                    {
                        const_iterator temp_clone( *this );
                        ptr--;
                        return temp_clone;
                    }

            };

            iterator begin( void ){ return iterator( &m_data[0] ); }
            const_iterator cbegin( void )const{ return const_iterator( &m_data[0] ); }

            iterator end( void ){ return iterator( &m_data[m_end] ); }
            const_iterator cend( void ){ return const_iterator( &m_data[m_end] ); }
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

            // Insert element in first position and increase logical index.
            void push_front( const T & element )
            {
                if( full() )
                {
                    reserve( 2 * m_capacity );
                }

                for( int i = m_end; i > 0; i-- )
                {
                    m_data[i] = m_data[i-1];
                }

                this->m_data[ 0 ] = element;

                m_end++;
            }

            // Remove element in last position.
            void pop_back( void )
            {
                if( m_end == 0 )
                {
                    return;
                }

                this->m_data[ m_end-- ] = T();
            }

            // Remove element in first position.
            void pop_front( void )
            {
                if( m_end == 0 )
                {
                    return;
                }

                for( int i = 0; i < m_end - 1; i++ )
                {
                    m_data[i] = m_data[i+1];
                }

                m_end--;
            }

            void shrink_to_fit()
            {
                T * temp = new T[this->size()];

                for( int i = 0; i < this->size(); i++ )
                {
                    temp[i] = m_data[i];
                }

                delete[] m_data;

                m_data = temp;

                m_capacity = m_end;
            }


    };
}

// OPERATORS OVERLOADING =============================================


template< typename T >

bool operator== ( const sc::vector<T>& lhs, const sc::vector<T>& rhs )
{
    if( lhs.size() != rhs.size() )
    {
        return false;

    }

    for( int i = 0; i < lhs.size(); i++ )
    {
        if( lhs[i] != rhs[i] )
        {
            return false;
        }
    }

    return true;

}

template< typename T >

bool operator!= ( const sc::vector<T>& lhs, const sc::vector<T>& rhs )
{
    if( lhs.size() != rhs.size() )
    {
        return true;

    }

    for( int i = 0; i < lhs.size(); i++ )
    {
        if( lhs[i] != rhs[i] )
        {
            return true;
        }
    }

    return false;

}
#endif
