################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-Party/CherrySH/cherryrl/chry_readline.c 

OBJS += \
./Third-Party/CherrySH/cherryrl/chry_readline.o 

C_DEPS += \
./Third-Party/CherrySH/cherryrl/chry_readline.d 


# Each subdirectory must supply rules for building sources it contributes
Third-Party/CherrySH/cherryrl/%.o Third-Party/CherrySH/cherryrl/%.su Third-Party/CherrySH/cherryrl/%.cyclo: ../Third-Party/CherrySH/cherryrl/%.c Third-Party/CherrySH/cherryrl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I"E:/2.Git/github/stm32h7r7_study/2.software/app/Appli/Third-Party/CherryRB" -I"E:/2.Git/github/stm32h7r7_study/2.software/app/Appli/Third-Party/CherrySH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third-2d-Party-2f-CherrySH-2f-cherryrl

clean-Third-2d-Party-2f-CherrySH-2f-cherryrl:
	-$(RM) ./Third-Party/CherrySH/cherryrl/chry_readline.cyclo ./Third-Party/CherrySH/cherryrl/chry_readline.d ./Third-Party/CherrySH/cherryrl/chry_readline.o ./Third-Party/CherrySH/cherryrl/chry_readline.su

.PHONY: clean-Third-2d-Party-2f-CherrySH-2f-cherryrl

