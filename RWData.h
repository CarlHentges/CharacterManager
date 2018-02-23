#ifndef __RWDATA_H_INCLUDED__
#define __RWDATA_H_INCLUDED__

class RWData;


#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include "Saver.h"

class RWData {
private:
  string seperator = "###";
public:
  RWData (){
  }

  int saveCharacter(Attributes attributes){
    Saver saver;
    string tempData = "";
    tempData += seperator + "\n";
    tempData += attributes.getName();
    tempData += "\n" + seperator + "\n";
    tempData += attributes.getAttributes();
    tempData += "\n" + seperator + "\n";
    tempData += attributes.getFluff();

    saver.save(tempData,attributes.getName());

    return 0;
  }

  string readCharacter(string charName){
    Saver saver;
    string temp = saver.read(charName);
    return temp;
  }


  ~RWData (){
    //bye
  }
};
#endif
