/**
*TODO this
**/
#ifndef __SAVER_H_INCLUDED__
#define __SAVER_H_INCLUDED__

class Saver;

#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

class Saver {
  public:

    Saver(){
      //helloThere.jpeg
    }

    int save(string data,string fileName){
    ofstream saveFile (fileName + ".txt");
    saveFile << data;
    saveFile.close();
    return 0;
  }

  int append(string data,string fileName){
    //TODO: this method appends the current file with the given data
    return 0;
  }

  string read(string fileName){
    string tempData;
    string str;
    ifstream saveFile (fileName + ".txt");
    while (!saveFile.eof()) {
      getline(saveFile,str);
      tempData += str + "\n";
    }
    return tempData;
  }

  ~Saver(){
    //Bye Bye
  }

};

#endif
