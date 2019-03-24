################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS_QUOTED += \
"../src/cpu_a.S" \
"../src/cpu_cache_powerpc_e200z4204n3_a.S" \
"../src/intc_sw_handlers.S" \
"../src/os_cpu_a.S" \

C_SRCS_QUOTED += \
"../src/MPC57xx__Interrupt_Init.c" \
"../src/Vector.c" \
"../src/app_hooks.c" \
"../src/bsp_clk.c" \
"../src/bsp_cpu.c" \
"../src/bsp_int.c" \
"../src/bsp_led.c" \
"../src/bsp_os.c" \
"../src/bsp_smpu.c" \
"../src/cpu_cache_powerpc_e200z4204n3.c" \
"../src/cpu_core.c" \
"../src/flashrchw.c" \
"../src/intc_SW_mode_isr_vectors_MPC5744P.c" \
"../src/lib_ascii.c" \
"../src/lib_math.c" \
"../src/lib_mem.c" \
"../src/lib_str.c" \
"../src/main.c" \
"../src/os_core.c" \
"../src/os_cpu_c.c" \
"../src/os_dbg_r.c" \
"../src/os_flag.c" \
"../src/os_mbox.c" \
"../src/os_mem.c" \
"../src/os_mutex.c" \
"../src/os_q.c" \
"../src/os_sem.c" \
"../src/os_task.c" \
"../src/os_time.c" \
"../src/os_tmr.c" \

S_UPPER_SRCS += \
../src/cpu_a.S \
../src/cpu_cache_powerpc_e200z4204n3_a.S \
../src/intc_sw_handlers.S \
../src/os_cpu_a.S \

C_SRCS += \
../src/MPC57xx__Interrupt_Init.c \
../src/Vector.c \
../src/app_hooks.c \
../src/bsp_clk.c \
../src/bsp_cpu.c \
../src/bsp_int.c \
../src/bsp_led.c \
../src/bsp_os.c \
../src/bsp_smpu.c \
../src/cpu_cache_powerpc_e200z4204n3.c \
../src/cpu_core.c \
../src/flashrchw.c \
../src/intc_SW_mode_isr_vectors_MPC5744P.c \
../src/lib_ascii.c \
../src/lib_math.c \
../src/lib_mem.c \
../src/lib_str.c \
../src/main.c \
../src/os_core.c \
../src/os_cpu_c.c \
../src/os_dbg_r.c \
../src/os_flag.c \
../src/os_mbox.c \
../src/os_mem.c \
../src/os_mutex.c \
../src/os_q.c \
../src/os_sem.c \
../src/os_task.c \
../src/os_time.c \
../src/os_tmr.c \

OBJS_OS_FORMAT += \
./src/MPC57xx__Interrupt_Init.o \
./src/Vector.o \
./src/app_hooks.o \
./src/bsp_clk.o \
./src/bsp_cpu.o \
./src/bsp_int.o \
./src/bsp_led.o \
./src/bsp_os.o \
./src/bsp_smpu.o \
./src/cpu_a.o \
./src/cpu_cache_powerpc_e200z4204n3.o \
./src/cpu_cache_powerpc_e200z4204n3_a.o \
./src/cpu_core.o \
./src/flashrchw.o \
./src/intc_SW_mode_isr_vectors_MPC5744P.o \
./src/intc_sw_handlers.o \
./src/lib_ascii.o \
./src/lib_math.o \
./src/lib_mem.o \
./src/lib_str.o \
./src/main.o \
./src/os_core.o \
./src/os_cpu_a.o \
./src/os_cpu_c.o \
./src/os_dbg_r.o \
./src/os_flag.o \
./src/os_mbox.o \
./src/os_mem.o \
./src/os_mutex.o \
./src/os_q.o \
./src/os_sem.o \
./src/os_task.o \
./src/os_time.o \
./src/os_tmr.o \

