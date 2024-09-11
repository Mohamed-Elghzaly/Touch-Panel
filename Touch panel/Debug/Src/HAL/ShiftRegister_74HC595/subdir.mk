################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/ShiftRegister_74HC595/ShiftRegister.c 

OBJS += \
./Src/HAL/ShiftRegister_74HC595/ShiftRegister.o 

C_DEPS += \
./Src/HAL/ShiftRegister_74HC595/ShiftRegister.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/ShiftRegister_74HC595/%.o Src/HAL/ShiftRegister_74HC595/%.su Src/HAL/ShiftRegister_74HC595/%.cyclo: ../Src/HAL/ShiftRegister_74HC595/%.c Src/HAL/ShiftRegister_74HC595/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-ShiftRegister_74HC595

clean-Src-2f-HAL-2f-ShiftRegister_74HC595:
	-$(RM) ./Src/HAL/ShiftRegister_74HC595/ShiftRegister.cyclo ./Src/HAL/ShiftRegister_74HC595/ShiftRegister.d ./Src/HAL/ShiftRegister_74HC595/ShiftRegister.o ./Src/HAL/ShiftRegister_74HC595/ShiftRegister.su

.PHONY: clean-Src-2f-HAL-2f-ShiftRegister_74HC595

