#ifndef __IO_H
#define __IO_H	 
#include "sys.h"

#define IO_0 PFout(6)
#define IO_1 PFout(4)
#define IO_2 PFout(2)
#define IO_3 PFout(0)
#define IO_4 PEout(0)	
#define IO_5 PEout(2)	
#define IO_6 PEout(4)
#define IO_7 PEout(6)

void IO_Init(void);//IO≥ı ºªØ
void Config_io(u8 num);    
#endif
