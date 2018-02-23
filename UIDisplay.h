/**
*TODO this
**/
#ifndef __UIDISPLAY_H_INCLUDED__
#define  __UIDISPLAY_H_INCLUDED__

class UIDisplay;

#include <string>
#include <cstdio>
#include <iomanip>
//#include <cstdlib>
#include "Attributes.h"

class UIDisplay {
private:
  string previousRolls = "ROLLS:";

public:
  UIDisplay (){

  }
  updateUI(Attributes attributes){
    system("cls");
    showLine();
    showName(attributes);
    showLine();
    showAttributes(attributes);
    showHealth(attributes);
    showSpeed(attributes);
    showLine();
    showFluff(attributes);
    showLine();
    displayDice();
    showLine();
  }

  int showLine(){
    std::cout << "**************************************************" << endl;
  }

  int showAttributes(Attributes attributes){
    std::cout << "ATTRIBUTES:" << endl <<
                 "STR "<< attributes.summarize("STR") << endl  <<
                 "DEX "<< attributes.summarize("DEX") << endl  <<
                 "CON "<< attributes.summarize("CON") << endl  <<
                 "INT "<< attributes.summarize("INT") << endl  <<
                 "WIS "<< attributes.summarize("WIS") << endl  <<
                 "CHA "<< attributes.summarize("CHA") << endl;
    return 0;
  }

  int showFluff(Attributes attributes){
    std::cout << "DESCRIPTION:" << endl << attributes.getFluff() <<endl ;
    return 0;
  }

  int showName(Attributes attributes){
    std::cout << "NAME:" << endl <<attributes.getName() <<endl ;
    return 0;
  }

  int showHealth(Attributes attributes){
    std::cout << "HP: "<<attributes.getValue("HP")<<"/"<<
                                attributes.getValue("HP_MAX") << endl;
  }

  int displayDice(){
    std::cout << previousRolls << endl;
    return 0;
  }

  int getDice(int dice, int result){
    previousRolls += "\nd"+to_string(dice) +":\t"+to_string(result);
    return 0;
  }

  int clearDice(){
    previousRolls = "ROLLS:";
    return 0;
  }

  int showSpeed(Attributes attributes){
    std::cout << attributes.getSpeed() << "ft\t[" << attributes.getSpeed()/5
                                                 << "]sq" <<endl;
  }

  ~UIDisplay (){
    //bye
  }
};

#endif
