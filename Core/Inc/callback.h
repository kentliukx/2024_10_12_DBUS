//
// Created by kentl on 24-10-12.
//

#ifndef CALLBACK_H
#define CALLBACK_H

#include "usart.h"

extern uint8_t buffer [20];
extern uint16_t rx_message[20];
extern float tx_message[20];

void DMA_Idle_Callback(void)
{
    HAL_UART_DMAStop(&huart1);
    __HAL_UART_CLEAR_IDLEFLAG(&huart1);
    HAL_UART_Receive_DMA(&huart1,buffer,20);
}

#endif //CALLBACK_H
