################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/RGB_Led/RGB_Led.c 

OBJS += \
./Src/HAL/RGB_Led/RGB_Led.o 

C_DEPS += \
./Src/HAL/RGB_Led/RGB_Led.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/RGB_Led/%.o Src/HAL/RGB_Led/%.su Src/HAL/RGB_Led/%.cyclo: ../Src/HAL/RGB_Led/%.c Src/HAL/RGB_Led/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-RGB_Led

clean-Src-2f-HAL-2f-RGB_Led:
	-$(RM) ./Src/HAL/RGB_Led/RGB_Led.cyclo ./Src/HAL/RGB_Led/RGB_Led.d ./Src/HAL/RGB_Led/RGB_Led.o ./Src/HAL/RGB_Led/RGB_Led.su

.PHONY: clean-Src-2f-HAL-2f-RGB_Led

