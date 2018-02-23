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

  int setName(string name){
    characterName = name;
    return 0;
  }

  int getValue(string attribute){   //swich only woks on ints (so i made my own)
    return attributes.find(attribute)->second;
  }

  int setValue(string attribute,int value){   //swich only woks on ints (so i made my own)
    if (attributes.find(attribute)!=attributes.end()) {
      attributes.find(attribute)->second = value;
    }else{
      attributes[attribute] = value;
    }
    return 0;
  }

  Attributes(){
    setValue("STR",0);
    setValue("DEX",0);
    setValue("CON",0);
    setValue("INT",0);
    setValue("WIS",0);
    setValue("CHA",0);
    setValue("HP",0);
    setValue("HP_MAX",0);
    setValue("Speed",0);
    setValue("AC",0);
    setFluff("");
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

  int setFluff(string newFluff){
    fluff = newFluff;
    return 0;
  }

  int getSpeed(){
    return getValue("Speed");
  }

  int getHealth(){
    return getValue("HitPoints");
  }
  int getMaxHealth(){
    return getValue("HitPoints_MAX");
  }

  string getAttributes(){
    string temp = "";
    for (std::map<string,int>::iterator a = attributes.begin(); a != attributes.end(); ++a) {
      temp += "\n" + a->first + "," + to_string(a->second);
    }
    return temp;
  }



  ~Attributes (){
    //bye now
  }
};
#endif
