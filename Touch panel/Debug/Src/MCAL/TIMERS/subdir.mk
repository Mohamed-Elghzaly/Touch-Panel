################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/TIMERS/timer.c 

OBJS += \
./Src/MCAL/TIMERS/timer.o 

C_DEPS += \
./Src/MCAL/TIMERS/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/TIMERS/%.o Src/MCAL/TIMERS/%.su Src/MCAL/TIMERS/%.cyclo: ../Src/MCAL/TIMERS/%.c Src/MCAL/TIMERS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-TIMERS

clean-Src-2f-MCAL-2f-TIMERS:
	-$(RM) ./Src/MCAL/TIMERS/timer.cyclo ./Src/MCAL/TIMERS/timer.d ./Src/MCAL/TIMERS/timer.o ./Src/MCAL/TIMERS/timer.su

.PHONY: clean-Src-2f-MCAL-2f-TIMERS

