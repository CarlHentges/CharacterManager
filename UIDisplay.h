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
#include <vector>
#include <tuple>

class UIDisplay {
private:

  std::vector<tuple<int,int>> previousRolls;

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
    showLine();
    showFluff(attributes);
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
    std::cout << "FLUFF:" << endl << attributes.getFluff() <<endl ;
    return 0;
  }

  int showName(Attributes attributes){
    std::cout << "NAME:" << endl <<attributes.getName() <<endl ;
    return 0;
  }

  int showHealth(Attributes attributes){
    std::cout << "HitPoints: "<<attributes.getHealth()<<"/"<<
                                attributes.getMaxHealth() << endl;
  }

  int displayDice(int dice, int result){
    for (size_t i = previousRolls.size(); i > previousRolls.size() - 10; i--) {
      std::cout <<"d["<< to_string(get<0>(previousRolls[i]))<< "] "<< to_string(get<1>(previousRolls[i]))<< endl;
      if(i == 0) break;
    }
    return 0;
  }

  int getDice(int dice, int result){
    previousRolls.push_back(tuple<int,int>(dice,result));
  }

  ~UIDisplay (){
    //bye
  }
};

#endif
