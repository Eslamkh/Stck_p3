#ifndef _COMMANDS_H
#define _COMMANDS_H

#include <string>
#include <iostream>
using namespace std ;

bool check_dots(int length , char* argv[] , int &dots);
bool check_signs(int length , char* argv[]);
bool check_numbers(int length , char* argv[]); // error here
int get_length(char* argv[]);
int get_number(int start , char* argv[] , string &number , int length , char &next);
bool all_zeros(string result);
bool check_number_after_dot(char *argv[] , int length);
string delete_zeros(string result);
string get_operation(int length , char* argv[]);
bool check_number_before_dot(char *argv[] , int length);
#endif // _COMMANDS_H
