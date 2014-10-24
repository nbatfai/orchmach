Orchestrated machines (OrchMach1)
=================================
The research is presented in an already submitted paper entitled
_"Are there intelligent Turing machines?"_

This is the most precise description of the 
_orchestrated machine algorithm_ 
because it is implemented in a concrete programming 
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

-breed "7" : orchmach1-ng7.out (orchmach1-exp4-pc.cpp)

-breed "3": orchmach1-ng3-3.out (orchmach1-exp5-pc.cpp) 

-5: 187049_1-24 (orchmach1-exp5-hpc.cpp)

-breed "3a": slurm-187049_17.out

-breed "18": slurm-187049_22.out

-breed "17": slurm-187049_23.out

  exp 6
  -----

  -6: 227748_1-24 (orchmach1-exp6-hpc.cpp)

  -breed "6": slurm-227748_11.out 

  -breed "5": slurm-227748_13.out 

  -breed "5a": slurm-227748_14.out 

  -breed "6a":  slurm-227748_18.out 

  -breed "17a": slurm-227748_22.out 

  -breed "13": slurm-227748_23.out 

  -breed "5b": slurm-227748_24.out 

  exp 7
  -----

  -7: 266553_[1-24] (orchmach1-exp7-hpc.cpp)

  -breed "18a": slurm-266553_1.out slurm-266553_13.out

  -breed "17b": slurm-266553_4.out slurm-266553_16.out

  -breed "": slurm-266553_7.out slurm-266553_19.out

  -breed "": slurm-266553_8.out slurm-266553_20.out

  -breed "": slurm-266553_9.out slurm-266553_21.out

  -breed "21": slurm-266553_10.out slurm-266553_22.out

  -breed "15": slurm-266553_12.out slurm-266553_24.out
 
 The above *.out files can be found at [http://www.inf.unideb.hu/~nbatfai/orchmach](http://www.inf.unideb.hu/~nbatfai/orchmach)
 
Version history
---------------

 Recombination of codes of BB5 machines
 see also related link http://arxiv.org/abs/0908.4013

 BB5.c, BB(5)=?, Kolmogorov time complexity
 see also related link http://arxiv.org/abs/0908.1159

 -2009/06/01 12:58:00, 0.0.1
  initial version from bb4.c

 -2009/06/02 18:53:00, 0.0.2
  Simulations of T machines are failed
  (array and operating limits are too small IMHO)
  Trying to fix it... yes, trivial, let MAX-STEPS < NOF_CELLS/2

 -2009/06/19 0.0.3
  Add trivial_infinite_loop()
  Add "for (i = 0; i < 2; ++i)" instead of "for (i = 0; i < NOF_FROM; ++i)"

 -2009/07/02 13:15:00, 0.0.4
  Add shorter_program() and "memset((void *)tape, 0, sizeof(tape));"

 -2009/07/27 11:29:00, 0.0.5
  simulate() and nof_ones() function are too slow...
  These functions have already been written without any "if" statements.

 -2009/07/27 19:10:00, 0.0.6
  if (NOF_CELLS > 200M) static+memset(), malloc()+memset(), calloc() are very slow
  Trying to use bits... ok, NOF_CELLS is equal to 268.435.456.-
  MAX_STEPS 134.217.600.-

 -...

 -...

 -2014/09/02 0.1.0
  OrchMach1.c
  Initial version, started from BB5-0.0.6-9-Recomb3.c

 -2014/09/03 0.1.1
  rewritten in C++: orchmach1.hpp, orchmach1.cpp

 -2014/09/04 0.1.2
  cmake project, C++11

 -2014/09/10 0.1.3
  GitHub project

 -2014/10/06 0.1.4
  uploaded to GitHub
  the next version history entries will be available in the git repo
