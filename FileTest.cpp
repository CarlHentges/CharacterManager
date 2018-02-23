#include <fstream>
#include <iostream>
#include <string>
#include "Saver.h"
#include "UIDisplay.h"
#include "Attributes.h"
#include "Roller.h"
#include "RWData.h"
using namespace std;

int main(){

  Roller roller;
  UIDisplay uiDisplay;
  RWData rwData;

  int a[6] = {7,20,8,16,15,9};
  Attributes attributes("eastwood",a,"MAN WITH NO NAME");
  uiDisplay.updateUI(attributes);
  rwData.saveCharacter(attributes);
  std::cout << rwData.readCharacter("eastwood") << '\n';

  // Saver nowSaver;
  // nowSaver.save("hi this is data\nHi data im dad","test");
  // std::cout << nowSaver.read("test") << '\n';

  cin.get();
  return 0;
}
