#include "Object.h"

Object::Object(){}
Object::Object(string name, string tag)
{
    this -> name = name;
    this -> tag = tag;
}
void Object::set_name(string name)
{
    this -> name = name;
}
void Object::set_tag(string tag)
{
    this -> tag = tag;
}
string Object::get_name()
{
    return this -> name;
}
string Object::get_tag()
{
    return this -> tag;
}
