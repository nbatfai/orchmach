#include <iostream>
#include "orchmach1.hpp"

/*
 g++ -O3 orchmach1-exp5-pc.cpp -o orchmach1-3 -std=c++11
 */

int
main ( int argc, char *argv[] )
{
     TuringMachine<5> tm8 ( 9, 0, 11, 1,  15, 2, 0,  3,  18, 4,  3,  6,  9,  7,  29, 8, 20, 9,  8 );// Uhing, 1915
     TuringMachine<5> tm10 ( 9, 0, 9,  1,  12, 2, 15, 3,  21, 4,  29, 5,  1,  7,  24, 8, 2,  9,  27 );// 160
     TuringMachine<5> mbR ( 9, 0, 11, 1, 15, 2, 17, 3, 1, 4, 23, 5, 24, 6, 3, 7, 21, 9, 0 );// Marxen-Buntrock, (recombinated 70740809, 4097)

     // NEITHER OrchMach1 NOR TuringMachine OBJECTS CAN BE USED IN PARALLEL

     OrchMach1<5> om ( 3, &mbR, &tm8, &tm10 );

     om.experiment();
}

