#ifndef BIT_MATH_H_
#define BIT_MATH_H_
/*Set bit*/
#define SET_BIT(Reg,bit) Reg=Reg|(1<<bit) 
/*Clear bit*/
#define CLEAR_BIT(Reg,bit) Reg=Reg&(~(1<<bit))
/*Get bit*/
#define GET_BIT(Reg,bit) ((Reg>>bit)&1)
/*Toggle bit*/
#define TOGGLE_BIT(Reg,bit) Reg=Reg^(1<<bit) 

#endif