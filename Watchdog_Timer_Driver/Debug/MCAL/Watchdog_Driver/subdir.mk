################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Watchdog_Driver/Watchdog_Timer_Program.c 

OBJS += \
./MCAL/Watchdog_Driver/Watchdog_Timer_Program.o 

C_DEPS += \
./MCAL/Watchdog_Driver/Watchdog_Timer_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Watchdog_Driver/%.o: ../MCAL/Watchdog_Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


