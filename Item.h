/**
#stores Data
**/
#ifndef __ITEM_H_INCLUDED__
#define __ITEM_H_INCLUDED__

class Item;

class Item {
private:
  string name;
  string description;
  int quantity;

public:

  Item (string newName):name(newName),quantity(1),description("NOT SET"){
  }
  ~Item (){
    //bye
  }
};

#endif
