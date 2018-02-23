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
    tempData += s +"\n" + "#FLUFF#";
    tempData += attributes.getFluff();
    saver.save(tempData,attributes.getName());

    return 0;
  }

  Attributes loadCharacter(string name){
    Saver saver;

    Attributes attributes;

    string temp = "";
    string status ="";

    if(!saver.exists(name)){
      attributes.setName(name);
      return attributes;
    }

    istringstream input(read(name));
    std::cout << "2" << '\n';
    while (getline(input,temp)){
      std::cout << "3 temp:" << temp << " status: " << status<< '\n';
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

      if(status == "FLUFF"){
        attributes.setFluff(attributes.getFluff() + "\n" + temp);
        continue;
      }
    }
    return attributes;
  }


  ~RWData (){
    //bye
  }
};
#endif
