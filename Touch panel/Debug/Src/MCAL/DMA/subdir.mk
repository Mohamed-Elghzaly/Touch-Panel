################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/DMA/dma.c 

OBJS += \
./Src/MCAL/DMA/dma.o 

C_DEPS += \
./Src/MCAL/DMA/dma.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/DMA/%.o Src/MCAL/DMA/%.su Src/MCAL/DMA/%.cyclo: ../Src/MCAL/DMA/%.c Src/MCAL/DMA/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-DMA

clean-Src-2f-MCAL-2f-DMA:
	-$(RM) ./Src/MCAL/DMA/dma.cyclo ./Src/MCAL/DMA/dma.d ./Src/MCAL/DMA/dma.o ./Src/MCAL/DMA/dma.su

.PHONY: clean-Src-2f-MCAL-2f-DMA

