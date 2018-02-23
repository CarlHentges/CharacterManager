/**
*TODO:this
**/
#ifndef __ATTRIBUTES_H_INCLUDED__
#define __ATTRIBUTES_H_INCLUDED__

class Attributes;

#include <string>
#include <map>

class Attributes {
private:

  map<string, int> attributes;


  int STR,DEX,CON,INT,WIS,CHA,health,health_max,AC,speed;
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
    return attributes.find(attribute)->second;
  }

  int setValue(string attribute,int value){   //swich only woks on ints (so i made my own)
    attributes.find(attribute)->second = value;
    return 0;
  }

  Attributes (string cName,int attribute[10],string fluf){

    attributes["STR"] = attribute[0];
    attributes["DEX"] = attribute[1];
    attributes["CON"] = attribute[2];
    attributes["INT"] = attribute[3];
    attributes["WIS"] = attribute[4];
    attributes["CHA"] = attribute[5];

    attributes["HitPoints"] = attribute[6];
    attributes["HitPoints_MAX"] = attribute[7];
    attributes["Speed"] = attribute[8];
    attributes["Initiative"] = attribute[9];
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

  int getSpeed(){

  }

  int getHealth(){
    return getValue("HitPoints");
  }
  int getMaxHealth(){
    return getValue("HitPoints_MAX");
  }

  string getAttributes(){
    return to_string(getValue("STR"))+"\n"+to_string(getValue("DEX"))+"\n"+
           to_string(getValue("CON"))+"\n"+to_string(getValue("INT"))+"\n"+
           to_string(getValue("WIS"))+"\n"+to_string(getValue("CHA"));
  }

  ~Attributes (){
    //bye now
  }
};
#endif
