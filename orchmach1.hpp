/*
Orchestrated machines (OrchMach1)
The research is presented in an already submitted paper entitled
"Are there intelligent Turing machines?"
---------------------------------
This is the most precise description of the orchestrated machine
algorithm because it is implemented in a concrete programming
language /in the source file orchmach1.hpp in the function
template <int M> long OrchMach1< M >::start ( void )/

 Copyright (C) 2009, 2014 Norbert Batfai, batfai.norbert@inf.unideb.hu

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

Examined breeds and full running logs
-------------------------------------

  exp 4-5
  -------

  breed "7" : orchmach1-ng7.out (orchmach1-exp4-pc.cpp)
  breed "3": orchmach1-ng3-3.out (orchmach1-exp5-pc.cpp)

  5: 187049_1-24 (orchmach1-exp5-hpc.cpp)

  breed "3a": slurm-187049_17.out
  breed "18": slurm-187049_22.out
  breed "17": slurm-187049_23.out

  exp 6
  -----

  6: 227748_1-24 (orchmach1-exp6-hpc.cpp)

  breed "6": slurm-227748_11.out
  breed "5": slurm-227748_13.out
  breed "5a": slurm-227748_14.out
  breed "6a":  slurm-227748_18.out
  breed "17a": slurm-227748_22.out
  breed "13": slurm-227748_23.out
  breed "5b": slurm-227748_24.out

  exp 7
  -----

  7: 266553_[1-24] (orchmach1-exp7-hpc.cpp)

  breed "18a": slurm-266553_1.out slurm-266553_13.out
  breed "17b": slurm-266553_4.out slurm-266553_16.out
  breed "": slurm-266553_7.out slurm-266553_19.out
  breed "": slurm-266553_8.out slurm-266553_20.out
  breed "": slurm-266553_9.out slurm-266553_21.out
  breed "21": slurm-266553_10.out slurm-266553_22.out
  breed "15": slurm-266553_12.out slurm-266553_24.out

 The above *.out files can be found at http://www.inf.unideb.hu/~nbatfai/orchmach

Version history
---------------

 Recombination of codes of BB5 machines
 see also related link http://arxiv.org/abs/0908.4013

 BB5.c, BB(5)=?, Kolmogorov time complexity
 see also related link http://arxiv.org/abs/0908.1159

 2009/06/01 12:58:00, 0.0.1
  initial version from bb4.c
 2009/06/02 18:53:00, 0.0.2
  Simulations of T machines are failed
  (array and operating limits are too small IMHO)
  Trying to fix it... yes, trivial, let MAX-STEPS < NOF_CELLS/2
 2009/06/19 0.0.3
  Add trivial_infinite_loop()
  Add "for (i = 0; i < 2; ++i)" instead of "for (i = 0; i < NOF_FROM; ++i)"
 2009/07/02 13:15:00, 0.0.4
  Add shorter_program() and "memset((void *)tape, 0, sizeof(tape));"
 2009/07/27 11:29:00, 0.0.5
  simulate() and nof_ones() function are too slow...
  These functions have already been written without any "if" statements.
 2009/07/27 19:10:00, 0.0.6
  if (NOF_CELLS > 200M) static+memset(), malloc()+memset(), calloc() are very slow
  Trying to use bits... ok, NOF_CELLS is equal to 268.435.456.-
  MAX_STEPS 134.217.600.-
 ...
 ...
 2014/09/02 0.1.0
  OrchMach1.c
  Initial version, started from BB5-0.0.6-9-Recomb3.c
 2014/09/03 0.1.1
  rewritten in C++: orchmach1.hpp, orchmach1.cpp
 2014/09/04 0.1.2
  cmake project, C++11
 2014/09/10 0.1.3
  GitHub project
 2014/10/06 0.1.4
  uploaded to GitHub
  the next version history entries will be available in the git repo
*/
#include <iostream>
#include <cstdarg>
#include <cstring>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iomanip>

template <int M>
class TransitionRules {

public:

