################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-Party/CherrySH/samples/hpm/freertos_usb/src/main.c \
../Third-Party/CherrySH/samples/hpm/freertos_usb/src/shell.c 

OBJS += \
./Third-Party/CherrySH/samples/hpm/freertos_usb/src/main.o \
./Third-Party/CherrySH/samples/hpm/freertos_usb/src/shell.o 

C_DEPS += \
./Third-Party/CherrySH/samples/hpm/freertos_usb/src/main.d \
./Third-Party/CherrySH/samples/hpm/freertos_usb/src/shell.d 


# Each subdirectory must supply rules for building sources it contributes
Third-Party/CherrySH/samples/hpm/freertos_usb/src/%.o Third-Party/CherrySH/samples/hpm/freertos_usb/src/%.su Third-Party/CherrySH/samples/hpm/freertos_usb/src/%.cyclo: ../Third-Party/CherrySH/samples/hpm/freertos_usb/src/%.c Third-Party/CherrySH/samples/hpm/freertos_usb/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I"E:/2.Git/github/stm32h7r7_study/2.software/app/Appli/Third-Party/CherryRB" -I"E:/2.Git/github/stm32h7r7_study/2.software/app/Appli/Third-Party/CherrySH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third-2d-Party-2f-CherrySH-2f-samples-2f-hpm-2f-freertos_usb-2f-src

clean-Third-2d-Party-2f-CherrySH-2f-samples-2f-hpm-2f-freertos_usb-2f-src:
	-$(RM) ./Third-Party/CherrySH/samples/hpm/freertos_usb/src/main.cyclo ./Third-Party/CherrySH/samples/hpm/freertos_usb/src/main.d ./Third-Party/CherrySH/samples/hpm/freertos_usb/src/main.o ./Third-Party/CherrySH/samples/hpm/freertos_usb/src/main.su ./Third-Party/CherrySH/samples/hpm/freertos_usb/src/shell.cyclo ./Third-Party/CherrySH/samples/hpm/freertos_usb/src/shell.d ./Third-Party/CherrySH/samples/hpm/freertos_usb/src/shell.o ./Third-Party/CherrySH/samples/hpm/freertos_usb/src/shell.su

.PHONY: clean-Third-2d-Party-2f-CherrySH-2f-samples-2f-hpm-2f-freertos_usb-2f-src

