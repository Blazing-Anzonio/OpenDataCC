################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Nationality.cpp \
../src/NationalityInfo.cpp \
../src/birthplace.cpp \
../src/birthplaces.cpp \
../src/birthyear.cpp \
../src/birthyears.cpp \
../src/education.cpp \
../src/educationInfo.cpp \
../src/managerN.cpp \
../src/managerV.cpp \
../src/neighborhood.cpp \
../src/opendata.cpp \
../src/timer.cpp \
../src/ui.cpp \
../src/via.cpp 

OBJS += \
./src/Nationality.o \
./src/NationalityInfo.o \
./src/birthplace.o \
./src/birthplaces.o \
./src/birthyear.o \
./src/birthyears.o \
./src/education.o \
./src/educationInfo.o \
./src/managerN.o \
./src/managerV.o \
./src/neighborhood.o \
./src/opendata.o \
./src/timer.o \
./src/ui.o \
./src/via.o 

CPP_DEPS += \
./src/Nationality.d \
./src/NationalityInfo.d \
./src/birthplace.d \
./src/birthplaces.d \
./src/birthyear.d \
./src/birthyears.d \
./src/education.d \
./src/educationInfo.d \
./src/managerN.d \
./src/managerV.d \
./src/neighborhood.d \
./src/opendata.d \
./src/timer.d \
./src/ui.d \
./src/via.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


