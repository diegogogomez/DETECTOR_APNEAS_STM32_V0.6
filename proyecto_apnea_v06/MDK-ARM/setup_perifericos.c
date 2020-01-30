#include "main.h"
#include "stm32f4xx_hal.h"
#include "setup_perifericos.h"

extern ADC_HandleTypeDef hadc1;

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim5;

extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart3;


void setup_uart3(void){
	
	HAL_UART_MspInit(&huart3);											//inicialización del puerto serial para transmitir y recibir
	__HAL_UART_ENABLE_IT(&huart3,UART_IT_RXNE);			//habilita las interrupciones recibidas del pin rb11 RX
	
	
}
