#ifndef VCTR_H
#define VCTR_H

#include <cstdlib>
#include <iostream>

namespace sc {

    template< typename T >

    class vector
    {

        public:
        //private:
            T *m_data;
            size_t m_capacity;
            size_t m_end;

        //public:

            vector( size_t cap=0 )
            {
                std::cout << "Entrou no construtor!\n";
                std::cout << this << "\n";

                m_data = new T[ cap ];

                m_capacity = cap;
                m_end =0;

            }

            void clear()
            {
                m_end = 0;
            }

            bool empty() const
            {
                return m_end == 0;
            }

            bool full() const
            {
                return m_end == m_capacity;
            }

            ~vector()
            {
                std::cout << "Entrou no destrutor!\n";

                delete[] m_data;
            }

            void reserve( size_t ncap )
            {

                if( m_capacity == 0 )
                {
                    ncap = 1;
                    m_capacity = 1;
                }

                T *temp = new T[ncap];

                for( int i = 0; i < m_capacity; i++ )
                {
                    temp[i] = m_data[i];
                }

                delete[] m_data;

                m_data = temp;

                m_capacity = ncap;
            }

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
