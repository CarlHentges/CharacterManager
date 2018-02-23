#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <ctype.h>
#include <sstream>
int health;
int healthMax;



int random(int dice){
  double random_variable = std::rand();
  return fmod(random_variable,dice-1) + 1;
}

int main() {
  int die;
  std::string input;
  while (true) {
    std::cin >> input;

    if(isdigit(input[0])){

      std::stringstream(input) >> die;
      std::cout << "\n\n\nrolling a D" << die <<" " << random(die) << '\n';

    }else{
      std::cout << input << '\n';
    }
  }

  return 0;
}
