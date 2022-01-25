#include <bitset>
#include <string>
#include<iostream>
#include"Components.h"

AluControl::AluControl(/* args */)
{
    func_i = bitset<6> (0);
    aluop_i = bitset<2> (0);
    aluctrl_o = bitset<4> (0);
}

AluControl::~AluControl()
{
}

void AluControl::input(bitset<6> func, bitset<2> aluop){
    func_i = func;
    aluop_i = aluop;
    aluctrl_o = this->map_aluctrl_code();
}

bitset<4> AluControl::get_output(){
    return aluctrl_o;
}

bitset<4> AluControl::map_aluctrl_code()
{
    /* Implement your ALU Control here */
    //every input is already assign to private member, you can use directly.
    //what you need to return: the correct ALU control code  
    //hint: use aluop_i(ALUop) and func_i(function code) to decide what is the alu control code.
    bitset<2>  beq = bitset<2> ("01");
    bitset<2>  rtyp = bitset<2> ("10");
    bitset<6>  add_f = bitset<6> ("100000");
    bitset<6>  sub_f = bitset<6> ("100010");
    if(aluop_i.none())
    {
       bitset<4>  temp_oc1 = bitset<4> ("0010");
       return temp_oc1;
    }
    else if(aluop_i==beq)
    {
       bitset<4>  temp_oc1 = bitset<4> ("0110");
       return temp_oc1;
    }
    else if(aluop_i==rtyp && func_i==add_f)
    {
       bitset<4>  temp_oc1 = bitset<4> ("0010");
       return temp_oc1;
    }
    else if(aluop_i==rtyp && func_i==sub_f)
    {
       bitset<4>  temp_oc1 = bitset<4> ("0110");
       return temp_oc1;
    }

}