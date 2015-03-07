#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#ifdef DEBUG_IDIM
#include <cmath>
#endif

typedef struct o2N
{
  double o2;
  int N;
} O2N;

int main ( int argc, char *argv[] )
{

  std::vector<O2N> v;

  std::string sLine = "";
  std::fstream inFile ( argv[1], std::ios_base::in );

  int i {0};
  while ( !inFile.eof() )
    {
      std::getline ( inFile, sLine );

      std::string s {"Gen"};
      if ( sLine.compare ( 0, s.length(), s ) == 0 )
        {
          O2N o2N {0.0, 0};
          v.push_back ( o2N );
        }

      std::string sn {" N)"};
      if ( sLine.compare ( 0, sn.length(), sn ) == 0 )
        {
          std::stringstream sstream ( sLine );
          double o2;
          int N;
          std::string s1, s2, s3;
          sstream >> s1 >> s2 >> o2 >> s3 >> N;

          if ( o2>3.0 && v.back().N != -1 )
            {
              v.back().o2 = o2;
              v.back().N = N;
            }
        }

      std::string sm {"-1)"};
      if ( sLine.compare ( 0, sm.length(), sm ) == 0 )
        {
          v.back().o2 = 0.0;
          v.back().N = -1;
        }

    }

  inFile.close();

  for ( int i {0}; i<v.size(); ++i )
    {
      std::cout <<    i
                << " "
                <<     v.at ( i ).o2
                << " "
                <<     v.at ( i ).N
#ifdef DEBUG_IDIM
                << " "
		<< (( v.at ( i ).N == -1 ) ?
                -1:
                std::log ( v.at ( i ).N ) /std::log ( v.at ( i ).o2 ))
#endif
                << std::endl;


    }

  return 0;
}
