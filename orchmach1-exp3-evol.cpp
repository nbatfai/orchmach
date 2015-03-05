#include <iostream>
#include "orchmach1.hpp"
#include <fstream>

/*
  g++ -DDEBUG_SEL_RULE -DDEBUG_SEL_MACHINE -DDEBUG_SEL_MACHINE_VAR -O3 orchmach1-exp3-evol.cpp -o orchmach1 -std=c++11
 */

int
main ( int argc, char *argv[] )
{

  if ( argc != 2 )
    {
      std::cout <<  "The filename of Turing machines must be given as the first argument."
                << std::endl;
      return -1;
    }

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

  std::fstream machsfile ( argv[1], std::ios_base::in );

  if ( !machsfile )
    {
      std::cout <<  argv[1] << " does not exist." << std::endl;
      return -1;
    }

  int nr, f1, f2, f3, f4, f5, f6, f7, f8, f9,
      t1, t2, t3, t4, t5, t6, t7, t8, t9;

  std::vector<TuringMachine<5> *> machv;

  while ( !machsfile.eof() )
    {
      machsfile >> nr >> f1 >> t1 >> f2 >> t2 >> f3 >> t3 >> f4 >> t4 >> f5 >>
                t5 >> f6 >> t6 >> f7 >> t7 >> f8 >> t8 >> f9 >> t9;

      machv.push_back ( new TuringMachine<5> {nr, f1 , t1 , f2 , t2 , f3 , t3 , f4 , t4 , f5 ,
                                              t5 , f6 , t6 , f7 , t7 , f8 , t8 , f9 , t9
                                             } );
    }

  std::cout<< machv.size()
           << " Turing machines have been read" << std::endl;

  // NEITHER OrchMach1 NOR TuringMachine OBJECTS CAN BE USED IN PARALLEL

  OrchMach1<5> om ( 30, &tm12,  &tm14, &tm15, &tm21,  &tm22, &tm24, &tm25, &tm27, &tm29,

                    machv.at ( 20 ),

                    machv.at ( 30 ),
                    machv.at ( 40 ),
                    machv.at ( 50 ),
                    machv.at ( 60 ),
                    machv.at ( 70 ),
                    machv.at ( 80 ),
                    machv.at ( 90 ),
                    machv.at ( 100 ),
                    machv.at ( 110 ),
                    machv.at ( 120 ),
                    /*
                                        machv.at ( 330 ),
                                        machv.at ( 440 ),
                                        machv.at ( 550 ),
                                        machv.at ( 660 ),
                                        machv.at ( 770 ),
                                        machv.at ( 880 ),
                                        machv.at ( 990 ),
                                        machv.at ( 1100 ),
                                        machv.at ( 1110 ),
                                        machv.at ( 1120 ),

                                        machv.at ( 1400 ),
                                        machv.at ( 1401 ),
                                        machv.at ( 1402 ),
                                        machv.at ( 1403 ),
                                        machv.at ( 1404 ),
                                        machv.at ( 1405 ),
                                        machv.at ( 1406 ),
                                        machv.at ( 1407 ),
                                        machv.at ( 1408 ),
                                        machv.at ( 1409 ),
                    */
                    machv.at ( 2330 ),
                    machv.at ( 3440 ),
                    machv.at ( 4550 ),
                    machv.at ( 5660 ),
                    machv.at ( 6770 ),
                    machv.at ( 7880 ),
                    machv.at ( 8990 ),
                    machv.at ( 9100 ),
                    machv.at ( 10110 ),
                    machv.at ( 10120 )

                  );

  TuringMachine<5> *last_added = om.back();
  int nr_generations {0};
  for ( ;; ++nr_generations )
    {
      std::cout << "Generation " << nr_generations << std::endl;
      try
        {
          TuringMachine<5>* m = om.experiment();
          if ( m )
            {
              om.del ( m );

              TuringMachine<5> *nm = nullptr;
              do
                {
                  nm = machv[std::rand() % machv.size()];
                }
              while ( om.contains ( nm ) );

              om.add ( nm );
              last_added = nm;
            }
          else
            throw "None";

        }
      catch ( ... )
        {
          om.del ( last_added );

          TuringMachine<5> *nm = nullptr;
          do
            {
              nm = machv[std::rand() % machv.size()];
            }
          while ( om.contains ( nm ) );

          om.add ( nm );
          last_added = nm;

        }
    }
}
