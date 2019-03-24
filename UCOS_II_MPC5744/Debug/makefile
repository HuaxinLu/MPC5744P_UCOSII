################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 35
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
UCOS_II_MPC5744.elf \

EXECUTABLES_QUOTED += \
"UCOS_II_MPC5744.elf" \

EXECUTABLES_OS_FORMAT += \
UCOS_II_MPC5744.elf \

SECONDARY_SIZE += \
UCOS_II_MPC5744.siz \

SECONDARY_SIZE_QUOTED += \
"UCOS_II_MPC5744.siz" \

SECONDARY_SIZE_OS_FORMAT += \
UCOS_II_MPC5744.siz \


# All Target
all: warning-messages explicit-dependencies UCOS_II_MPC5744.elf secondary-outputs

# Tool invocations
UCOS_II_MPC5744.elf: $(OBJS) C:/Users/uu/Desktop/MPC5744/UCOS_II_MPC5744/Project_Settings/Linker_Files/57xx_flash.ld C:/Users/uu/Desktop/MPC5744/UCOS_II_MPC5744/Project_Settings/Linker_Files/libs.ld $(OSPT) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #36 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	powerpc-eabivle-gcc -o "UCOS_II_MPC5744.elf" "@UCOS_II_MPC5744.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED) $(OSPT)
	@echo 'Finished building target: $@'
	@echo ' '

UCOS_II_MPC5744.siz: $(EXECUTABLES)
	@echo 'Executing target #37 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	powerpc-eabivle-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*.d  ./*/*/*.o ./*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

