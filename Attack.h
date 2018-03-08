/**
#stores data
**/
#ifndef __ATTACK_H_INCLUDED__
#define __ATTACK_H_INCLUDED__

class Attack;

#include <vector>
#include <string>

struct Attack {
  string name;
  string hitAttribute;
  string damageAttribute;
  string damageType;
  vector<int> diceHit;
  vector<int> diceDamage;
  int hitMod,damMod;
};

#endif
