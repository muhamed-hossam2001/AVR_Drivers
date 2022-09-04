################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Watchdog_Driver/subdir.mk
-include MCAL/PORT_Driver/subdir.mk
-include MCAL/DIO_Driver/subdir.mk
-include HAL/LED_Module/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Watchdog_Timer_Driver.lss \

FLASH_IMAGE += \
Watchdog_Timer_Driver.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Watchdog_Timer_Driver.elf secondary-outputs

# Tool invocations
Watchdog_Timer_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Watchdog_Timer_Driver.map -mmcu=atmega32 -o "Watchdog_Timer_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Watchdog_Timer_Driver.lss: Watchdog_Timer_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Watchdog_Timer_Driver.elf  >"Watchdog_Timer_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

Watchdog_Timer_Driver.hex: Watchdog_Timer_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Watchdog_Timer_Driver.elf  "Watchdog_Timer_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Watchdog_Timer_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Watchdog_Timer_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Watchdog_Timer_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
