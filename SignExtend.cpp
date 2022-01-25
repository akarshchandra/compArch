#include <iostream>
#include <bitset>
#include <string>

#include "Components.h"

SignExtend::SignExtend()
{
    data_i = bitset<16> (0);
    data_o = bitset<32> (0);
}

SignExtend::~SignExtend()
{
}

void SignExtend::input(bitset<16> input){
    data_i = input;
    data_o = this->extend(data_i);
}
bitset<32> SignExtend::get_output(){
    return data_o;
}

bitset<32> SignExtend::extend(bitset<16> input){
    /* implement your sign-extend funciton here */
    // becareful with the most significant bit.
    // if is 0110--> 000...0110
    // if is 1100--> 1111..1100
    // you have to consider two cases.
    string tempstr = input.to_string();
    bitset<32> result;
    if(input.test(15))
    {
     string temp1="1111111111111111";
     result= bitset<32> ((temp1+tempstr));
     return result;
    }
    else
    {
       string temp2="0000000000000000";
       result= bitset<32> ((temp2+tempstr));
       return result;
    }

}