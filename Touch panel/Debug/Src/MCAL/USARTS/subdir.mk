################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/USARTS/usart.c 

OBJS += \
./Src/MCAL/USARTS/usart.o 

C_DEPS += \
./Src/MCAL/USARTS/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/USARTS/%.o Src/MCAL/USARTS/%.su Src/MCAL/USARTS/%.cyclo: ../Src/MCAL/USARTS/%.c Src/MCAL/USARTS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-USARTS

clean-Src-2f-MCAL-2f-USARTS:
	-$(RM) ./Src/MCAL/USARTS/usart.cyclo ./Src/MCAL/USARTS/usart.d ./Src/MCAL/USARTS/usart.o ./Src/MCAL/USARTS/usart.su

.PHONY: clean-Src-2f-MCAL-2f-USARTS

