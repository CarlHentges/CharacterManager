/**
*TODO:this
**/
#ifndef __ATTRIBUTES_H_INCLUDED__
#define __ATTRIBUTES_H_INCLUDED__

class Attributes;

#include <string>
#include <map>
#include <vector>
#include "Roller.h"
#include "Attack.h"


class Attributes {
private:

  map<string, int> attributes;
  map<string, string> skillMap;

  map<string,Attack> attackMap;
  int STR,DEX,CON,INT,WIS,CHA,health,health_max,AC,speed;
  string characterName = "";
  string fluff = "";

  int getValueExplicit(string attribute){ // needed for recursive call for skills value
    return attributes.find(attribute)->second;
  }

public:

  int modifier(string input){

    int baseValue = getValue(input) - 10;
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

  int getValue(string attribute){

    if(skillMap.find(attribute)!=skillMap.end()){
      return getValueExplicit(attribute)+
             getValue(skillMap.find(attribute)->second);
    }

    return attributes.find(attribute)->second;
  }

  int setValue(string attribute,int value){   //swich only woks on ints (so i made my own)
    if (attributes.find(attribute)!=attributes.end()) { // if found use that
      attributes.find(attribute)->second = value;
    }else{
      attributes[attribute] = value;
    }
    return 0;
  }

  Attributes(){
    //default attributs
    setValue("STR",0);
    setValue("DEX",0);
    setValue("CON",0);
    setValue("INT",0);
    setValue("WIS",0);
    setValue("CHA",0);
    setValue("HP",0);
    //skills
    setValue("Acrobatics",0);
    setValue("Animal_Handling",0);
    setValue("Arcana",0);
    setValue("Athletics",0);
    setValue("Deception",0);
    setValue("History",0);
    setValue("Insight",0);
    setValue("Intimidation",0);
    setValue("Investigation",0);
    setValue("Medicine",0);
    setValue("Nature",0);
    setValue("Perception",0);
    setValue("Preformance",0);
    setValue("Persuasion",0);
    setValue("Religion",0);
    setValue("Slight_of_Hand",0);
    setValue("Stealth",0);
    setValue("Survival",0);

    skillMap["Acrobatics"]="DEX";
    skillMap["Animal_Handling"]="WIS";
    skillMap["Arcana"]="INT";
    skillMap["Athletics"]="STR";
    skillMap["Deception"]="CHA";
    skillMap["History"]="INT";
    skillMap["Insight"]="WIS";
    skillMap["Intimidation"]="CHA";
    skillMap["Investigation"]="INT";
    skillMap["Medicine"]="WIS";
    skillMap["Nature"]="INT";
    skillMap["Perception"]="INT";
    skillMap["Preformance"]="CHA";
    skillMap["Persuasion"]="CHA";
    skillMap["Religion"]="INT";
    skillMap["Slight_of_Hand"]="DEX";
    skillMap["Stealth"]="DEX";
    skillMap["Survival"]="WIS";
    //other
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
    if (modifier(input) > 0 ) {
      mod = "+" + to_string(modifier(input));
    }else{
      mod = "" + to_string(modifier(input));
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

  // int getHealth(){
  //   return getValue("HitPoints");
  // }
  // int getMaxHealth(){
  //   return getValue("HitPoints_MAX");
  // }

  string getAttributes(){
    string temp = "";
    for (std::map<string,int>::iterator a = attributes.begin(); a != attributes.end(); ++a) {
      temp += "\n" + a->first + "," + to_string(a->second);
    }
    return temp;
  }


  bool isAttribute(string input){
    return attributes.find(input)!=attributes.end();
  }

  bool isAttack(string input){
    return attackMap.find(input)!=attackMap.end();
  }

  int newAttack(Attack attack){
    if(!isAttack(attack.name)){
      attackMap[attack.name] = attack;
    }else{
      attackMap.find(attack.name) -> second = attack;
    }
    return 0;
  }

  int loadAttack(string name,string hitAttribute,string damageAttribute,string damageType,vector<int> diceHit,vector<int> diceDamage, int hitMod,int damMod){
    attackMap[name] = Attack{name,hitAttribute,damageAttribute,damageType,diceHit,diceDamage,hitMod,damMod};
    return 0;
  }

  string getAttackData(){
    string temp = "\n";
    for (std::map<string,Attack>::iterator a = attackMap.begin(); a != attackMap.end(); ++a) {
      temp += "#ATTACK#\n";
      temp += a->second.name;
      temp +="\n";
      temp += a->second.hitAttribute;
      temp +="\n";
      temp += a->second.damageAttribute;
      temp +="\n";
      temp += a->second.damageType;
      temp +="\n";
      for (int d:a->second.diceHit) {
        temp +=to_string(d)+",";
      }
      temp +="\n";
      for(int d:a->second.diceDamage){
        temp +=to_string(d)+",";
      }
      temp +="\n";
      temp += to_string(a->second.hitMod);
      temp +="\n";
      temp += to_string(a->second.damMod);
      if(a  != attackMap.end()){
        temp += "\n";
      }
    }
    return temp;
  }

  string getAttack(string name,Roller &roller){
    string output = "Making Attack: ";
    int total = 0;
    int tempInt = 0;
    if(isAttack(name)){
      Attack temp = attackMap.find(name)->second;
      output += temp.name +"\nDamage type: "+temp.damageType+ "\nRolling hit Dice";
      for(int d: temp.diceHit){
        tempInt = roller.getRandom(d);
        output += " d" + to_string(d)+":"+to_string(tempInt);
        total += tempInt;
      }
      output += " Plus Hit modifier " + to_string(temp.hitMod);
      if(isAttribute(temp.hitAttribute)){
        output += " and "+temp.hitAttribute+" modifier " + to_string(modifier(temp.hitAttribute))
               + "\tHit Toal is: " + to_string(total + temp.hitMod +modifier(temp.hitAttribute));
      }else{
        output += "\tHit Toal is: " + to_string(total + temp.hitMod);
      }
      output +="\nROlling Damage:";
      total = 0;
      tempInt = 0;
      for(int d: temp.diceDamage){
        tempInt = roller.getRandom(d);
        output += " d" + to_string(d)+":"+to_string(tempInt);
        total += tempInt;
      }
      output += " Plus Damage modifier " + to_string(temp.damMod);
      if(isAttribute(temp.damageAttribute)){
        output += " and "+temp.damageAttribute+" modifier "+ to_string(modifier(temp.damageAttribute))
               + "\t Damage Toal is: " + to_string(total + temp.damMod+ modifier(temp.damageAttribute));
      }else{
        output += "\t Damage Toal is: " + to_string(total + temp.damMod);
      }
      return output;
    }
    return "NOT AN ATTACK";
  }

  ~Attributes (){
    //bye now
  }
};
#endif
