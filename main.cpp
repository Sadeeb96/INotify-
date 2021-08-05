
#include <iostream>
#include "include/Inotify.h"
using namespace std;
int main(){
    Inotify i = Inotify("/home/ahsan/ascipc/","modify","create");
    i.init();
    i.startAsync();
    
}