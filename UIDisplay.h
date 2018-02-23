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
  /* data */

public:
  UIDisplay (){

  }

  updateUI(Attributes attributes){
    system("cls");
    showLine();
    showName(attributes);
    showLine();
    showAttributes(attributes);
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

  ~UIDisplay (){
    //bye
  }
};

#endif
