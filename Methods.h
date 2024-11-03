#pragma once
#ifndef METHOD_H
#define METHOD_H
#include <string>
using namespace std;

string set_time();
void output(const string);
void cmd();
bool correct_choose(const string&);
bool correct_id(const string&);
bool correct_description(const string&);
void loading();

#endif