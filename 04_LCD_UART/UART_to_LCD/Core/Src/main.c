#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "string.h"


UART_HandleTypeDef huart1;

I2C_HandleTypeDef hi2c1;
UART_HandleTypeDef huart2;

#define I2C_ADDRESS_LCD 0x27 << 1

void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
void lcd_init(void);
void lcd_send_string(char *str);

static void MX_I2C1_Init(void);
void Error_Handler(void);
void uart_init(void);


uint8_t Tx_buffer[10] = " Rathna_CR";
uint8_t Rx_buffer[10];
uint8_t Additional_Buffer[10];

uint32_t Rx_counter, Tx_counter;

char str[20];

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	Tx_counter++;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	Rx_counter++;

	// Display received data on the LCD
	lcd_send_string((char *)Rx_buffer);

	// Re-enable UART receive interrupt to continue receiving data
	HAL_UART_Receive_IT(huart, Rx_buffer, 10);

}


int main()
{

  HAL_Init();
  uart_init();
  MX_I2C1_Init();
  lcd_init();
  HAL_Delay(1000);  // Wait for LCD to initialize
  lcd_send_string("Hello World!");
  HAL_Delay(5000);
  lcd_send_cmd(0x01);

  HAL_UART_Transmit_IT(&huart1,Tx_buffer,10);
  HAL_UART_Receive_IT(&huart1,Rx_buffer,10);
  while(1)
  {
  }
}


void lcd_init(void)
{
    HAL_Delay(50);          // Wait for LCD to power up
    lcd_send_cmd(0x02);     // initialize LCD in 4-bit mode
    HAL_Delay(50);
    lcd_send_cmd(0x28);     // 2 line, 5*7 matrix
    HAL_Delay(50);
    lcd_send_cmd(0x0c);     // display on, cursor off
    HAL_Delay(50);
    lcd_send_cmd(0x80);     // force cursor to beginning (1st line)
    HAL_Delay(50);
}

void lcd_send_cmd(char cmd)
{
    char data_u, data_l;
    uint8_t data_t[4];
    data_u = (cmd & 0xf0);
    data_l = ((cmd << 4) & 0xf0);
    data_t[0] = data_u | 0x0C;  // en=1, rs=0
    data_t[1] = data_u | 0x08;  // en=0, rs=0
    data_t[2] = data_l | 0x0C;  // en=1, rs=0
    data_t[3] = data_l | 0x08;  // en=0, rs=0
    HAL_I2C_Master_Transmit(&hi2c1, I2C_ADDRESS_LCD, (uint8_t *)data_t, 4, 100);
}

void lcd_send_data(char data)
{
    char data_u, data_l;
    uint8_t data_t[4];
    data_u = (data & 0xf0);
    data_l = ((data << 4) & 0xf0);
    data_t[0] = data_u | 0x0D;  // en=1, rs=1
    data_t[1] = data_u | 0x09;  // en=0, rs=1
    data_t[2] = data_l | 0x0D;  // en=1, rs=1
    data_t[3] = data_l | 0x09;  // en=0, rs=1
    HAL_I2C_Master_Transmit(&hi2c1, I2C_ADDRESS_LCD, (uint8_t *)data_t, 4, 100);
}

void lcd_send_string(char *str)
{
    while (*str) lcd_send_data(*str++);
}


void uart_init(void)
{

	 GPIO_InitTypeDef GPIO_InitStruct = {0};

    //Enable UART pins clock access
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//Enable UART module clock access
    __HAL_RCC_USART1_CLK_ENABLE();


	//Configure pins to act as alternate func pins(UART)

     GPIO_InitStruct.Pin  = GPIO_PIN_9|GPIO_PIN_10;
     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
     GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
     GPIO_InitStruct.Pull =  GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

     HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);

     //Configure UART module
     huart1.Instance = USART1;
     huart1.Init.BaudRate = 115200;
     huart1.Init.WordLength = UART_WORDLENGTH_8B;
     huart1.Init.StopBits = UART_STOPBITS_1;
     huart1.Init.Parity = UART_PARITY_NONE;
     huart1.Init.Mode = UART_MODE_TX_RX;
     huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
     huart1.Init.OverSampling = UART_OVERSAMPLING_16;

     HAL_UART_Init(&huart1);

     HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
     HAL_NVIC_EnableIRQ(USART1_IRQn);


}

static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
