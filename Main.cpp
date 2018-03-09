#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Saver.h"
#include "UIDisplay.h"
#include "Attributes.h"
#include "Roller.h"
#include "RWData.h"
#include "Attack.h"
using namespace std;

int main(){

  Roller roller;
  UIDisplay uiDisplay;
  RWData rwData;
  Attributes attributes;
  Attack holder;
  uiDisplay.updateUI(attributes);
  string input;
  int value;
  vector<int> holdingVector;

  while (true) {
    cin >> input;

    roller.roll(roller.roll());

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

    if (input == "Attack"||input == "a") {
      cin >> input;
      if(attributes.isAttack(input)){
        uiDisplay.getAttack(attributes.getAttack(input,roller));
      }else{
        holder.name = input;
        std::cout << "new Attack: " << input << "give hit attribute or leave blanck for no hit attribute\n or press q to cancel...\n";
        cin >> input;
        if(input != "q"){
          if(attributes.isAttribute(input) || input == ""){
            holder.hitAttribute = input;
          }

          cout <<"give damage attribute or _ for no hit attribute\n";
          cin >> input;

          if(attributes.isAttribute(input) || input == ""){
            holder.damageAttribute = input;
          }

          cout <<"damage type\n";
          cin >> input;
          holder.damageType = input;
          holdingVector.clear();
          cout << "enter hit dice" << '\n';
          cin >> input;
          while(isdigit(input.at(0))){
            cout << input <<" next or character if finished" << '\n';
            holdingVector.push_back(stoi(input));
            cin >> input;
          }
          holder.diceHit = holdingVector;
          holdingVector.clear();
          cout << "enter damage dice" << '\n';
          cin >> input;

          holdingVector.clear();

          while(isdigit(input.at(0))){
            cout << input <<" next or character if finished" << '\n';
            holdingVector.push_back(stoi(input));
            cin >> input;
          }

          holder.diceDamage = holdingVector;

          cout << "hit modifier" << '\n';
          cin >> input;
          holder.hitMod = stoi(input);

          cout << "damge modifier" << '\n';
          cin >> input;
          holder.damMod = stoi(input);

          attributes.newAttack(holder);
        }
      holder = {"","","","",{},{},0,0};
      }
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
