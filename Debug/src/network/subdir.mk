################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/network/dump.c \
../src/network/send_recv.c 

OBJS += \
./src/network/dump.o \
./src/network/send_recv.o 

C_DEPS += \
./src/network/dump.d \
./src/network/send_recv.d 


# Each subdirectory must supply rules for building sources it contributes
src/network/%.o: ../src/network/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


