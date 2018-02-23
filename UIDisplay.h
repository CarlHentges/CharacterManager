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
    std::cout << "**************************************************" << endl  <<
                 "STR "<< attributes.summarize("STR") << endl  <<
                 "DEX "<< attributes.summarize("DEX") << endl  <<
                 "CON "<< attributes.summarize("CON") << endl  <<
                 "INT "<< attributes.summarize("INT") << endl  <<
                 "WIS "<< attributes.summarize("WIS") << endl  <<
                 "CHA "<< attributes.summarize("CHA") << endl  <<
                 "**************************************************" <<endl ;
  }

  ~UIDisplay (){
    //bye
  }
};

#endif