     int from[M*2][2];
     int to[M*2*3][3];

     TransitionRules() {

          for ( int i ( 0 ); i<M; ++i ) {

               // (state, read) ->
               for ( int j ( 0 ); j<2; ++j ) {
                    from[2*i+j][0] = i;
                    from[2*i+j][1] = j;
               }

               // -> (state, write, move)
               for ( int j ( 0 ); j<2; ++j )
                    for ( int k ( 0 ); k<3; ++k ) {
                         to[6*i+j*3+k][0] = i;
                         to[6*i+j*3+k][1] = j;
                         to[6*i+j*3+k][2] = k;
                    }
          }
     }

     friend std::ostream & operator<< ( std::ostream & os, TransitionRules<M> & tr ) {

          for ( int i ( 0 ); i<M; ++i ) {

               // (state, read) ->
               for ( int j ( 0 ); j<2; ++j ) {
                    std::cout << tr.from[2*i+j][0];
                    std::cout << " ";
                    std::cout << tr.from[2*i+j][1];
                    std::cout << std::endl;
               }

               // -> (state, write, move)
               for ( int j ( 0 ); j<2; ++j )
                    for ( int k ( 0 ); k<3; ++k ) {
                         std::cout << tr.to[6*i+j*3+k][0];
                         std::cout << " ";
                         std::cout << tr.to[6*i+j*3+k][1];
                         std::cout << " ";
                         std::cout << tr.to[6*i+j*3+k][2];
                         std::cout << std::endl;
                    }

          }

          return os;
     }

};

template <long M>
class Tape {

public:

     char* tape;
     long tapei {0L};

     Tape() {

          tape = new char[M];
          clear();

     }

     void clear ( void ) {

          memset ( ( void * ) tape, 0, M*sizeof ( char ) );
     }

     void clear ( long from, long to ) {

          memset ( ( void * ) ( tape+M/2-from/8-4 ), 0, from/8+to/8+8 );

     }

     int
     get_tape ( long tapei ) {

          long bytei = tapei / 8;
          int biti = tapei % 8;

          char value = 0x01;

          value = ( value & ( tape[bytei] >> ( 8 - biti - 1 ) ) );

          return value;
     }

     void
     set_tape ( long xth, int value ) {

          long bytei = xth / 8;
          int biti = xth % 8;

          if ( value == 0x00 ) {
               // set x-th. bit to 0
               value = 0x01;
               value <<= ( 8 - biti - 1 );
               value = ( char ) ~value;
               tape[bytei] &= value;

          } else {
               // set x-th. bit to 1
               value = 0x01;
               value <<= ( 8 - biti - 1 );
               tape[bytei] |= value;

          }
     }

     friend std::ostream & operator<< ( std::ostream & os, Tape<M> & t ) {

          std::cout << t.tapei;

          return os;
     }

     ~Tape() {
          delete[] tape;
     }

};

template <int M>
class TuringMachine {

public:

#ifdef HPC
     static constexpr long MAX_STEPS =   3.5*2147483648L;
     static constexpr long NOF_CELLS = ( 2*MAX_STEPS+32 ) /8; //1792M
#else
     static constexpr long MAX_STEPS =   8*2147483648L;
     static constexpr long NOF_CELLS = ( 2*MAX_STEPS+32 ) /8; //4096M
#endif

     static TransitionRules<M> rules;
     static Tape<NOF_CELLS> tape;

     int astep[M*2];
     int machine[M*2][5];

     int state {0};

     long nr_ones[4] = {0L, 0L, 0L, 0L};
     long nof_dirs[3] = {0L, 0L, 0L};

     int nof {0};

#ifdef STATES_OM3
     bool states[M] = {false, false, false};
#endif

     TuringMachine () {}

     TuringMachine ( int nof, ... );

