#include <fstream>
#include <iostream>
#include <string>
#include "Saver.h"
#include "UIDisplay.h"
#include "Attributes.h"
#include "Roller.h"
#include "RWData.h"
using namespace std;

int main(){

  Roller roller;
  UIDisplay uiDisplay;
  RWData rwData;

  int a[10] = {7,20,8,16,15,9,14,7,15,5};
  Attributes attributes("eastwood",a,"MAN WITH NO NAME");
  uiDisplay.updateUI(attributes);
  rwData.saveCharacter(attributes);
  std::cout << rwData.readCharacter("eastwood") << '\n';

  string input;
  int value;
  while (true) {
    cin >> input;
    //std::cout << input << '\n';
    if(input == "exit"){
      rwData.saveCharacter(attributes);
      std::cout << "Saveing" << endl;
      break;
    }

    if(input == "roll"){
      cin >> value;
      uiDisplay.getDice(value,roller.getRandom(value));
    }

    if(input == "clear"){
      uiDisplay.clearDice();
    }

    if(input == "set"){
      cin >> input;
      cin >> value;
      attributes.setValue(input,value);
    }

    uiDisplay.updateUI(attributes);
  }

  std::cout << "EXIT" << endl;

  // Saver nowSaver;
  // nowSaver.save("hi this is data\nHi data im dad","test");
  // std::cout << nowSaver.read("test") << '\n';
  return 0;
}
