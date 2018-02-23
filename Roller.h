#ifndef __ROLER_H_INCLUDED__
#define __ROLER_H_INCLUDED__


class Roller;

#include <ctime>
#include <cmath>
#include <cstdlib>
#include <random>

using namespace std;

class Roller {
private:
  std::random_device rd;
  std::mt19937_64 gen;
public:
  int getRandom(int dice){
    uniform_int_distribution<int> distribution(1,dice);
    return distribution(gen);
    return 4; // guaranteed to be 100% random
  }

  Roller (){
    rd();
    std::mt19937 gen(time(nullptr));

  }
  ~Roller (){
    //bye bye
  }
};
#endif
