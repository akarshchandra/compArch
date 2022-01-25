#include <bitset>
#include "Components.h"


ShiftLeft::ShiftLeft()
{
    data_i = bitset<32> (0);
    data_o = bitset<32> (0);
}

ShiftLeft::~ShiftLeft()
{
}
void ShiftLeft::input(bitset<32> data_in)
{
    data_i = data_in;
    data_o = this->sl_operation();
}
bitset<32> ShiftLeft::get_output(){
    return data_o;
}
bitset<32> ShiftLeft::sl_operation(){
    /*implement your shift-left here */
    // very easy, the bitset(c++) support some operator.
    // check http://www.cplusplus.com/reference/bitset/bitset/operators/
    
    return (data_i<<2);
    
}