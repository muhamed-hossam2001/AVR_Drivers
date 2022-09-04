################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART_Driver/subdir.mk
-include MCAL/Timer_Driver/subdir.mk
-include MCAL/PORT_Driver/subdir.mk
-include MCAL/GIE_Driver/subdir.mk
-include MCAL/External_Interrupt_Driver/subdir.mk
-include MCAL/DIO_Driver/subdir.mk
-include MCAL/ADC_Driver/subdir.mk
-include HAL/ServoMotor_Handler/subdir.mk
-include HAL/LM35_Module/subdir.mk
-include HAL/LED_Module/subdir.mk
-include HAL/LCD_Module/subdir.mk
-include HAL/Keypad_Module/subdir.mk
-include HAL/DC_MOTOR/subdir.mk
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
UART_Driver.lss \

FLASH_IMAGE += \
UART_Driver.hex \

EEPROM_IMAGE += \
UART_Driver.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: UART_Driver.elf secondary-outputs

# Tool invocations
UART_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,UART_Driver.map -mmcu=atmega32 -o "UART_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

UART_Driver.lss: UART_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S UART_Driver.elf  >"UART_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

UART_Driver.hex: UART_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex UART_Driver.elf  "UART_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

UART_Driver.eep: UART_Driver.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex UART_Driver.elf  "UART_Driver.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: UART_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 UART_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) UART_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
