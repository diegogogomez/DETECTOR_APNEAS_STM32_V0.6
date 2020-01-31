
#include "interrupcion_periodica.h"
#include "stm32f4xx_hal.h"

extern uint16_t estado_de_muestreo;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance==TIM2){
		estado_de_muestreo = 1;
	}
}
