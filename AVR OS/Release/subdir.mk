################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ejemplo.c \
../hd44780.c \
../interprete.c \
../lcd.c \
../leds.c \
../main.c \
../motor.c \
../tiempo.c \
../uart.c 

OBJS += \
./ejemplo.o \
./hd44780.o \
./interprete.o \
./lcd.o \
./leds.o \
./main.o \
./motor.o \
./tiempo.o \
./uart.o 

C_DEPS += \
./ejemplo.d \
./hd44780.d \
./interprete.d \
./lcd.d \
./leds.d \
./main.d \
./motor.d \
./tiempo.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=11059200UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


