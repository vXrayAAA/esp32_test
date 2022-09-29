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
#define gpiCLK	12                       			                        // Seleciona o pino de 'clock' para o registrador.
#define gpiDAT	13                       			                        // Seleciona o pino de 'data in' para o registrador.
#define gpiLOAD	14                       			                        // Seleciona o pino de 'load' para o registrador.

//SAIDA
#define gpoCLK	12                       			                        // Seleciona o pino de 'clock' para o registrador.
#define gpoDAT	27                       			                        // Seleciona o pino de 'data out' para o registrador.
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

void gpiInit (void)
{
  gpio_reset_pin(gpiCLK);
  gpio_reset_pin(gpiDAT);
  gpio_reset_pin(gpiLOAD);

  gpio_set_direction(gpiCLK,GPIO_MODE_OUTPUT);
  gpio_set_direction(gpiDAT,GPIO_MODE_INPUT);
  gpio_set_direction(gpiLOAD,GPIO_MODE_OUTPUT);

  gpio_set_level(gpiCLK,0);
  gpio_set_level(gpiDAT,0);
  gpio_set_level(gpiLOAD,0);
}

void app_main(void)
{
  char *aviso = pcTaskGetName("__LCD");

  ESP_LOGI(aviso,"iniciando");


  lcdIniciar();

  lcdTexto("vXray",1,3);
  while(1)
  {

  }
}
