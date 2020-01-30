
#include "main.h"
#include "stm32f4xx_hal.h"
#include "recepcion_serial.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char rxData1[70];
char rxData2[70];
char dato1;
uint8_t index1 = 0;
uint8_t dato = 0;
uint16_t coma = 0;

char primer_dato[25];
int primer_dato_entero = 0;
char segundo_dato[25];
int segundo_dato_entero = 0;
char tercer_dato[25];
char cuarto_dato[25];
char quinto_dato[25];
char sexto_dato[25];


extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart3;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance==USART3){
		if(dato1 != 10){ // If received data different from LF
			if(index1 == 0){
				memset(rxData1, 0, sizeof(rxData1));
			}
			rxData1[index1++] = dato1;    // Add data to Rx_Buffer
		}
		else{
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_14);
			
			for(int i = 0; i < sizeof(rxData1)-1; i++){
				rxData2[i] = rxData1[i];
			}
			
			////////////////////////inicio de tratamiento para arreglo////////////////////////////
				memset(primer_dato, 0, sizeof(primer_dato));					///limpia arreglo val_contador
				memset(segundo_dato, 0, sizeof(segundo_dato));
				memset(tercer_dato, 0, sizeof(tercer_dato));
				memset(cuarto_dato, 0, sizeof(cuarto_dato));
				memset(quinto_dato, 0, sizeof(quinto_dato));
				memset(sexto_dato, 0, sizeof(sexto_dato));
			
			dato = 0;
			coma = 0;
			for(int j = 0; j < sizeof(rxData2); j++){
				if(rxData2[j] == ','){
					dato++;
					coma = j + 1;
				}
				if(dato == 0 && rxData2[j] != '['){
					primer_dato[j-1] = rxData2[j];
				}
				else if(dato == 1 && ((rxData2[j] != ',' || rxData2[j] != ' ' || rxData2[j] != ']'))){
					segundo_dato[j-coma] = rxData2[j];
				}
				
			}
			primer_dato_entero = atoi(primer_dato);
			segundo_dato_entero = atoi(segundo_dato);
			
			index1 = 0;
		}
	}
	HAL_UART_Receive_IT(&huart3, (uint8_t *)&dato1, 1);
}
