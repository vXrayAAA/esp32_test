#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"															



#define CONFIG_FREERTOS_HZ 100	

//PINOS LCD
#define en 2
#define rs 3
#define lcdCLK	14                      			                        
#define lcdDaT	12                      			                        
#define lcdLOAD	5 

//ENTRADA
#define gpiCLK	12                       			                       
#define gpiDAT	13                       			                        
#define gpiLOAD	14                       			                        

//SAIDA
#define gpoCLK	12                       			                        
#define gpoDAT	27                       			                        
#define gpoLOAD	14


void lcdBits (unsigned char valor, unsigned char pinoRs)
{

}

void lcdIniciar (void)
{

}

void lcdTexto (char *palavras, unsigned char lin, unsigned char col)
{
    if(lin==1)lcdBits((127+col),0);
    if(lin==2)lcdBits((191+col),0);

    while (*palavras)
    {
        lcdBits(*palavras,1);
        palavras++;
    }
    
}

void gpioInit (void)
{

}

void app_main(void)
{

}
