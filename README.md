01_GPIO  :-

1. Write a c program to turn on led when we press the switch and turn off
the led when we released the switch
Take Input pin PC9 and Output pin PA8

2. Write a c program to turn on Led when we press the switch and
turn off Led if again we press the switch
Take Input pin PC9 and Output pin PA8

3. write a program to turn on 3 led using 3 switch
             conditions :
                 if we press 1st switch 1st led turn on then off.
                 if we press 2nd switch 2nd led turn on then off.
                 if we press 3rd switch 3rd led turn on then off.
                 Take PA7, PA8 and PA9 as output pin.
                 PB8, PB9 and PC9 as input pin.

4. write a program to turn on 3 led using 3 switch.
              conditons :
                     if we press the 1st switch 1st led turn on
                     if we press the 2nd switch 1st and 2nd led turn on
                     if we press the 3rd switch 1st,2nd and 3rd led turn on
                    Take PA7, PA8 and PA9 as output pin.
                    PB8, PB9 and PC9 as input pin.

5. Two switch and one led condition :
                   if we press the 1st switch led will turn on.
                   if we press the 2nd switch led will turn off.
                   Take PA7 as output pin
                   PB8 and PB9 as input pin

6. write a program using 3 led and 1 switch conidtion :
                   if we press the switch 1st time 1st led will turn on.
                   if we press the switch 2nd time 2nd led will turn on.
                   if we press the switch 3rd time 3rd led will turn on.
                   after releasing switch leds will be in off state.
                   also show the num of times switch pressed.
                   Take PA7, PA8 and PA9 as output pin.
                   PB8 as input pin.

7. write a program using 3 led and 1 switch
           conidtion :
                     if we press the switch 1st time 1st led will turn on.
                     if we press the switch 2nd time 2nd led will turn on.
                     if we press the switch 3rd time 3rd led will turn on.
                     after releasing switch led state will not change.
                     also show the num of times switch pressed.
                     Take PA7, PA8 and PA9 as output pin.
                      PB8 as input pin.
8. Write a Program using 1 led and 1 switch
                 conditions:
                        if we press the switch 1st time led will toggle 1 time
                        if we press the switch 2nd time led will toggle 2 times.
                        if we press the switch 3rd time led will toggle 3 times.
                        and this should be in a loop.
                        also print the number of times switch pressed.
                        Take onboard led and switch.

9. Write a Program using 2 leds and 1 switch
                  conditions:
                         if we press the switch 1st time led1 will toggle 1 time and led2 toggle 3 times.
                         if we press the switch 2nd time led1 will toggle 2 time and led2 toggle 6 times.
                         if we press the switch 3rd time led1 will toggle 3 time and led2 toggle 9 times.
                         and this should be in a loop.
                         also print the number of times switch pressed.
                         Take onboard switch , led (PA5) and PA7.

10. Write a Program using 1 led and 1 switch
                 conditions:
                          if we press the switch 1st time led will turn on and
                          print LED ON in SWV ITM Data Console.
                          if we press the switch 2nd time led will turn off and
                          print LED OFF in SWV ITM Data Console
                          and this should be in a loop.
                          after releasing switch led state will not change.
                          also print the number of times switch pressed.
                          Take onboard led and switch.

02_GPIO_Interupt :-
1. Write a c program to turn on led when we press the switch and turn off
the led when we released the switch
Take Input pin PC9 and Output pin PA8

2. Write a c program to turn on Led when we press the switch and
turn off Led if again we press the switch
Take Input pin PC9 and Output pin PA8

3. write a program to turn on 3 led using 3 switch
             conditions :
                 if we press 1st switch 1st led turn on then off.
                 if we press 2nd switch 2nd led turn on then off.
                 if we press 3rd switch 3rd led turn on then off.
                 Take PA7, PA8 and PA9 as output pin.
                 PB8, PB9 and PC9 as input pin.

4. write a program to turn on 3 led using 3 switch.
              conditons :
                     if we press the 1st switch 1st led turn on
                     if we press the 2nd switch 1st and 2nd led turn on
                     if we press the 3rd switch 1st,2nd and 3rd led turn on
                    Take PA7, PA8 and PA9 as output pin.
                    PB8, PB9 and PC9 as input pin.

5. Two switch and one led condition :
                   if we press the 1st switch led will turn on.
                   if we press the 2nd switch led will turn off.
                   Take PA7 as output pin
                   PB8 and PB9 as input pin

6. write a program using 3 led and 1 switch conidtion :
                   if we press the switch 1st time 1st led will turn on.
                   if we press the switch 2nd time 2nd led will turn on.
                   if we press the switch 3rd time 3rd led will turn on.
                   after releasing switch leds will be in off state.
                   also show the num of times switch pressed.
                   Take PA7, PA8 and PA9 as output pin.
                   PB8 as input pin.

   With Interrupt

03_7Seg_Keyboard :-
1. Display 0 – 9 on 7 segment

2. Write a program in keypad matrix to see in which row key is pressed and print the corresponding row

3. Write a program to interface keypad with STM32 and if we press any key it should print “Key pressed”.

4. Write a program in keypad matrix to print the keypad value corresponding to key pressed in keypad matrix

5. Write a program to display the number pressed on the keypad on 7 segment

6. Write a program to toggle the LED number of times displayed on 7 segment

04_LCD_UART :-
1. Write a code to display string on lcd in 8 bit mode

2. Write a code to display string on lcd in 4 bit mode

3. Write a code to set the cursor and display data on both the lines of LCD

4. Write a code to scroll the data on the LCD

5. Write a code to display the special character ‘alpha’ , ‘beta’ ,’pie’ and ‘ohm symbol’ on LCD

6.  Write a code to transfer and receive data

7. Write a code to control the LED PA5 using UART when we press cha ‘N’ or ‘n’ then led will turn on and if we press char ‘F’ or ‘f’ then led will turn off.

05_ADC_PWM
1. Write a function that will create delay in millisecond using systick delay

2. Write a code to interface soil sensor and turn off led PA5 when water is present at appropriate level and turn on PA5 when water is not present.

3. Write a code to change the intensity of light it decreases from 100 % to 25 % after one second

06_I2C_RTC
1. Write a code for STM32 to Display TIME and DATE on 16x2 LCD use I2C LCD Module  and internel  RTC  Module.

2. Write a code for STM32 to Display TIME in 24 Hour Format and DATE on 16x2 LCD  Module  and external RTC DS1307 Module.

3. Write a code for STM32 to Display TIME in 12 Hour Format and DATE on 16x2 LCD  Module  and external RTC DS1307 Module.

07_Free_RTOs
1.  Two switch and one led condition : if we press the 1st switch led will turn on. if we press the 2nd switch led will turn off. Take PA7 as output pin PB8 and PB9 as input pin

2.  write a program using 3 led and 1 switch conidtion : if we press the switch 1st time 1st led will turn on. if we press the switch 2nd time 2nd led will turn on. if we press the switch 3rd time 3rd led will turn on. after releasing switch leds will be in off state. also show the num of times switch pressed. Take PA7, PA8 and PA9 as output pin. PB8 as input pin.

3.  Write a code to transfer and receive data

4.  Display 0 – 9 on 7 segment

5.  Write a code for STM32 to Display TIME and DATE ,use internel RTC Module.

08_MODBUS_RTU_2chRelay
1.  Modbus RTU 2CH relay module RS485/TTL UART 2CH IN 2CH OUT [When the Relay channel 1 open, The LED will glow and when Relay channel 1 close, The LED will off].
