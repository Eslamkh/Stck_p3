#include"commands.h"

bool check_dots(int length,char *argv[], int& dots)
{
    dots =0;

    for(int i =0 ; i<length ; i++)
    {
        if(argv[1][i]== '.')
            dots++;
    }
    if(dots >2)
        return true ;
    else
        return false ;
}

bool check_signs(int length,char *argv[])
{
   int signs = 0 ;
   for(int i =0 ; i<length ; i++)
    {
        if(argv[1][i]== '+' || argv[1][i]== '-')
            signs++;
    }
    if(signs != 1)
        return true;
    else
        return false;
}

bool check_numbers(int length,char *argv[])
{
   int flag = 0 ;
//   cout<<"length = "<<length<<' ';
   for(int i =0 ; i<length ; i++) // error here
    {
        if(argv[1][i]!= '+' && argv[1][i]!= '-' && argv[1][i]!= '.' && (int(argv[1][i])<48 || int(argv[1][i])>57 ))
        {
            flag = 1;
            break;
        }

    }
    if(flag==1)
        return true;
    else
        return false;
}


int get_length(char* argv[])
{
    int i = 0;
    while(argv[1][i] != '\0')
    {
        i++;
    }
    return i ;
}

string get_operation(int length ,char* argv[])
{
    string operation = "";
    for (int i =0 ; i<length ; i++)
    {
        if(argv[1][i] == '+')
            operation = "add";
        if(argv[1][i]== '-')
            operation = "subtract";
    }
    return operation ;
}

int get_number(int start , char* argv[], string &number , int length , char &next)
{
    int i = start ;
    for ( i = start ; i<length ; i++)
    {
        if(argv[1][i] == '.' || argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '\0')
        {
            next = argv[1][i];
            break ;
        }
        number += argv[1][i];
    }
    return i+1 ;
}
bool all_zeros(string result)
{
    int zeros = 0;
    for(int i =0 ; i<result.size() ; i++)
    {
        if(result[i]== '0')
            zeros++;
    }
    if(zeros == result.size())
        return true ;
    else
        return false;
}
bool check_number_after_dot(char *argv[] , int length)
{
    for(int i =0 ; i<length-1 ; i++)
    {
        if(argv[1][i] == '.' && ( argv[1][i+1]== '+' || argv[1][i+1]== '-' ) )
           {
               return true ;
           }
    }
    return false ;
}
bool check_number_before_dot(char *argv[] , int length)
{
    if(argv[1][0] == '.')
        return true ;
    for(int i =0 ; i<length-1 ; i++)
    {
        if((argv[1][i] == '+' || argv[1][i] == '-') && argv[1][i+1] == '.' )
           {
               return true ;
           }
    }
    return false ;
}
string delete_zeros(string result)
{
    int i ;
    string output = "";
    if(result.size() == 1 )
        return result ;
    for (i=0; i < result.size() ; i++)
    {
        if(result[i] == '0' && result[i+1]=='0')
        {
            continue ;
        }
        break ;
    }
    if(result[i] == '0')
        i++;
    for(i = i ; i<result.size() ; i++)
    {
        output += result[i];
    }
    return output ;
}
