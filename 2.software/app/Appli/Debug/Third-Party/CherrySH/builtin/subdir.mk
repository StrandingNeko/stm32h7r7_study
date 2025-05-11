################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-Party/CherrySH/builtin/help.c \
../Third-Party/CherrySH/builtin/login.c \
../Third-Party/CherrySH/builtin/shsize.c 

OBJS += \
./Third-Party/CherrySH/builtin/help.o \
./Third-Party/CherrySH/builtin/login.o \
./Third-Party/CherrySH/builtin/shsize.o 

C_DEPS += \
./Third-Party/CherrySH/builtin/help.d \
./Third-Party/CherrySH/builtin/login.d \
./Third-Party/CherrySH/builtin/shsize.d 


# Each subdirectory must supply rules for building sources it contributes
Third-Party/CherrySH/builtin/%.o Third-Party/CherrySH/builtin/%.su Third-Party/CherrySH/builtin/%.cyclo: ../Third-Party/CherrySH/builtin/%.c Third-Party/CherrySH/builtin/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I"E:/2.Git/github/stm32h7r7_study/2.software/app/Appli/Third-Party/CherryRB" -I"E:/2.Git/github/stm32h7r7_study/2.software/app/Appli/Third-Party/CherrySH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third-2d-Party-2f-CherrySH-2f-builtin

clean-Third-2d-Party-2f-CherrySH-2f-builtin:
	-$(RM) ./Third-Party/CherrySH/builtin/help.cyclo ./Third-Party/CherrySH/builtin/help.d ./Third-Party/CherrySH/builtin/help.o ./Third-Party/CherrySH/builtin/help.su ./Third-Party/CherrySH/builtin/login.cyclo ./Third-Party/CherrySH/builtin/login.d ./Third-Party/CherrySH/builtin/login.o ./Third-Party/CherrySH/builtin/login.su ./Third-Party/CherrySH/builtin/shsize.cyclo ./Third-Party/CherrySH/builtin/shsize.d ./Third-Party/CherrySH/builtin/shsize.o ./Third-Party/CherrySH/builtin/shsize.su

.PHONY: clean-Third-2d-Party-2f-CherrySH-2f-builtin

