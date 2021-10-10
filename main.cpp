
#include <iostream>

#include "include/Inotify.h"
using namespace std;
int main() {
  Inotify i =
      Inotify("/home/ahsan/ascipc/myfile", "modify", "open",
              [](char* path) { cout << "File " << path << " Modified \n"; });
  i.init();
  i.startAsync();
}