     friend std::ostream & operator<< ( std::ostream & os, TuringMachine<M> & tm ) {

          std::cout << "(" << tm.nof;

          for ( int i ( 0 ); i<tm.nof; ++i ) {


               for ( int f ( 0 ); f<M*2; ++f )
                    if ( tm.machine[i][0] == rules.from[f][0]
                              && tm.machine[i][1] == rules.from[f][1] ) {
                         std::cout << ", "<< f;
                         break;
                    }


               for ( int t ( 0 ); t<M*2*3; ++t )

                    if ( tm.machine[i][2] == rules.to[t][0]
                              && tm.machine[i][3] == rules.to[t][1]
                              && tm.machine[i][4] == rules.to[t][2] ) {
                         std::cout << ", "<< t;
                         break;
                    }

          }
          std::cout << ")" << std::endl;

          for ( int i = 0; i < tm.nof; ++i ) {

               std::cout << "(" << tm.machine[i][0]
                         << "," << tm.machine[i][1]
                         << ")->(" << tm.machine[i][2]
                         << "," << tm.machine[i][3]
                         << "," << tm.machine[i][4]
                         << ")" << std::endl;

          }

          return os;
     }

     virtual long start ( void );

};


template <int M>
class OrchMach1 : public TuringMachine<M> {

     std::list<TuringMachine<M>*> TMs;
     std::list<TuringMachine<M>*> TMscopy;

     long N {0L};
     double o2 {0.0};
     long nof1s {0L};

public:

#ifdef DEBUG_SEL
     bool log {false};
#endif

     OrchMach1 ( int nof, ... ) {

          va_list vap;

          va_start ( vap, nof );

          for ( int i ( 0 ); i < nof; ++i ) {
               TMs.push_back ( va_arg ( vap, TuringMachine<M>* ) );
          }

          va_end ( vap );

#ifdef DEBUG_RND
          int t = 1413408464;
#elif HPC_RND
          int t = std::time ( NULL );
          if ( std::getenv ( "SLURM_ARRAY_TASK_ID" ) )
               t += std::atoi ( std::getenv ( "SLURM_ARRAY_TASK_ID" ) ) ;
#else
          int t = std::time ( NULL );
#endif
          std::srand ( t );
          std::cout  << "srand: " << t << std::endl;
          std::cout  << "sizeof long: " << sizeof ( 1L ) << std::endl;
          std::cout  << "tape length: " << TuringMachine<M>::NOF_CELLS * 8 << " ("
                     << ( TuringMachine<M>::NOF_CELLS / 1024 ) / 1024 << " MBytes)" <<  std::endl;
          std::cout  << "steps limit: " << TuringMachine<M>::MAX_STEPS << std::endl;

          for ( typename std::list<TuringMachine<M>*>::iterator it=TMs.begin(); it != TMs.end(); ++it ) {

               std::cout  << *it << std::endl;
               std::cout  << **it << std::endl;

          }

          TMscopy = TMs;

     }

     void start ( long& N, double& o2, long& nof1s ) {
          start();
          N = this->N;
          o2 = this->o2;
          nof1s = this->nof1s;
     }

     long start ( void );
     void experiment ( void );

     friend std::ostream & operator<< ( std::ostream & os, OrchMach1<M> & om1 ) {

          std::cout << std::setprecision ( std::numeric_limits<double>::digits10 )
                    << "o2= " << om1.o2
                    << " N= " << om1.N
                    << " 1s= " << om1.nof1s << std::endl;
          ;

     }

};

template <int M> TransitionRules<M> TuringMachine< M >::rules;
template <int M> Tape<TuringMachine<M>::NOF_CELLS> TuringMachine< M >::tape;

