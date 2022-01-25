#include <bitset>
#include <string>
#include<iostream>
#include"Components.h"
using namespace std;

Alu::Alu()
{
    src0_i = bitset<32> (0);
    src1_i = bitset<32> (0);
    aluctrl_i = bitset<4> (0);
    result_o = bitset<32> (0);
    zero_o = bitset<1> (0); 
}

Alu::~Alu()
{
}
void Alu::input(bitset<32> src_0, bitset<32> src_1, bitset<4> alu_ctrl){
    src0_i = src_0;
    src1_i = src_1;
    aluctrl_i = alu_ctrl;
    alu_operation(); // assign the result to output private member (output)
}
void Alu::alu_operation(){
    /* Your implementation of the Alu  */
    /* 1. Need to assign calculation result to result_o
       2. Need to set zero_o to 1 if result_o is zero. 
    */
    bitset<4>  temp_alu_add = bitset<4> ("0010");
    bitset<4>  temp_alu_sub = bitset<4> ("0110");
    if(aluctrl_i==temp_alu_add)
    {
        bitset<32> result_o = bitset<32> (src0_i.to_ulong() + src1_i.to_ulong());
    }
    else if(aluctrl_i==temp_alu_sub)
    {
       bitset<32> result_o = bitset<32> (src0_i.to_ulong() - src1_i.to_ulong());
    }
    if(result_o.to_ulong()==0)
    {
       zero_o = bitset<1> ("0");
    }
    
}
bitset<32> Alu::get_output()
{ return result_o;}
bitset<1> Alu::get_zero()
{ return zero_o;}