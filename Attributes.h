/**
*TODO:this
**/
#ifndef __ATTRIBUTES_H_INCLUDED__
#define __ATTRIBUTES_H_INCLUDED__

class Attributes;

#include <string>

class Attributes {
private:
  int STR = 0;
  int DEX = 0;
  int CON = 0;
  int INT = 0;
  int WIS = 0;
  int CHA = 0;
  int health;
  int health_max;
  int AC;
  string characterName = "";
  string fluff = "";

public:

  int modifier(int baseValue){
    baseValue = baseValue - 10;
    if (baseValue >= 0) {
      return baseValue / 2;
    }else{
      baseValue --;
      return baseValue /2;
    }
  }

  int getValue(string attribute){   //swich only woks on ints (so i made my own)
    if (attribute == "STR") {return STR;}
    if (attribute == "DEX") {return DEX;}
    if (attribute == "CON") {return CON;}
    if (attribute == "INT") {return INT;}
    if (attribute == "WIS") {return WIS;}
    if (attribute == "CHA") {return CHA;}
  }

  int setValue(string attribute,int value){   //swich only woks on ints (so i made my own)
    if (attribute == "STR") {STR = value;return 0;}
    if (attribute == "DEX") {DEX = value;return 0;}
    if (attribute == "CON") {CON = value;return 0;}
    if (attribute == "INT") {INT = value;return 0;}
    if (attribute == "WIS") {WIS = value;return 0;}
    if (attribute == "CHA") {CHA = value;return 0;}

  }

  Attributes (string cName,int attribute[6],string fluf){
    STR = attribute[0];
    DEX = attribute[1];
    CON = attribute[2];
    INT = attribute[3];
    WIS = attribute[4];
    CHA = attribute[5];
    fluff = fluf;
    characterName = cName;
  }

  int print(){
    std::cout<<"["<<STR<<","<<DEX<<","<<CON<<","<<
                    INT<<","<<WIS<<","<<CHA<< "]\n";
    return 0;
  }

  string summarize(string input){
    string mod = "";
    string value = to_string(getValue(input));
    if (modifier(getValue(input)) > 0 ) {
      mod = "+" + to_string(modifier(getValue(input)));
    }else{
      mod = "" + to_string(modifier(getValue(input)));
    }
    if(getValue(input) > 9){
      return "[ " + value + " ](" + mod + ")";
    }else{
      return "[ " + value + " ] (" + mod + ")";
    }


    return 0;
  }

  string getName(){
    return characterName;
  }

  string getFluff(){
    return fluff;
  }


  string getAttributes(){
    return to_string(STR)+"\n"+to_string(DEX)+"\n"+
           to_string(CON)+"\n"+to_string(INT)+"\n"+
           to_string(WIS)+"\n"+to_string(CHA);
  }



  ~Attributes (){
    //bye now
  }
};
#endif
