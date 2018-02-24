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

  uiDisplay.updateUI(attributes);
  string input;
  int value;
  while (true) {
    cin >> input;

    if(input == "load"){
      cin >> input;
      attributes = rwData.loadCharacter(input);
      uiDisplay.clearDice();
    }

    if (input == "save") {
      rwData.saveCharacter(attributes);
    }

    if(input == "help"||input == "h"){
      std::cout << "load:\nsave:\nroll:\nset:\nclear:\nexit:\n" << '\n';
      continue;
    }

    if(input == "exit"||input == "e"||input == "q"){
      if(attributes.getName()!=""){
        rwData.saveCharacter(attributes);
        std::cout << "Saveing" << endl;
      }
      break;
    }

    if(input == "roll"||input == "r"){
      cin >> input;
      if(attributes.isAttribute(input)){
        uiDisplay.getCheck(input,roller.getRandom(20)+attributes.modifier(input));
      }else{
        value = stoi(input);
        uiDisplay.getDice(value,roller.getRandom(value));
      }
    }

    if(input == "clear"){
      uiDisplay.clearDice();
    }

    if(input == "set"){
      cin >> input;
      if(input == "name"||input == "Name"){ // RISK OF CHASH TODO: secure this
        cin >> input;
        attributes.setName(input);
      }else{
        cin >> value;
        attributes.setValue(input,value);
      }
    }

    uiDisplay.updateUI(attributes);
  }

  std::cout << "EXIT" << endl;

  // Saver nowSaver;
  // nowSaver.save("hi this is data\nHi data im dad","test");
  // std::cout << nowSaver.read("test") << '\n';
  return 0;
}
