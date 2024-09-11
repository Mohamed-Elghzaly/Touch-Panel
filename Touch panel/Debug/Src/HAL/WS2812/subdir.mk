################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/WS2812/ws2812.c 

OBJS += \
./Src/HAL/WS2812/ws2812.o 

C_DEPS += \
./Src/HAL/WS2812/ws2812.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/WS2812/%.o Src/HAL/WS2812/%.su Src/HAL/WS2812/%.cyclo: ../Src/HAL/WS2812/%.c Src/HAL/WS2812/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-WS2812

clean-Src-2f-HAL-2f-WS2812:
	-$(RM) ./Src/HAL/WS2812/ws2812.cyclo ./Src/HAL/WS2812/ws2812.d ./Src/HAL/WS2812/ws2812.o ./Src/HAL/WS2812/ws2812.su

.PHONY: clean-Src-2f-HAL-2f-WS2812

