#include <bitset>
#include <string>
#include<iostream>
#include"Components.h"
using namespace std;


Control::Control()
{
    ctrl_i = bitset<6> (0);
    regDst_o = bitset<1> (0);
    regWrite_o = bitset<1> (0); 
    ALUop_o = bitset<2> (0);
    ALUsrc_o = bitset<1> (0);
    Branch_o = bitset<1> (0); 
}

Control::~Control()
{
}

void Control::input(bitset<6> ctrl_input)
{
    /* implement your own control method here*/
    // tips: map the opcode to the instruction type (r-type, i-type...etc) and decide the value for output signal.
    // private member XXX_i is for input, XXX_o is for output.
    // (1) Need to assign value to output (e.g. regDst_o, regWrite_o...)
    bitset<1> temp1 = bitset<1> ("1");
    bitset<1> temp0 = bitset<1> ("0");
    bitset<6> temp_op1 = bitset<6> ("001000");
    bitset<6> temp_op2 = bitset<6> ("000100");
    
    if(ctrl_input.none())
    {
       regDst_o=temp1;
       regWrite_o=temp1;
       ALUop_o=bitset<2> ("10");
       ALUsrc_o=temp0;
       Branch_o=temp0;
    }
    else if(ctrl_input==temp_op1)
    {
       regDst_o=temp0;
       regWrite_o=temp1;
       ALUop_o=bitset<2> ("00");
       ALUsrc_o=temp1;
       Branch_o=temp0;
    }
    else if(ctrl_input==temp_op2)
    {
       regDst_o=temp0;
       regWrite_o=temp0;
       ALUop_o=bitset<2> ("01");
       ALUsrc_o=temp0;
       Branch_o=temp1;
    }


}
bitset<1> Control::get_regdst(){
    return regDst_o;
}
bitset<1> Control::get_regwrite(){
    return regWrite_o;
}
bitset<2> Control::get_aluop(){
    return ALUop_o;
}
bitset<1> Control::get_alusrc(){
    return ALUsrc_o;
}
bitset<1> Control::get_branch(){
    return Branch_o;
}