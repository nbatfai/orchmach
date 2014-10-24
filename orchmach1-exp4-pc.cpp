#include <iostream>
#include "orchmach1.hpp"

/*
  g++ -O3 -DDEBUG_RND orchmach1.cpp -o orchmach1 -std=c++11
 */

int
main ( int argc, char *argv[] )
{

     TuringMachine<5> tm21 ( 9, 0, 9, 1, 11, 2, 5, 3, 20, 4, 15, 5, 0, 7, 17, 8, 15, 9, 1 );// 12
     TuringMachine<5> tm22 ( 9, 0, 9, 1, 14, 2, 5, 3, 21, 4, 8, 5, 1, 6, 3, 8, 15, 9, 1 );// 11
     TuringMachine<5> tm23 ( 9, 0, 6, 1, 17, 2, 15, 3, 3, 4, 5, 5, 20, 6, 3, 8, 15, 9, 1 );// 10
     TuringMachine<5> tm24 ( 9, 0, 9, 1, 17, 2, 18, 3, 1, 4, 5, 6, 15, 7, 29, 8, 15, 9, 1 );// 9
     TuringMachine<5> tm25 ( 9, 0, 9, 1, 14, 2, 18, 3, 3, 4, 5, 6, 15, 7, 29, 8, 15, 9, 1 );// 8
     TuringMachine<5> tm29 ( 9, 0, 9, 1, 11, 2, 5, 3, 20, 4, 17, 5, 24, 7, 29, 8, 15, 9, 1 );// 4
     TuringMachine<5> mbR ( 9, 0, 11, 1, 15, 2, 17, 3, 1, 4, 23, 5, 24, 6, 3, 7, 21, 9, 0 );// Marxen-Buntrock, (recombinated 70740809, 4097)

     // NEITHER OrchMach1 NOR TuringMachine OBJECTS CAN BE USED IN PARALLEL

     OrchMach1<5> om ( 7,
                       &mbR,  &tm21, &tm22, &tm23, &tm24,
                       &tm25, &tm29
                     );

     om.experiment();
}

