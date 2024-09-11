################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/Backup/backup.c 

OBJS += \
./Src/MCAL/Backup/backup.o 

C_DEPS += \
./Src/MCAL/Backup/backup.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/Backup/%.o Src/MCAL/Backup/%.su Src/MCAL/Backup/%.cyclo: ../Src/MCAL/Backup/%.c Src/MCAL/Backup/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-Backup

clean-Src-2f-MCAL-2f-Backup:
	-$(RM) ./Src/MCAL/Backup/backup.cyclo ./Src/MCAL/Backup/backup.d ./Src/MCAL/Backup/backup.o ./Src/MCAL/Backup/backup.su

.PHONY: clean-Src-2f-MCAL-2f-Backup

