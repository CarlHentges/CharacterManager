#include <fstream>
#include <iostream>
#include <string>
#include "Saver.h"
#include "UIDisplay.h"
#include "Attributes.h"
#include "Roller.h"

using namespace std;

int main(){
    Roller roller;

  Attributes attributes(7,20,8,16,15,9);
  UIDisplay uiDisplay;
  Saver nowSaver;
  uiDisplay.updateUI(attributes);

  nowSaver.save("hi this is data\nHi data im dad","test");
  std::cout << nowSaver.read("test") << '\n';

  cin.get();
  system("CLS");
  return 0;
}
