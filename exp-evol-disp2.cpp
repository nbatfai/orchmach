#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

typedef struct o2N
{
  double o2;
  int N;
  std::vector<std::string> v;

} O2N;

int cut ( std::vector<std::string> u,   std::vector<std::string> v )
{
  int r {0};
  for ( std::string uu:u )
    {
      std::vector<std::string>::iterator it =std::find ( v.begin(), v.end(), uu );
      if ( it != v.end() )
        ++r;
    }
  return r;
}

int main ( int argc, char *argv[] )
{

  std::vector<O2N> v;

  std::string sLine = "";
  std::fstream inFile ( argv[1], std::ios_base::in );
  bool inmach {false};

  int i {0};
  while ( !inFile.eof() )
    {
      std::getline ( inFile, sLine );

      std::string s {"Gen"};
      if ( sLine.compare ( 0, s.length(), s ) == 0 )
        {
          std::vector<std::string> vv;

          O2N o2N {0.0, 0, vv};
          v.push_back ( o2N );
          inmach = false;
        }

      std::string snn {"("};
      if ( sLine.compare ( 0, snn.length(), snn ) == 0 )
        {
          if ( !inmach )
            v.back().v.clear();

          inmach = true;

          v.back().v.push_back ( sLine.substr ( 0, sLine.find_last_of ( ')' ) +1 ) );
        }
      else
        inmach = false;

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

  int q {10};
  for ( int i {0}; i<v.size(); ++i )
    {

#ifdef SEARCH_FOR_MACHINE      
      if ( v.at ( i ).N > 1000 )
        {
          std::cout << "++++ " << v.at ( i ).o2 << " " << v.at ( i ).N << std::endl;
        }
#endif        

      std::cout <<    i << " **** " << v.at ( i ).N
                << std::endl;
      if ( i>q )
        for ( int j {0}; j<q; ++j )
          {
            std::cout <<
                      j << " " <<
                      v.at ( i ).v.size() << " " <<
                      v.at ( i-j ).v.size() << " " <<
                      cut ( v.at ( i ).v, v.at ( i-j ).v ) <<
                      " " <<cut ( v.at ( i ).v, v.at ( 902 ).v )
                      << std::endl;
          }

      std::cout <<    "----"
                << std::endl;

    }

  return 0;
}
