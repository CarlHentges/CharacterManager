/**
#stores data
**/
#ifndef __ATTACK_H_INCLUDED__
#define __ATTACK_H_INCLUDED__

class Attack;

#include <vector>
#include <string>


class Attack {
private:
  vector<int> hitDice;
  vector<int> damageDice;
  int hitModifier;
  int damageModifier;
  string name;
  string baseAttribute;
  string damageType;
public:
  Attack (string name,vector<int> hit,vector<int> damage,int hitMod,int damMod):hitDice(hit),damageDice(damage),hitModifier(hitMod),damageModifier(damMod){
    // hi
  }

  ~Attack (){
    //bye
  }

};


#endif
