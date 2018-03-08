#ifndef __RWDATA_H_INCLUDED__
#define __RWDATA_H_INCLUDED__

class RWData;


#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include "Saver.h"

class RWData {
private:
  string s = "";

  string read(string name){
    Saver saver;
    string temp = saver.read(name);
    return temp;
  }

public:
  RWData (){
  }

  int saveCharacter(Attributes attributes){
    Saver saver;
    string tempData = "";
    tempData += s +"#NAME#" + "\n";
    tempData += attributes.getName();
    tempData += s +"\n" + "#ATTRIBUTES#";
    tempData += attributes.getAttributes();
    //tempData += s +"\n" + "#ATTACK#";
    tempData += attributes.getAttackData();
    tempData += s + "#FLUFF#";
    tempData += attributes.getFluff();
    tempData += s +"\n" + "#END#";
    saver.save(tempData,attributes.getName());

    return 0;
  }

  Attributes loadCharacter(string name){
    Saver saver;

    Attributes attributes;

    string temp = "";
    string status ="";
    int count = 0;

    if(!saver.exists(name)){
      attributes.setName(name);
      return attributes;
    }

    istringstream input(read(name));
    std::cout << "2" << '\n';
    while (getline(input,temp)){
      std::cout << "temp:" << temp << " status: " << status<< '\n';
      if(temp == "#NAME#"){
        status = "NAME";
        continue;
      }
      if(temp == "#ATTRIBUTES#"){
        status = "ATTRIBUTES";
        continue;
      }
      if(temp == "#FLUFF#"){
        status = "FLUFF";
        continue;
      }

      if(temp == "#ATTACK#"){
        status = "ATTACK";
        continue;
      }

      if(temp == "#END#"){
        break;
      }

      if(status == "NAME"){
        attributes.setName(temp);
        continue;
      }

      if (status == "ATTRIBUTES") {
        int pos = temp.find(",");
        std::cout << temp.substr(0,pos) << " <><> "  << stoi(temp.substr(pos+1))<< '\n';
        attributes.setValue(temp.substr(0,pos),stoi(temp.substr(pos+1)));
        continue;
      }

      if(status == "ATTACK"){
        string name = temp;
        getline(input,temp);
        string hitAttribute = temp;
        getline(input,temp);
        string damageAttribute = temp;
        getline(input,temp);
        string damageType = temp;
        getline(input,temp);
        vector<int> diceHit = toVector(temp);
        getline(input,temp);
        vector<int> diceDamage = toVector(temp);
        getline(input,temp);
        std::cout << temp << '\n';
        int hitMod = stoi(temp);
        getline(input,temp);
        std::cout << temp << '\n';
        int damMod = stoi(temp);
        attributes.loadAttack(name,hitAttribute,damageAttribute,damageType,diceHit,diceDamage,hitMod,damMod);
        std::cout << "done" << '\n';
        continue;
      }

      if(status == "FLUFF"){
        attributes.setFluff(attributes.getFluff() + "\n" + temp);
        continue;
      }
    }
    return attributes;
  }

  vector<int> toVector(string input){
    string temp = "";
    vector<int> tempVector;
    for(int i = 0; i < input.length();i++){
      if(isdigit(input.at(i))){
        temp += input.at(i);
      }else{
        tempVector.push_back(stoi(temp));
        temp = "";
      }
    }
    return tempVector;
  }


  ~RWData (){
    //bye
  }
};
#endif
