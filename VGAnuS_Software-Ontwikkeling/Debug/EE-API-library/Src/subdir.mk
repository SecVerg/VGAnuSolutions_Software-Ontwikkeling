################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EE-API-library/Src/API_draw.c \
../EE-API-library/Src/API_io.c 

OBJS += \
./EE-API-library/Src/API_draw.o \
./EE-API-library/Src/API_io.o 

C_DEPS += \
./EE-API-library/Src/API_draw.d \
./EE-API-library/Src/API_io.d 


# Each subdirectory must supply rules for building sources it contributes
EE-API-library/Src/API_draw.o: ../EE-API-library/Src/API_draw.c EE-API-library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/secve/Documents/GitHub/VGAnuSolutions_Software-Ontwikkeling/VGAnuS_Software-Ontwikkeling/EE-API-library" -I"C:/Users/secve/Documents/GitHub/VGAnuSolutions_Software-Ontwikkeling/VGAnuS_Software-Ontwikkeling/EE-API-library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"EE-API-library/Src/API_draw.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
EE-API-library/Src/API_io.o: ../EE-API-library/Src/API_io.c EE-API-library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/secve/Documents/GitHub/VGAnuSolutions_Software-Ontwikkeling/VGAnuS_Software-Ontwikkeling/EE-API-library" -I"C:/Users/secve/Documents/GitHub/VGAnuSolutions_Software-Ontwikkeling/VGAnuS_Software-Ontwikkeling/EE-API-library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"EE-API-library/Src/API_io.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

