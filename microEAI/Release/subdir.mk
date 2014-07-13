################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../config.cpp \
../files.cpp \
../main.cpp 

OBJS += \
./config.o \
./files.o \
./main.o 

CPP_DEPS += \
./config.d \
./files.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include -I/usr/include/c++/4.7 -I/usr/include/c++/4.7/i486-linux-gnu -I/usr/include/c++/4.7/backward -I/usr/include/i386-linux-gnu -I/usr/lib/gcc/i486-linux-gnu/4.7/include/ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


