
#ifndef __TIMERINTERRUPTCALLBACK__
#define __TIMERINTERRUPTCALLBACK__
#include "stm32f4xx_hal.h"

class TimerInterrupt
{
private:

public:
	void TIM7interrupt();
	void TIM10interrupt();
	void TIM11interrupt();
	void TIM13interrupt();
	void TIM14interrupt();
};

















#endif