C_DEPS_QUOTED += \
"./src/MPC57xx__Interrupt_Init.d" \
"./src/Vector.d" \
"./src/app_hooks.d" \
"./src/bsp_clk.d" \
"./src/bsp_cpu.d" \
"./src/bsp_int.d" \
"./src/bsp_led.d" \
"./src/bsp_os.d" \
"./src/bsp_smpu.d" \
"./src/cpu_cache_powerpc_e200z4204n3.d" \
"./src/cpu_core.d" \
"./src/flashrchw.d" \
"./src/intc_SW_mode_isr_vectors_MPC5744P.d" \
"./src/lib_ascii.d" \
"./src/lib_math.d" \
"./src/lib_mem.d" \
"./src/lib_str.d" \
"./src/main.d" \
"./src/os_core.d" \
"./src/os_cpu_c.d" \
"./src/os_dbg_r.d" \
"./src/os_flag.d" \
"./src/os_mbox.d" \
"./src/os_mem.d" \
"./src/os_mutex.d" \
"./src/os_q.d" \
"./src/os_sem.d" \
"./src/os_task.d" \
"./src/os_time.d" \
"./src/os_tmr.d" \

OBJS += \
./src/MPC57xx__Interrupt_Init.o \
./src/Vector.o \
./src/app_hooks.o \
./src/bsp_clk.o \
./src/bsp_cpu.o \
./src/bsp_int.o \
./src/bsp_led.o \
./src/bsp_os.o \
./src/bsp_smpu.o \
./src/cpu_a.o \
./src/cpu_cache_powerpc_e200z4204n3.o \
./src/cpu_cache_powerpc_e200z4204n3_a.o \
./src/cpu_core.o \
./src/flashrchw.o \
./src/intc_SW_mode_isr_vectors_MPC5744P.o \
./src/intc_sw_handlers.o \
./src/lib_ascii.o \
./src/lib_math.o \
./src/lib_mem.o \
./src/lib_str.o \
./src/main.o \
./src/os_core.o \
./src/os_cpu_a.o \
./src/os_cpu_c.o \
./src/os_dbg_r.o \
./src/os_flag.o \
./src/os_mbox.o \
./src/os_mem.o \
./src/os_mutex.o \
./src/os_q.o \
./src/os_sem.o \
./src/os_task.o \
./src/os_time.o \
./src/os_tmr.o \

OBJS_QUOTED += \
"./src/MPC57xx__Interrupt_Init.o" \
"./src/Vector.o" \
"./src/app_hooks.o" \
"./src/bsp_clk.o" \
"./src/bsp_cpu.o" \
"./src/bsp_int.o" \
"./src/bsp_led.o" \
"./src/bsp_os.o" \
"./src/bsp_smpu.o" \
"./src/cpu_a.o" \
"./src/cpu_cache_powerpc_e200z4204n3.o" \
"./src/cpu_cache_powerpc_e200z4204n3_a.o" \
"./src/cpu_core.o" \
"./src/flashrchw.o" \
"./src/intc_SW_mode_isr_vectors_MPC5744P.o" \
"./src/intc_sw_handlers.o" \
"./src/lib_ascii.o" \
"./src/lib_math.o" \
"./src/lib_mem.o" \
"./src/lib_str.o" \
"./src/main.o" \
"./src/os_core.o" \
"./src/os_cpu_a.o" \
"./src/os_cpu_c.o" \
"./src/os_dbg_r.o" \
"./src/os_flag.o" \
"./src/os_mbox.o" \
"./src/os_mem.o" \
"./src/os_mutex.o" \
"./src/os_q.o" \
"./src/os_sem.o" \
"./src/os_task.o" \
"./src/os_time.o" \
"./src/os_tmr.o" \

C_DEPS += \
./src/MPC57xx__Interrupt_Init.d \
./src/Vector.d \
./src/app_hooks.d \
./src/bsp_clk.d \
./src/bsp_cpu.d \
./src/bsp_int.d \
./src/bsp_led.d \
./src/bsp_os.d \
./src/bsp_smpu.d \
./src/cpu_cache_powerpc_e200z4204n3.d \
./src/cpu_core.d \
./src/flashrchw.d \
./src/intc_SW_mode_isr_vectors_MPC5744P.d \
./src/lib_ascii.d \
./src/lib_math.d \
./src/lib_mem.d \
./src/lib_str.d \
./src/main.d \
./src/os_core.d \
./src/os_cpu_c.d \
./src/os_dbg_r.d \
./src/os_flag.d \
./src/os_mbox.d \
./src/os_mem.d \
./src/os_mutex.d \
./src/os_q.d \
./src/os_sem.d \
./src/os_task.d \
./src/os_time.d \
./src/os_tmr.d \


