################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/Emulated\ EEPROM/em_eeprom.c 

OBJS += \
./Src/HAL/Emulated\ EEPROM/em_eeprom.o 

C_DEPS += \
./Src/HAL/Emulated\ EEPROM/em_eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/Emulated\ EEPROM/em_eeprom.o: ../Src/HAL/Emulated\ EEPROM/em_eeprom.c Src/HAL/Emulated\ EEPROM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Src/HAL/Emulated EEPROM/em_eeprom.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-Emulated-20-EEPROM

clean-Src-2f-HAL-2f-Emulated-20-EEPROM:
	-$(RM) ./Src/HAL/Emulated\ EEPROM/em_eeprom.cyclo ./Src/HAL/Emulated\ EEPROM/em_eeprom.d ./Src/HAL/Emulated\ EEPROM/em_eeprom.o ./Src/HAL/Emulated\ EEPROM/em_eeprom.su

.PHONY: clean-Src-2f-HAL-2f-Emulated-20-EEPROM