template <int M> long OrchMach1< M >::start ( void )
{

     this->nof_dirs[0] = this->nof_dirs[1] = this->nof_dirs[2] = 0L;
     this->nr_ones[0] = this->nr_ones[1] = this->nr_ones[2] = this->nr_ones[3] = 0L;

     TuringMachine<M>::tape.tapei = ( TuringMachine<M>::NOF_CELLS * 8 ) / 2;
     this->state = 0;

     TMs = TMscopy;

     for ( typename std::list<TuringMachine<M>*>::iterator it=TMs.begin(); it != TMs.end(); ++it ) {

          ( *it )->state = 0;

     }

#ifdef DEBUG_SEL
     std::vector<std::pair<int,TuringMachine<M>*>> tois ( 10 );
     long logc {500L};
     if ( log )
          std::cout << "START SEL" << std::endl;
#else
     std::vector<int> tois ( 10 );
#endif

     int toi {0};

     long s {0}, sumo {0};

     for ( ; s < TuringMachine<M>::MAX_STEPS && !TMs.empty(); ++s ) {

          tois.clear();

          typename std::list<TuringMachine<M>*>::iterator it=TMs.begin();
          while ( it != TMs.end() ) {

               toi = ( *it )->astep[ ( *it )->state * 2
                                     + TuringMachine<M>::tape.get_tape ( TuringMachine<M>::tape.tapei )];
               if ( toi >= 0 ) {

#ifdef DEBUG_SEL
                    tois.push_back ( std::make_pair ( toi, *it ) );
#else
                    tois.push_back ( toi );
#endif
                    ++it;
               } else {
                    // halt
                    typename std::list<TuringMachine<M>*>::iterator dit=it;
                    ++it;

                    TMs.erase ( dit );

               }
          }

          // select

          if ( tois.size() > 0 ) {

#ifdef DEBUG_SEL
               typename std::vector<std::pair<int,TuringMachine<M>*>>::iterator toisi=tois.begin();
               std::advance ( toisi, std::rand() % tois.size() );
               toi = ( *toisi ).first;

               if ( log && ( --logc > 0 ) )
                    std::cout << ( *toisi ).second << " " << TMs.size() << ":"
                              << tois.size() << "/" << toi << std::endl;

#else

               std::vector<int>::iterator toisi=tois.begin();
               std::advance ( toisi, std::rand() % tois.size() );
               toi = *toisi;
#endif
               sumo += tois.size();

               // exec

               for ( typename std::list<TuringMachine<M>*>::iterator it=TMs.begin(); it != TMs.end(); ++it ) {

#ifdef STATES_OM3
                    // OrchMach3
                    int st = TuringMachine<M>::rules.to[toi][0];
                    if ( ( *it )->states[st] )
                         ( *it )->state = st;
#endif

                    ( *it )->state = TuringMachine<M>::rules.to[toi][0];

               }

               ++this->nr_ones[TuringMachine<M>::
                               tape.get_tape ( TuringMachine<M>::tape.tapei ) * 2
                               + TuringMachine<M>::rules.to[toi][1]];

               TuringMachine<M>::tape.set_tape ( TuringMachine<M>::tape.tapei,
                                                 TuringMachine<M>::rules.to[toi][1] );
               TuringMachine<M>::tape.tapei += ( TuringMachine<M>::rules.to[toi][2] - 1 );

               ++this->nof_dirs[TuringMachine<M>::rules.to[toi][2]];

          }

     }

     if ( s >= TuringMachine<M>::MAX_STEPS ) {
          N = -1;
          o2 = ( double ) sumo / ( double ) TuringMachine<M>::MAX_STEPS;
     } else {
          N = s-1;
          o2 = ( double ) sumo / ( double ) N;
     }

     nof1s = this->nr_ones[1] - this->nr_ones[2];

     TuringMachine<M>::tape.clear ( this->nof_dirs[0], this->nof_dirs[2] );

     return N;
}

