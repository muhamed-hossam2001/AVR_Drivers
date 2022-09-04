################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/PORT_Driver/subdir.mk
-include MCAL/DIO_Driver/subdir.mk
-include HAL/LCD_Module/subdir.mk
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
Freeartos_Driver.lss \

FLASH_IMAGE += \
Freeartos_Driver.hex \

EEPROM_IMAGE += \
Freeartos_Driver.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Freeartos_Driver.elf secondary-outputs

# Tool invocations
Freeartos_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Freeartos_Driver.map -mmcu=atmega32 -o "Freeartos_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Freeartos_Driver.lss: Freeartos_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Freeartos_Driver.elf  >"Freeartos_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

Freeartos_Driver.hex: Freeartos_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Freeartos_Driver.elf  "Freeartos_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

Freeartos_Driver.eep: Freeartos_Driver.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Freeartos_Driver.elf  "Freeartos_Driver.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Freeartos_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Freeartos_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Freeartos_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
