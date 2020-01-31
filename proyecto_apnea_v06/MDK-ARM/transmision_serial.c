#include "stm32f4xx_hal.h"
#include "transmision_serial.h"

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
}
