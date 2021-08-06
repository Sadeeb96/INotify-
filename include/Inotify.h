#ifndef INOTIFY_CPP
#define INOTIFY_CPP
#include "common.h"
#include "modes.h"
#include "defines.h"
#include <iostream>
#include <string>
#include <functional>
class Inotify
{
private:
    std::function<void(char*)> _cBack;
    int _fileD;
    int _watchD;
    std::string path;
    char buffer[BUFFER_LEN];
    int _mode=0;
    
public:
    template <class... T2>
    Inotify(std:: string path, T2... modes){
        this->path = path;
        setModes(modes...);
        
    }
    void init(){
        _fileD = inotify_init();
        _watchD = inotify_add_watch(_fileD, path.c_str(), _mode );
    }
    void startAsync(){
        start();
    }
    int mode(){
        return _mode;
    }
    ~Inotify(){

    }
private:    
    void start(){
        int len;
        while (true)
        {
            len = read(_fileD,buffer,BUFFER_LEN);
            std::cout<<"Change"<<" "<<len<<std::endl;
            
            int i=0;
            while (i<len)
            {
                inotify_event* event = (inotify_event*)&buffer[i];
                bool isDir = event->mask & IN_ISDIR;
                _cBack(event->name);
                i+= EVENT_SIZE + event->len;
            }
            
        }
        
    }
    template <class T>
    void setModes(T var){
        //_mode = _mode | getMode(var);
        _cBack = var;
        
    }
    template <class T1,class... T2>
    void setModes(T1 arg1 ,T2... args){
        _mode = _mode | getMode(arg1);
        setModes(args...);
    }
};


#endif