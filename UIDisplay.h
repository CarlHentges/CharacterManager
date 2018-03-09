/**
*
*TODO: re-write so only one print function and oters just update string to print
*TODO: make string 'zipping function' to display information side by side
**/
#ifndef __UIDISPLAY_H_INCLUDED__
#define  __UIDISPLAY_H_INCLUDED__

class UIDisplay;

#include <string>
#include <cstdio>
#include <iomanip>
#include "Attributes.h"

class UIDisplay {
private:
  string previousRolls = "ROLLS:";
//string frame; updated and printed
public:
  UIDisplay (){

  }
  updateUI(Attributes attributes){
    system("cls");
    showWelcome();
    showLine();
    showName(attributes);
    showSpeed(attributes);
    showHealth(attributes);
    showLine();
    showAttributes(attributes);
    showLine();
    showSkills(attributes);
    showLine();
    showFluff(attributes);
    showLine();
    displayDice();
    showLine();
  }

  int showWelcome(){
    cout <<"    _____ _                          _             ___  ___                                     \n"<<
           "   /  __ | |                        | |            |  \\/  |                                    \n"<<
           "   | /  \\| |__   __ _ _ __ __ _  ___| |_ ___ _ __  | .  . | __ _ _ __   __ _  __ _  ___ _ __   \n"<<
           "   | |   | '_ \\ / _` | '__/ _` |/ __| __/ _ | '__| | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ | '__|\n"<<
           "   | \\__/| | | | (_| | | | (_| | (__| ||  __| |    | |  | | (_| | | | | (_| | (_| |  __| |     \n"<<
           "    \\____|_| |_|\\__,_|_|  \\__,_|\\___|\\__\\___|_|    \\_|  |_/\\__,_|_| |_|\\__,_|\\__, |\\___|_|   \n"<<
           "                                                                              __/ |             \n"<<
           "                                                                             |___/              \n";
    return 0;
  }

  int showLine(){
    std::cout << "**************************************************" << endl;
  }

  int showAttributes(Attributes attributes){
    std::cout << "ATTRIBUTES:" << endl <<
                 "STR\t\t"<< attributes.summarize("STR") << endl  <<
                 "DEX\t\t"<< attributes.summarize("DEX") << endl  <<
                 "CON\t\t"<< attributes.summarize("CON") << endl  <<
                 "INT\t\t"<< attributes.summarize("INT") << endl  <<
                 "WIS\t\t"<< attributes.summarize("WIS") << endl  <<
                 "CHA\t\t"<< attributes.summarize("CHA") << endl;
    return 0;
  }

  int showSkills(Attributes attributes){
    std::cout << "SKILLS:" << endl <<
                "Acrobatics\t"<< attributes.summarize("Acrobatics")<<endl<<
                "Animal_Handling\t"<< attributes.summarize("Animal_Handling")<<endl<<
                "Arcana\t\t"<< attributes.summarize("Arcana")<<endl<<
                "Athletics\t"<< attributes.summarize("Athletics")<<endl<<
                "Deception\t"<< attributes.summarize("Deception")<<endl<<
                "History\t\t"<< attributes.summarize("History")<<endl<<
                "Insight\t\t"<< attributes.summarize("Insight")<<endl<<
                "Intimidation\t"<< attributes.summarize("Intimidation")<<endl<<
                "Investigation\t"<< attributes.summarize("Investigation")<<endl<<
                "Medicine\t"<< attributes.summarize("Medicine")<<endl<<
                "Nature\t\t"<< attributes.summarize("Nature")<<endl<<
                "Perception\t"<< attributes.summarize("Perception")<<endl<<
                "Preformance\t"<< attributes.summarize("Preformance")<<endl<<
                "Persuasion\t"<< attributes.summarize("Persuasion")<<endl<<
                "Religion\t"<< attributes.summarize("Religion")<<endl<<
                "Slight_of_Hand\t"<< attributes.summarize("Slight_of_Hand")<<endl<<
                "Stealth\t\t"<< attributes.summarize("Stealth")<<endl<<
                "Survival\t"<< attributes.summarize("Survival")<<endl;
    return 0;
  }

  int showFluff(Attributes attributes){
    std::cout << "DESCRIPTION:" << endl << attributes.getFluff() <<endl ;
    return 0;
  }

  int showName(Attributes attributes){
    std::cout << "NAME:" << "\t" <<attributes.getName() <<endl ;
    return 0;
  }

  int showHealth(Attributes attributes){
    std::cout << "HP: "<<attributes.getValue("HP")<<"/"<<
                                attributes.getValue("HP_MAX") << endl;
    return 0;
  }

  int displayDice(){
    std::cout << previousRolls << endl;
    return 0;
  }

  int getDice(int dice, int result){
    previousRolls += "\nd"+to_string(dice) +":\t"+to_string(result);
    return 0;
  }

  int getAttack(string attack){
    previousRolls += "\n" + attack;
    return 0;
  }

  int getCheck(string attribute,int result){
    previousRolls += "\nmaking "+attribute+" check: \t" + to_string(result);
    return 0;
  }

  int clearDice(){
    previousRolls = "ROLLS:";
    return 0;
  }

  int showSpeed(Attributes attributes){
    std::cout << attributes.getSpeed() << "ft\t[" << attributes.getSpeed()/5
                                                 << "]sq" <<endl;
    return 0;
  }

  ~UIDisplay (){
    //bye
  }
};

#endif
