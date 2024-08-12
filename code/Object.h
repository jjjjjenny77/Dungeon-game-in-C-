#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Object{
private:
    string name;
    string tag;
public:
    Object();
    Object(string, string);
    void set_name(string);
    void set_tag(string);
    string get_name();
    string get_tag();
    virtual bool triggerEvent(Object*) = 0;
};

#endif // OBJECT_H_INCLUDED
