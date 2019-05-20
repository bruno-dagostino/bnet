################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/utils/die_with_error.c 

OBJS += \
./src/utils/die_with_error.o 

C_DEPS += \
./src/utils/die_with_error.d 


# Each subdirectory must supply rules for building sources it contributes
src/utils/%.o: ../src/utils/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


