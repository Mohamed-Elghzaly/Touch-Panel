################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/SysTick/SysTick.c 

OBJS += \
./Src/MCAL/SysTick/SysTick.o 

C_DEPS += \
./Src/MCAL/SysTick/SysTick.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/SysTick/%.o Src/MCAL/SysTick/%.su Src/MCAL/SysTick/%.cyclo: ../Src/MCAL/SysTick/%.c Src/MCAL/SysTick/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-SysTick

clean-Src-2f-MCAL-2f-SysTick:
	-$(RM) ./Src/MCAL/SysTick/SysTick.cyclo ./Src/MCAL/SysTick/SysTick.d ./Src/MCAL/SysTick/SysTick.o ./Src/MCAL/SysTick/SysTick.su

.PHONY: clean-Src-2f-MCAL-2f-SysTick

