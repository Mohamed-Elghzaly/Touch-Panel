################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/FLASH/flash.c 

OBJS += \
./Src/MCAL/FLASH/flash.o 

C_DEPS += \
./Src/MCAL/FLASH/flash.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/FLASH/%.o Src/MCAL/FLASH/%.su Src/MCAL/FLASH/%.cyclo: ../Src/MCAL/FLASH/%.c Src/MCAL/FLASH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-FLASH

clean-Src-2f-MCAL-2f-FLASH:
	-$(RM) ./Src/MCAL/FLASH/flash.cyclo ./Src/MCAL/FLASH/flash.d ./Src/MCAL/FLASH/flash.o ./Src/MCAL/FLASH/flash.su

.PHONY: clean-Src-2f-MCAL-2f-FLASH

