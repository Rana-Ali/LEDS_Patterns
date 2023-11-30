#ifndef LED_PRIVATE_H_
#define LED_PRIVATE_H_

#define Valid_pattern (((key>currentstate)&&\
                       (key<NumberOfPatterns))||\
					   key==IDLE)

#endif
