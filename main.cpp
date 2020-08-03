#include <iostream>
#include <cstdlib>
#include"Stack.h"
#include "Stack.cpp"
#include "commands.h"

using namespace std;

int main(int argc , char* argv[])
{
    if(argc != 2)
    {
        cout<<"Invalid input";
        return 0;
    }
    Stack<char>Stack1;
    Stack<char>Stack2;
    Stack<char>tempStack;
    int dots_number ;
    int length = get_length(argv);
    if(check_dots(length,argv,dots_number) )
    {
        cout<<"Invalid input";
        return 0;
    }
    if(check_signs(length,argv))
    {
        cout<<"Invalid input";
        return 0;
    }
    if(check_numbers(length,argv))
    {
        cout<<"Invalid input";
        return 0;
    }
    if(check_number_after_dot(argv , length))
    {
        cout<<"Invalid input";
        return 0;
    }
    if(check_number_before_dot(argv , length))
    {
        cout<<"Invalid input";
        return 0;
    }
    string operation ;
    operation = get_operation(length , argv);
     int start = 0;
    string first_number_part1 = "";
    string first_number_part2 = "";
    string second_number_part1 = "";
    string second_number_part2 = "";
    char next ;
    start = get_number(start , argv , first_number_part1 , length , next);
//    cout<<first_number_part1<<' '<<start<<endl;
    if(next != '.')
        first_number_part2 = "0";
    else
        start = get_number(start , argv , first_number_part2 , length , next);
//    cout<<first_number_part2<<' '<<start<<endl;
    start = get_number(start , argv , second_number_part1 , length , next);
//    cout<<second_number_part1<<' '<<start<<endl;
    if(next != '.')
        second_number_part2 = "0";
    else
        start = get_number(start , argv , second_number_part2 , length , next);
//    cout<<second_number_part2<<' '<<start<<endl;

//    cout<<first_number_part1<<' '<<first_number_part2<<endl;
//    cout<<second_number_part1<<' '<<second_number_part2<<endl;

    for(int i =0 ; i< max(first_number_part2.size(), second_number_part2.size()); i++) // error here
    {
        if(int(first_number_part2[i]) < 48 || int(first_number_part2[i]) > 57 )
        {
            Stack1.push('0');
//            cout<<"0 will be pushed "<<endl;
        }

        else
        {
            Stack1.push(first_number_part2[i]);
//            cout<<first_number_part2[i]<<" will be pushed --- "<<endl;
        }

        if(second_number_part2[i] < 48 || second_number_part2[i] > 57 )
        {
            Stack2.push('0');
//            cout<<"0 will be pushed "<<endl;
        }

        else
        {
            Stack2.push(second_number_part2[i]);
//            cout<<second_number_part2[i]<<" will be pushed --- "<<endl;
        }
    }
    int carry = 0;
    int temp  = 0;
    string result_part1 = "";
    string result_part2 = "";
    if(operation == "add")
    {
        while(!Stack1.isempty())
        {
            temp = (int(Stack1.pop())-'0') + (int(Stack2.pop()) - '0') + carry;
            if(temp>=10)
                {
                    temp = temp %10;
                    carry = 1;
                }
            else
                carry = 0;
    //        result_part2 += temp + '0';
            tempStack.push(temp + '0');

        }

    }
    if(operation == "subtract")
    {
        while(!Stack1.isempty())
        {
            temp = (int(Stack1.pop())-'0') - (int(Stack2.pop()) - '0') + carry;
            if(temp < 0)
                {
                    temp += 10 ;
                    carry = -1;
                }
            else
                carry = 0;
    //        result_part2 += temp + '0';
            tempStack.push(temp + '0');

        }
    }

    while(!tempStack.isempty())
    {
        result_part2 += tempStack.pop();
    }
//    cout<<result_part2<<endl;
    int j = 0;
    int k = 0;
    for(int i = max(first_number_part1.size(), second_number_part1.size()) ; i> 0 ; i--)
    {
        if(i > first_number_part1.size())
        {
            Stack1.push('0');
//            cout<<"0 will be pushed "<<endl;
        }

        else
        {
            Stack1.push(first_number_part1[j]);
//            cout<<first_number_part1[j]<<" will be pushed "<<endl;
            j++;
        }

        if(i > second_number_part1.size())
        {
            Stack2.push('0');
//            cout<<"0 will be pushed "<<endl;
        }

        else
        {
            Stack2.push(second_number_part1[k]);
//            cout<<second_number_part1[k]<<" will be pushed "<<endl;
            k++;
        }

    }
    temp = 0 ;

     if(operation == "add")
    {
        while(!Stack1.isempty())
            {
      //        cout<<Stack1.top()<<" + "<<Stack2.top()<<" + "<<carry;
                temp = (int(Stack1.pop())-'0') + (int(Stack2.pop()) - '0') + carry;
      //        cout<<" = "<<temp<<endl;
                if(temp>=10)
                    {
                        temp = temp %10;
                        carry = 1;
                    }
                else
                    carry = 0;
                tempStack.push(temp + '0');

            }
        if(carry != 0)
            tempStack.push(carry + '0');

    }

    if (operation == "subtract")
        {
            while(!Stack1.isempty())
                {
          //        cout<<Stack1.top()<<" + "<<Stack2.top()<<" + "<<carry;
                    temp = (int(Stack1.pop())-'0') - (int(Stack2.pop()) - '0') + carry;
          //        cout<<" = "<<temp<<endl;
                    if(temp < 0)
                        {
                            temp += 10;
                            carry = -1;
                        }
                    else
                        carry = 0;
                    tempStack.push(temp + '0');

                }
        }

    while(!tempStack.isempty())
    {
        result_part1 += tempStack.pop();
    }
//    cout<<result_part1<<endl;
    if(all_zeros(result_part1))
        result_part1 = "0";
    if(dots_number == 0)
    {
        string final_result = result_part1;
        cout<<final_result;
        return 0;
    }


    string final_result = delete_zeros(result_part1) + '.' + result_part2 ;
    cout<<final_result;


    return 0;
}