# Each subdirectory must supply rules for building sources it contributes
src/MPC57xx__Interrupt_Init.o: ../src/MPC57xx__Interrupt_Init.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/MPC57xx__Interrupt_Init.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/MPC57xx__Interrupt_Init.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Vector.o: ../src/Vector.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Vector.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/Vector.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/app_hooks.o: ../src/app_hooks.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/app_hooks.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/app_hooks.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bsp_clk.o: ../src/bsp_clk.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/bsp_clk.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/bsp_clk.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bsp_cpu.o: ../src/bsp_cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/bsp_cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/bsp_cpu.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bsp_int.o: ../src/bsp_int.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/bsp_int.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/bsp_int.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bsp_led.o: ../src/bsp_led.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/bsp_led.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/bsp_led.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bsp_os.o: ../src/bsp_os.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/bsp_os.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/bsp_os.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bsp_smpu.o: ../src/bsp_smpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/bsp_smpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/bsp_smpu.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cpu_a.o: ../src/cpu_a.S
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: Standard S32DS Assembler'
	powerpc-eabivle-gcc "@src/cpu_a.args" -c -o "src/cpu_a.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cpu_cache_powerpc_e200z4204n3.o: ../src/cpu_cache_powerpc_e200z4204n3.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/cpu_cache_powerpc_e200z4204n3.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/cpu_cache_powerpc_e200z4204n3.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cpu_cache_powerpc_e200z4204n3_a.o: ../src/cpu_cache_powerpc_e200z4204n3_a.S
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: Standard S32DS Assembler'
	powerpc-eabivle-gcc "@src/cpu_cache_powerpc_e200z4204n3_a.args" -c -o "src/cpu_cache_powerpc_e200z4204n3_a.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cpu_core.o: ../src/cpu_core.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/cpu_core.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/cpu_core.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/flashrchw.o: ../src/flashrchw.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/flashrchw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/flashrchw.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intc_SW_mode_isr_vectors_MPC5744P.o: ../src/intc_SW_mode_isr_vectors_MPC5744P.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/intc_SW_mode_isr_vectors_MPC5744P.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/intc_SW_mode_isr_vectors_MPC5744P.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intc_sw_handlers.o: ../src/intc_sw_handlers.S
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: Standard S32DS Assembler'
	powerpc-eabivle-gcc "@src/intc_sw_handlers.args" -c -o "src/intc_sw_handlers.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib_ascii.o: ../src/lib_ascii.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/lib_ascii.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/lib_ascii.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib_math.o: ../src/lib_math.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/lib_math.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/lib_math.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib_mem.o: ../src/lib_mem.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/lib_mem.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/lib_mem.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib_str.o: ../src/lib_str.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/lib_str.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/lib_str.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_core.o: ../src/os_core.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_core.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_core.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_cpu_a.o: ../src/os_cpu_a.S
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: Standard S32DS Assembler'
	powerpc-eabivle-gcc "@src/os_cpu_a.args" -c -o "src/os_cpu_a.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_cpu_c.o: ../src/os_cpu_c.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_cpu_c.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_cpu_c.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_dbg_r.o: ../src/os_dbg_r.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_dbg_r.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_dbg_r.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_flag.o: ../src/os_flag.c
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_flag.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_flag.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_mbox.o: ../src/os_mbox.c
	@echo 'Building file: $<'
	@echo 'Executing target #27 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_mbox.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_mbox.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_mem.o: ../src/os_mem.c
	@echo 'Building file: $<'
	@echo 'Executing target #28 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_mem.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_mem.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_mutex.o: ../src/os_mutex.c
	@echo 'Building file: $<'
	@echo 'Executing target #29 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_mutex.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_mutex.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_q.o: ../src/os_q.c
	@echo 'Building file: $<'
	@echo 'Executing target #30 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_q.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_q.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_sem.o: ../src/os_sem.c
	@echo 'Building file: $<'
	@echo 'Executing target #31 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_sem.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_sem.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_task.o: ../src/os_task.c
	@echo 'Building file: $<'
	@echo 'Executing target #32 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_task.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_task.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_time.o: ../src/os_time.c
	@echo 'Building file: $<'
	@echo 'Executing target #33 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_time.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_time.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os_tmr.o: ../src/os_tmr.c
	@echo 'Building file: $<'
	@echo 'Executing target #34 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/os_tmr.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/os_tmr.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


