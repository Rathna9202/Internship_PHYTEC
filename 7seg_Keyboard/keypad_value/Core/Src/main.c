/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stdio.h" // Include for printf function, if using SWV

/* Private function prototypes -----------------------------------------------*/
static void MX_GPIO_Init(void);
void scan_keypad(void);
char get_key_value(uint8_t row, uint8_t col);

/* Private variables ---------------------------------------------------------*/
uint8_t pressed_row = 0xFF; // 0xFF indicates no key is pressed
uint8_t pressed_col = 0xFF; // 0xFF indicates no key is pressed

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{
    /* MCU Configuration--------------------------------------------------------*/
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    /* Initialize SWV output */
    printf("Keypad Scanner Initialized\n");

    /* Infinite loop */
    while (1)
    {
        scan_keypad();

        if (pressed_row != 0xFF && pressed_col != 0xFF)
        {
            char key_value = get_key_value(pressed_row, pressed_col);
            printf("Key Pressed: %c\n", key_value);
        }
        else
        {
            printf("No key is pressed\n");
        }

        HAL_Delay(500); // Delay for debouncing and readability
    }
}

int _write(int file, char *ptr, int len)
{
    (void)file;
    int DataIdx;

    for (DataIdx = 0; DataIdx < len; DataIdx++)
    {
        ITM_SendChar(*ptr++);
    }
    return len;
}

void scan_keypad(void)
{
    // Initialize row pins as output
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    // Set all rows high initially
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_SET);

    // Initialize column pins as input with pull-up resistors enabled
    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    pressed_row = 0xFF; // No key pressed
    pressed_col = 0xFF; // No key pressed

    // Scan each row
    for (int row = 0; row < 4; row++)
    {
        // Set the current row pin to low
        HAL_GPIO_WritePin(GPIOC, (GPIO_PIN_0 << row), GPIO_PIN_RESET);

        // Check each column
        for (int col = 0; col < 3; col++)
        {
            if (HAL_GPIO_ReadPin(GPIOA, (GPIO_PIN_0 << col)) == GPIO_PIN_RESET)
            {
                // Key is pressed in this row and column
                pressed_row = row;
                pressed_col = col;
             //   printf("Key at Row %d and Column %d is pressed\n", row, col);
                return; // Exit as soon as a pressed key is found
            }
        }

        // Restore the row pin to high
        HAL_GPIO_WritePin(GPIOC, (GPIO_PIN_0 << row), GPIO_PIN_SET);
    }

    // If no key is pressed
    pressed_row = 0xFF; // No key pressed
    pressed_col = 0xFF; // No key pressed
    printf("No key is pressed\n");
}

char get_key_value(uint8_t row, uint8_t col)
{
    // Define key values in a 4x4 matrix
    char keys[4][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}
    };

    // Return the key value based on row and column
    return keys[row][col];
}

void SystemClock_Config(void)
{
    // Configuration code for system clock (automatically generated by STM32CubeMX)
}

static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* Configure GPIO pins : PC0 PC1 PC2 PC3 (Rows) */
    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* Configure GPIO pins : PA0 PA1 PA2 PA3 (Columns) */
    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Set all rows high initially */
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_SET);
}