template <int M> long TuringMachine< M >::start ( void )
{

     nr_ones[0] = nr_ones[1] = nr_ones[2] = nr_ones[3] = 0;
     nof_dirs[0] = nof_dirs[1] = nof_dirs[2] = 0L;

     tape.tapei = ( NOF_CELLS * 8 ) / 2;
     state = 0;

     int toi {0};
     for ( long s ( 0 ); s < MAX_STEPS; ++s ) {
          toi = astep[state * 2 + tape.get_tape ( tape.tapei )];
          if ( toi >= 0 ) {
               state = rules.to[toi][0];
               ++nr_ones[tape.get_tape ( tape.tapei ) * 2 + rules.to[toi][1]];
               tape.set_tape ( tape.tapei, rules.to[toi][1] );
               tape.tapei += ( rules.to[toi][2] - 1 );
               ++nof_dirs[rules.to[toi][2]];
               // 0: <-
               // 1: |
               // 2: ->
          } else {
               // halt
               tape.clear ( nof_dirs[0], nof_dirs[2] );
               return nr_ones[1] - nr_ones[2];
          }
     }

     tape.clear ( nof_dirs[0], nof_dirs[2] );
     return -1;
}

template <int M> TuringMachine< M >::TuringMachine ( int nof, ... ) :nof ( nof )
{

#ifdef STATES_OM3
     for ( int i ( 0 ); i < M; ++i )
          states[i] = false;
#endif

     va_list vap;
     va_start ( vap, nof );

     for ( int i ( 0 ); i < M*2; ++i )
          astep[i] = -1;

     for ( int i ( 0 ); i < nof; ++i ) {
          int f = va_arg ( vap, int );
          int t = va_arg ( vap, int );

          // used only for printing and debugging purposes
          machine[i][0] = rules.from[f][0];
          machine[i][1] = rules.from[f][1];
          machine[i][2] = rules.to[t][0];
          machine[i][3] = rules.to[t][1];
          machine[i][4] = rules.to[t][2];

          astep[rules.from[f][0] * 2 + rules.from[f][1]] = t;

#ifdef STATES_OM3
          states[rules.from[f][0]] = true;
          states[rules.to[t][0]] = true;
#endif

     }

     va_end ( vap );

}

template <int M> void OrchMach1< M >::experiment ( void )
{

     long max_N {0L};
     long max_nof1s {0};
     double max_o2 {0.0};
     double mean {0.0};
     double max_mean {0.0};
     double mN {0.0};
     double mo {0.0};
     double m1 {0.0};
     double sum_mN {0.0};
     double sum_mo {0.0};
     double sum_m1 {0.0};
     double max_mN {0.0};
     double max_mo {0.0};
     double max_m1 {0.0};

     long n {0L};
     for ( ;; ) {

          start ( );

          if ( N != -1 ) {

               if ( N >max_N ) {
                    max_N = N;
                    std::cout << " N) " << *this;
               }
               if ( o2>max_o2 ) {
                    max_o2 = o2;
                    std::cout << " o) " << *this;
               }
               if ( nof1s>max_nof1s ) {
                    max_nof1s = nof1s;
                    std::cout << " 1) " << *this;
               }

               mean = ( N+max_o2+nof1s ) / 3.0;
               if ( mean>max_mean ) {
                    max_mean = mean;
                    std::cout << " m) " << *this;
               }

               ++n;

               sum_mN += N;
               mN = ( double ) N / ( double ) n;
               if ( mN>max_mN ) {
                    max_mN = mN;
                    std::cout << "mN) " << *this;
               }

               sum_mo += o2;
               mo = ( double ) sum_mo / ( double ) n;
               if ( mo>max_mo ) {
                    max_mo = mo;
                    std::cout << "mo) " << *this;
               }

               sum_m1 += nof1s;
               m1 = ( double ) sum_m1 / ( double ) n;
               if ( m1>max_m1 ) {
                    max_m1 = m1;
                    std::cout << "m1) " << *this;
               }


#ifdef DEBUG_SEL
               if ( /*o2 == 1.00000002180426 &&*/ N == 3210381160L && nof1s == 74280L ) {
                    log = true;
               } else if ( N == 3272948454L && nof1s == 75001L ) {
                    std::exit ( -1 );
               }
#endif


          } else {
               std::cout << "-1) " << *this;
#ifdef DEBUG_INFTY
               ;
#else
               std::exit ( -1 );
#endif

          }

     }

}
