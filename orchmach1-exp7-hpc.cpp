#include <iostream>
#include "orchmach1.hpp"

/*
 g++ -DHPC -DHPC_RND orchmach1-exp7-hpc.cpp -O3 -o orchmach1-exp7-hpc -std=c++11

 #!/bin/bash
 #SBATCH -A account
 #SBATCH --job-name=OM1-newgen
 #SBATCH --mem-per-cpu=2000
 #SBATCH --time=5-0
 #SBATCH --mail-type=ALL
 #SBATCH --mail-user=batfai.norbert@inf.unideb.hu
 #SBATCH --array=1-24
 #SBATCH --ntasks=1
 srun ./orchmach1-exp7-hpc

 */

int
main ( int argc, char *argv[] )
{
     TuringMachine<5> tm1 ( 9, 0, 11, 1, 15, 2, 17, 3, 11, 4, 23, 5, 24, 6, 3,  7, 21, 9, 0 ); // Marxen-Buntrock, 4097
     TuringMachine<5> tm2 ( 9, 0, 11, 1, 18, 2, 15, 3, 23, 4, 3,  5, 15, 7, 29, 8, 5,  9, 8 ); // Marxen-Buntrock, 4096
     TuringMachine<5> tm3 ( 9, 0, 11, 1, 5,  2, 15, 3, 20, 4, 3,  5, 15, 7, 29, 8, 24, 9, 11 ); // Marxen-Buntrock, 4095
     TuringMachine<5> tm4 ( 9, 0, 11, 1, 5,  2, 15, 3, 20, 4, 3,  5, 15, 7, 29, 8, 15, 9, 11 ); // Marxen-Buntrock, 4095
     TuringMachine<5> tm5 ( 9, 0, 11, 1, 5,  2, 15, 3, 9,  4, 5,  5, 21, 6, 5,  7, 27, 9, 12 ); // Marxen-Buntrock, 4097
     TuringMachine<5> tm6 ( 9, 0, 11, 1, 5,  2, 15, 3, 23, 4, 3,  5, 15, 7, 26, 8, 15, 9, 11 ); // Marxen-Buntrock, 4096
     TuringMachine<5> tm7 ( 9, 0, 11, 2, 15, 3, 17, 4, 26, 5, 18, 6, 15, 7, 6,  8, 23, 9, 5 ); // Uhing, 1471
     TuringMachine<5> tm8 ( 9, 0, 11, 1, 15, 2, 0,  3, 18, 4, 3,  6, 9,  7, 29, 8, 20, 9, 8 ); // Uhing, 1915
     TuringMachine<5> tm9 ( 9, 0, 11, 1, 12, 2, 17, 3, 23, 4, 3,  5, 8,  6, 26, 8, 15, 9, 5 ); // Schult, 501
     TuringMachine<5> tm10 ( 9, 0, 9,  1, 12, 2, 15, 3, 21, 4, 29, 5, 1,  7, 24, 8, 2,  9, 27 );// 160
     TuringMachine<5> tm11 ( 9, 0, 21, 1, 9,  2, 24, 3, 6,  4, 3,  5, 20, 6, 17, 7, 0,  9, 15 );// 32
     TuringMachine<5> tm12 ( 9, 0, 9,  1, 11, 2, 17, 3, 21, 4, 19, 5, 29, 6, 5,  7, 6,  8, 8 );// 26
     TuringMachine<5> tm13 ( 9, 0, 9,  1, 11, 2, 15, 3, 20, 4, 21, 5, 27, 6, 4,  7, 2,  8, 12 );// 21
     TuringMachine<5> tm14 ( 9, 0, 9,  1, 11, 2, 26, 3, 23, 4, 27, 5, 2,  7, 17, 8, 5,  9, 13 );// 19
     TuringMachine<5> tm15 ( 9, 0, 9,  1, 11, 2, 5,  3, 20, 4, 17, 5, 24, 7, 29, 8, 15, 9, 1 );// 14
     TuringMachine<5> tm16 ( 9, 0, 9,  1, 11, 2, 5,  3, 20, 4, 15, 5, 0,  6, 26, 7, 17, 8, 27 );// 15
     TuringMachine<5> tm17 ( 9, 0, 9,  1, 11, 2, 5,  3, 20, 4, 27, 5, 29, 7, 17, 8, 8,  9, 0 );// 16
     TuringMachine<5> tm18 ( 9, 0, 9,  1, 11, 2, 12, 3, 23, 4, 18, 5, 15, 6, 29, 7, 5,  8, 2 );// 17
     TuringMachine<5> tm19 ( 9, 0, 9,  1, 11, 2, 5,  3, 23, 4, 27, 6, 17, 7, 20, 8, 0,  9, 13 );// 18
     TuringMachine<5> tm20 ( 9, 0, 9,  1, 11, 2, 5,  3, 20, 4, 15, 5, 0,  6, 27, 7, 17, 9, 1 );// 13 1 marad a 14-esbol.
     TuringMachine<5> tm21 ( 9, 0, 9,  1, 11, 2, 5,  3, 20, 4, 15, 5, 0,  7, 17, 8, 15, 9, 1 );// 12
     TuringMachine<5> tm22 ( 9, 0, 9,  1, 14, 2, 5,  3, 21, 4, 8,  5, 1,  6, 3,  8, 15, 9, 1 );// 11
     TuringMachine<5> tm23 ( 9, 0, 6,  1, 17, 2, 15, 3, 3,  4, 5,  5, 20, 6, 3,  8, 15, 9, 1 );// 10
     TuringMachine<5> tm24 ( 9, 0, 9,  1, 17, 2, 18, 3, 1,  4, 5,  6, 15, 7, 29, 8, 15, 9, 1 );// 9
     TuringMachine<5> tm25 ( 9, 0, 9,  1, 14, 2, 18, 3, 3,  4, 5,  6, 15, 7, 29, 8, 15, 9, 1 );// 8
     TuringMachine<5> tm26 ( 9, 0, 25, 1, 11, 2, 23, 3, 27, 4, 1,  5, 21, 6, 5,  7, 16, 8, 21 );// 6
     TuringMachine<5> tm27 ( 9, 0, 25, 1, 11, 2, 23, 4, 23, 5, 27, 6, 5,  7, 17, 8, 9,  9, 29 ); // 5
     TuringMachine<5> tm28 ( 9, 0, 9,  1, 11, 2, 5,  3, 20, 4, 17, 5, 24, 7, 29, 8, 15, 9, 1 );// 4
     TuringMachine<5> tm29 ( 9, 0, 16, 1, 14, 2, 18, 3, 11, 4, 27, 5, 29, 7, 27, 8, 21, 9, 12 ); // 3
     TuringMachine<5> tm30 ( 9, 0, 16, 1, 14, 2, 18, 3, 12, 4, 27, 5, 9,  6, 26, 7, 0,  8, 29 ); // 2
     TuringMachine<5> mbR ( 9, 0, 11, 1, 15, 2, 17, 3, 1,  4, 23, 5, 24, 6, 3,  7, 21, 9, 0 );// Marxen-Buntrock, (recombinated 70740809, 4097)

     // NEITHER OrchMach1 NOR TuringMachine OBJECTS CAN BE USED IN PARALLEL

     OrchMach1<5>* om;

     if ( std::getenv ( "SLURM_ARRAY_TASK_ID" ) ) {

          switch ( std::atoi ( std::getenv ( "SLURM_ARRAY_TASK_ID" ) ) ) {

               // Breeds that were surely divergent were deleted.

          case 1:
               om = new OrchMach1<5> ( 18,
                                       &tm10, &tm11, &tm12, &tm13, &tm14,
                                       &tm15, &tm16, &tm17, &tm18, &tm19,
                                       &tm20, &tm21, &tm22, &tm23, &tm24,
                                       &tm25, &tm29, &tm30
                                     );
               break;

          case 4:
               om = new OrchMach1<5> ( 17,
                                       &tm10, &tm12, &tm13, &tm14, &tm15,
                                       &tm16, &tm17, &tm18, &tm19, &tm20,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm29, &tm30
                                     );
               break;

          case 7:
               om = new OrchMach1<5> ( 31-7,
                                       &tm8, &tm9, &tm10,
                                       &tm11, &tm12, &tm13, &tm14, &tm15,
                                       &tm16, &tm17, &tm18, &tm19, &tm20,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm26, &tm27, &tm28, &tm29, &tm30,
                                       &mbR
                                     );
               break;
          case 8:
               om = new OrchMach1<5> ( 31-8,
                                       &tm9, &tm10,
                                       &tm11, &tm12, &tm13, &tm14, &tm15,
                                       &tm16, &tm17, &tm18, &tm19, &tm20,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm26, &tm27, &tm28, &tm29, &tm30,
                                       &mbR
                                     );
               break;

          case 9:
               om = new OrchMach1<5> ( 31-9,
                                       &tm10,
                                       &tm11, &tm12, &tm13, &tm14, &tm15,
                                       &tm16, &tm17, &tm18, &tm19, &tm20,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm26, &tm27, &tm28, &tm29, &tm30,
                                       &mbR
                                     );
               break;
          case 10:
               om = new OrchMach1<5> ( 31-10,
                                       &tm11, &tm12, &tm13, &tm14, &tm15,
                                       &tm16, &tm17, &tm18, &tm19, &tm20,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm26, &tm27, &tm28, &tm29, &tm30,
                                       &mbR
                                     );
               break;

          case 12:
               om = new OrchMach1<5> ( 15,

                                       &tm11, &tm12, &tm13, &tm14, &tm15,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm26, &tm27, &tm28, &tm29, &tm30

                                     );
               break;

          case 13:
               om = new OrchMach1<5> ( 18,
                                       &tm10, &tm11, &tm12, &tm13, &tm14,
                                       &tm15, &tm16, &tm17, &tm18, &tm19,
                                       &tm20, &tm21, &tm22, &tm23, &tm24,
                                       &tm25, &tm29, &tm30
                                     );
               break;

          case 16:
               om = new OrchMach1<5> ( 17,
                                       &tm10, &tm12, &tm13, &tm14, &tm15,
                                       &tm16, &tm17, &tm18, &tm19, &tm20,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm29, &tm30
                                     );
               break;

          case 19:
               om = new OrchMach1<5> ( 31-7,
                                       &tm8, &tm9, &tm10,
                                       &tm11, &tm12, &tm13, &tm14, &tm15,
                                       &tm16, &tm17, &tm18, &tm19, &tm20,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm26, &tm27, &tm28, &tm29, &tm30,
                                       &mbR
                                     );
               break;
          case 20:
               om = new OrchMach1<5> ( 31-8,
                                       &tm9, &tm10,
                                       &tm11, &tm12, &tm13, &tm14, &tm15,
                                       &tm16, &tm17, &tm18, &tm19, &tm20,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm26, &tm27, &tm28, &tm29, &tm30,
                                       &mbR
                                     );
               break;

          case 21:
               om = new OrchMach1<5> ( 31-9,
                                       &tm10,
                                       &tm11, &tm12, &tm13, &tm14, &tm15,
                                       &tm16, &tm17, &tm18, &tm19, &tm20,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm26, &tm27, &tm28, &tm29, &tm30,
                                       &mbR
                                     );
               break;
          case 22:
               om = new OrchMach1<5> ( 31-10,
                                       &tm11, &tm12, &tm13, &tm14, &tm15,
                                       &tm16, &tm17, &tm18, &tm19, &tm20,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm26, &tm27, &tm28, &tm29, &tm30,
                                       &mbR
                                     );
               break;

          case 24:
               om = new OrchMach1<5> ( 15,

                                       &tm11, &tm12, &tm13, &tm14, &tm15,
                                       &tm21, &tm22, &tm23, &tm24, &tm25,
                                       &tm26, &tm27, &tm28, &tm29, &tm30

                                     );
               break;


          }

     } else
          om = new OrchMach1<5> ( 5,  &tm2, &tm12, &tm13, &tm14, &tm15 );


     om->experiment();

     delete om;
}

