//
// Created by kentl on 2024/10/2.
//
#include "main.h"
#include "tim.h"
#include "usart.h"

extern uint8_t buffer [20];
extern uint16_t rx_message[20];
extern float tx_message[20];


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    if(htim->Instance==TIM6){
        rx_message[0]=((uint16_t)buffer[0]*8+buffer[1]/32)%2048;
        rx_message[1]=((uint16_t)buffer[1]*64+buffer[2]/4)%2048;
        rx_message[2]=((uint16_t)buffer[2]*512+buffer[3]*2+buffer[4]/128)%2048;
        rx_message[3]=((uint16_t)buffer[4]*16+buffer[5]/16)%2048;
        rx_message[4]=((uint16_t)buffer[5]/4)%4;
        rx_message[5]=((uint16_t)buffer[5])%4;

        tx_message[0]=((float)rx_message[0]-1024)/1320;
        tx_message[1]=((float)rx_message[1]-1024)/1320;
        tx_message[2]=((float)rx_message[2]-1024)/1320;
        tx_message[3]=((float)rx_message[3]-1024)/1320;
        tx_message[4]=rx_message[4];
        tx_message[5]=rx_message[5];

        HAL_UART_Transmit_DMA(&huart6,tx_message,6);
    }
}