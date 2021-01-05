################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/STM32FXX_GPIO_Driver.c 

OBJS += \
./Drivers/src/STM32FXX_GPIO_Driver.o 

C_DEPS += \
./Drivers/src/STM32FXX_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/STM32FXX_GPIO_Driver.o: ../Drivers/src/STM32FXX_GPIO_Driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"C:/Users/99003157/STM32CubeIDE/workspace_1.5.0/driver/Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/src/STM32FXX_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

