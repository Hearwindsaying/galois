#include <galois++/element.h>
#include <galois++/field.h>
#include <galois++/primes.h>
#include <iostream>

using namespace std;


template<unsigned int M, unsigned int N, unsigned int R>
void matrixMul(const Galois::Element (&m1)[M*N], const Galois::Element (&m2)[N*R], Galois::Element (&temp)[M*R])
{
    for (unsigned int i = 0; i < M; ++i) {
        for (unsigned int j = 0; j < R; ++j) {
            Galois::Element sum(m1[0].field());
            for (unsigned int k = 0; k < N; ++k) {
                Galois::Element ik = m1[i*N + k];
                Galois::Element kj = m2[k*R + j];
                sum += ik * kj;
            }
            temp[i*R + j] = sum;
        }
    }
}

template<unsigned int M, unsigned int N>
void displayMatrix(const Galois::Element(&m)[M*N])
{
#define RT_MATRIX_ACCESS(m,i,j) m[i*N+j]
    for (unsigned int i = 0; i < M; ++i) {
        for (unsigned int j = 0; j < N; ++j) {
            cout << RT_MATRIX_ACCESS(m, i, j) << " ";
        }
        cout << endl;
    }
}

int main(int argc, const char* argv[])
{
    Galois::Field gf(4);
    Galois::Element B1[16 * 2] = {Galois::Element(&gf,0),Galois::Element(&gf,0),
                                  Galois::Element(&gf,0),Galois::Element(&gf,1),
                                  Galois::Element(&gf,0),Galois::Element(&gf,2),
                                  Galois::Element(&gf,0),Galois::Element(&gf,3),
                                  Galois::Element(&gf,1),Galois::Element(&gf,0),
                                  Galois::Element(&gf,1),Galois::Element(&gf,1),
                                  Galois::Element(&gf,1),Galois::Element(&gf,2),
                                  Galois::Element(&gf,1),Galois::Element(&gf,3),
                                  Galois::Element(&gf,2),Galois::Element(&gf,0),
                                  Galois::Element(&gf,2),Galois::Element(&gf,1),
                                  Galois::Element(&gf,2),Galois::Element(&gf,2),
                                  Galois::Element(&gf,2),Galois::Element(&gf,3),
                                  Galois::Element(&gf,3),Galois::Element(&gf,0),
                                  Galois::Element(&gf,3),Galois::Element(&gf,1),
                                  Galois::Element(&gf,3),Galois::Element(&gf,2),
                                  Galois::Element(&gf,3),Galois::Element(&gf,3),
    };

    Galois::Element A[2 * 5] = { 
     Galois::Element(&gf,1),Galois::Element(&gf,0),Galois::Element(&gf,1),Galois::Element(&gf,2),Galois::Element(&gf,3), 
     Galois::Element(&gf,0),Galois::Element(&gf,1),Galois::Element(&gf,1),Galois::Element(&gf,1),Galois::Element(&gf,1), 
    };

    Galois::Element B1A[16 * 5] = {
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), 
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), 
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), 
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), 
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf),
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf),
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf),
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), 
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf),
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf),
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf),
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), 
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf),
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf),
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf),
     Galois::Element(&gf),Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), Galois::Element(&gf), 
    };

    matrixMul<16,2,5>(B1, A, B1A);
    displayMatrix<16,5>(B1A);

    return 0;
}