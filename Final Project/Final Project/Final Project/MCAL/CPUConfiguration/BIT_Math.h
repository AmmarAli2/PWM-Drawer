/*
 * IncFile1.h
 *
 * Created: 5/29/2022 8:34:17 PM
 *  Author: Ammar
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_


#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)
#define TGL_BIT(REG,BIT) REG^=(1<<BIT)
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)




#endif /* INCFILE1_H_ */