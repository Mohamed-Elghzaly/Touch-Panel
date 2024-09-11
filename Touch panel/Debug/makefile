################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/MCAL/USARTS/subdir.mk
-include Src/MCAL/TIMERS/subdir.mk
-include Src/MCAL/SysTick/subdir.mk
-include Src/MCAL/SCB/subdir.mk
-include Src/MCAL/RCC/subdir.mk
-include Src/MCAL/NVIC/subdir.mk
-include Src/MCAL/GPIO/subdir.mk
-include Src/MCAL/FLASH/subdir.mk
-include Src/MCAL/DMA/subdir.mk
-include Src/MCAL/Backup/subdir.mk
-include Src/HAL/WS2812/subdir.mk
-include Src/HAL/ShiftRegister_74HC595/subdir.mk
-include Src/HAL/RGB_Led/subdir.mk
-include Src/HAL/LED/subdir.mk
-include Src/HAL/Emulated\ EEPROM/subdir.mk
-include Src/HAL/Button/subdir.mk
-include Src/APP/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := test1
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
test1.elf \

MAP_FILES += \
test1.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
test1.list \

OBJCOPY_HEX += \
test1.hex \


# All Target
all: main-build

# Main-build Target
main-build: test1.elf secondary-outputs

# Tool invocations
test1.elf test1.map: $(OBJS) $(USER_OBJS) D:\Embedded\Alkhooly\test1\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "test1.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Embedded\Alkhooly\test1\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="test1.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

test1.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "test1.list"
	@echo 'Finished building: $@'
	@echo ' '

test1.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "test1.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout test1.elf test1.hex test1.list test1.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
