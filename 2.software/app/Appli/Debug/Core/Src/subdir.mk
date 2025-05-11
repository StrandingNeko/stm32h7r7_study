################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app_shell.c \
../Core/Src/app_threadx.c \
../Core/Src/flash.c \
../Core/Src/gpdma.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/stm32h7rsxx_hal_msp.c \
../Core/Src/stm32h7rsxx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7rsxx.c \
../Core/Src/usart.c 

S_UPPER_SRCS += \
../Core/Src/tx_initialize_low_level.S 

OBJS += \
./Core/Src/app_shell.o \
./Core/Src/app_threadx.o \
./Core/Src/flash.o \
./Core/Src/gpdma.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/stm32h7rsxx_hal_msp.o \
./Core/Src/stm32h7rsxx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7rsxx.o \
./Core/Src/tx_initialize_low_level.o \
./Core/Src/usart.o 

S_UPPER_DEPS += \
./Core/Src/tx_initialize_low_level.d 

C_DEPS += \
./Core/Src/app_shell.d \
./Core/Src/app_threadx.d \
./Core/Src/flash.d \
./Core/Src/gpdma.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/stm32h7rsxx_hal_msp.d \
./Core/Src/stm32h7rsxx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7rsxx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I"E:/2.Git/github/stm32h7r7_study/2.software/app/Appli/Third-Party/CherryRB" -I"E:/2.Git/github/stm32h7r7_study/2.software/app/Appli/Third-Party/CherrySH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o: ../Core/Src/%.S Core/Src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I"E:/2.Git/github/stm32h7r7_study/2.software/app/Appli/Third-Party/CherryRB" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/app_shell.cyclo ./Core/Src/app_shell.d ./Core/Src/app_shell.o ./Core/Src/app_shell.su ./Core/Src/app_threadx.cyclo ./Core/Src/app_threadx.d ./Core/Src/app_threadx.o ./Core/Src/app_threadx.su ./Core/Src/flash.cyclo ./Core/Src/flash.d ./Core/Src/flash.o ./Core/Src/flash.su ./Core/Src/gpdma.cyclo ./Core/Src/gpdma.d ./Core/Src/gpdma.o ./Core/Src/gpdma.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32h7rsxx_hal_msp.cyclo ./Core/Src/stm32h7rsxx_hal_msp.d ./Core/Src/stm32h7rsxx_hal_msp.o ./Core/Src/stm32h7rsxx_hal_msp.su ./Core/Src/stm32h7rsxx_it.cyclo ./Core/Src/stm32h7rsxx_it.d ./Core/Src/stm32h7rsxx_it.o ./Core/Src/stm32h7rsxx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h7rsxx.cyclo ./Core/Src/system_stm32h7rsxx.d ./Core/Src/system_stm32h7rsxx.o ./Core/Src/system_stm32h7rsxx.su ./Core/Src/tx_initialize_low_level.d ./Core/Src/tx_initialize_low_level.o ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

