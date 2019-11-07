################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USB_HOST/Target/subdir.mk
-include USB_HOST/App/subdir.mk
-include Middlewares/ST/STM32_USB_Host_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Lesson-2-Romanchuk-Vitaliy-HeartBeat.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Lesson-2-Romanchuk-Vitaliy-HeartBeat.list \


# All Target
all: Lesson-2-Romanchuk-Vitaliy-HeartBeat.elf secondary-outputs

# Tool invocations
Lesson-2-Romanchuk-Vitaliy-HeartBeat.elf: $(OBJS) $(USER_OBJS) C:\ST\STM32CubeIDE_1.1.0\STM32CubeIDE\projects\Lesson-2-Romanchuk-Vitaliy-HeartBeat\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "Lesson-2-Romanchuk-Vitaliy-HeartBeat.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\ST\STM32CubeIDE_1.1.0\STM32CubeIDE\projects\Lesson-2-Romanchuk-Vitaliy-HeartBeat\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Lesson-2-Romanchuk-Vitaliy-HeartBeat.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Lesson-2-Romanchuk-Vitaliy-HeartBeat.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Lesson-2-Romanchuk-Vitaliy-HeartBeat.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
