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
  Attributes attributes;

  attributes = rwData.loadCharacter("eastwood");
  uiDisplay.updateUI(attributes);
  string input;
  int value;
  while (true) {
    cin >> input;

    if(input == "load"){
      cin >> input;
      attributes = rwData.loadCharacter(input);
    }

    if (input == "save") {
      rwData.saveCharacter(attributes);
    }

    if(input == "help"||input == "h"){
      std::cout << "load:\nsave:\nroll:\nset:\nclear:\nexit:\n" << '\n';
      continue;
    }

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
