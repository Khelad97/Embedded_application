#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ecu/ecu_button/ecu_button.c ecu/ecu_keypad/ecu_keypad.c ecu/ecu_lcd/ecu_lcd.c ecu/ecu_led/ecu_led.c ecu/ecu_motor/ecu_motor.c ecu/ecu_relay/ecu_relay.c mcal/mcal_gpio/mcal_gpio.c application.c device_config.c mcal/interrupt/mcal_external_interrupt.c mcal/interrupt/mcal_interrupt_manager.c mcal/timers/mcal_timer0.c mcal/timers/mcal_timer1.c mcal/timers/mcal_timer2.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ecu/ecu_button/ecu_button.p1 ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1 ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1 ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1 ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1 ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1 ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/device_config.p1 ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/mcal/timers/mcal_timer0.p1 ${OBJECTDIR}/mcal/timers/mcal_timer1.p1 ${OBJECTDIR}/mcal/timers/mcal_timer2.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ecu/ecu_button/ecu_button.p1.d ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1.d ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1.d ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1.d ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1.d ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1.d ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/device_config.p1.d ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/mcal/timers/mcal_timer0.p1.d ${OBJECTDIR}/mcal/timers/mcal_timer1.p1.d ${OBJECTDIR}/mcal/timers/mcal_timer2.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ecu/ecu_button/ecu_button.p1 ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1 ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1 ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1 ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1 ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1 ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/device_config.p1 ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/mcal/timers/mcal_timer0.p1 ${OBJECTDIR}/mcal/timers/mcal_timer1.p1 ${OBJECTDIR}/mcal/timers/mcal_timer2.p1

# Source Files
SOURCEFILES=ecu/ecu_button/ecu_button.c ecu/ecu_keypad/ecu_keypad.c ecu/ecu_lcd/ecu_lcd.c ecu/ecu_led/ecu_led.c ecu/ecu_motor/ecu_motor.c ecu/ecu_relay/ecu_relay.c mcal/mcal_gpio/mcal_gpio.c application.c device_config.c mcal/interrupt/mcal_external_interrupt.c mcal/interrupt/mcal_interrupt_manager.c mcal/timers/mcal_timer0.c mcal/timers/mcal_timer1.c mcal/timers/mcal_timer2.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ecu/ecu_button/ecu_button.p1: ecu/ecu_button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_button" 
	@${RM} ${OBJECTDIR}/ecu/ecu_button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_button/ecu_button.p1 ecu/ecu_button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_button/ecu_button.d ${OBJECTDIR}/ecu/ecu_button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1: ecu/ecu_keypad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_keypad" 
	@${RM} ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1 ecu/ecu_keypad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.d ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1: ecu/ecu_lcd/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_lcd" 
	@${RM} ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1 ecu/ecu_lcd/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.d ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu/ecu_led/ecu_led.p1: ecu/ecu_led/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_led" 
	@${RM} ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1 ecu/ecu_led/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_led/ecu_led.d ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1: ecu/ecu_motor/ecu_motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_motor" 
	@${RM} ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1 ecu/ecu_motor/ecu_motor.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.d ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1: ecu/ecu_relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_relay" 
	@${RM} ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1 ecu/ecu_relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.d ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1: mcal/mcal_gpio/mcal_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/mcal_gpio" 
	@${RM} ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1 mcal/mcal_gpio/mcal_gpio.c 
	@-${MV} ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.d ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/device_config.p1: device_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/device_config.p1.d 
	@${RM} ${OBJECTDIR}/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/device_config.p1 device_config.c 
	@-${MV} ${OBJECTDIR}/device_config.d ${OBJECTDIR}/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1: mcal/interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/interrupt" 
	@${RM} ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1 mcal/interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.d ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1: mcal/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/interrupt" 
	@${RM} ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1 mcal/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/timers/mcal_timer0.p1: mcal/timers/mcal_timer0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/timers" 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/timers/mcal_timer0.p1 mcal/timers/mcal_timer0.c 
	@-${MV} ${OBJECTDIR}/mcal/timers/mcal_timer0.d ${OBJECTDIR}/mcal/timers/mcal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/timers/mcal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/timers/mcal_timer1.p1: mcal/timers/mcal_timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/timers" 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/timers/mcal_timer1.p1 mcal/timers/mcal_timer1.c 
	@-${MV} ${OBJECTDIR}/mcal/timers/mcal_timer1.d ${OBJECTDIR}/mcal/timers/mcal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/timers/mcal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/timers/mcal_timer2.p1: mcal/timers/mcal_timer2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/timers" 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/timers/mcal_timer2.p1 mcal/timers/mcal_timer2.c 
	@-${MV} ${OBJECTDIR}/mcal/timers/mcal_timer2.d ${OBJECTDIR}/mcal/timers/mcal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/timers/mcal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ecu/ecu_button/ecu_button.p1: ecu/ecu_button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_button" 
	@${RM} ${OBJECTDIR}/ecu/ecu_button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_button/ecu_button.p1 ecu/ecu_button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_button/ecu_button.d ${OBJECTDIR}/ecu/ecu_button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1: ecu/ecu_keypad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_keypad" 
	@${RM} ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1 ecu/ecu_keypad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.d ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_keypad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1: ecu/ecu_lcd/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_lcd" 
	@${RM} ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1 ecu/ecu_lcd/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.d ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_lcd/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu/ecu_led/ecu_led.p1: ecu/ecu_led/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_led" 
	@${RM} ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1 ecu/ecu_led/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_led/ecu_led.d ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_led/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1: ecu/ecu_motor/ecu_motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_motor" 
	@${RM} ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1 ecu/ecu_motor/ecu_motor.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.d ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_motor/ecu_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1: ecu/ecu_relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/ecu/ecu_relay" 
	@${RM} ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1 ecu/ecu_relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.d ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu/ecu_relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1: mcal/mcal_gpio/mcal_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/mcal_gpio" 
	@${RM} ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1 mcal/mcal_gpio/mcal_gpio.c 
	@-${MV} ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.d ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/mcal_gpio/mcal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/device_config.p1: device_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/device_config.p1.d 
	@${RM} ${OBJECTDIR}/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/device_config.p1 device_config.c 
	@-${MV} ${OBJECTDIR}/device_config.d ${OBJECTDIR}/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1: mcal/interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/interrupt" 
	@${RM} ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1 mcal/interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.d ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1: mcal/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/interrupt" 
	@${RM} ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1 mcal/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/timers/mcal_timer0.p1: mcal/timers/mcal_timer0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/timers" 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/timers/mcal_timer0.p1 mcal/timers/mcal_timer0.c 
	@-${MV} ${OBJECTDIR}/mcal/timers/mcal_timer0.d ${OBJECTDIR}/mcal/timers/mcal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/timers/mcal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/timers/mcal_timer1.p1: mcal/timers/mcal_timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/timers" 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/timers/mcal_timer1.p1 mcal/timers/mcal_timer1.c 
	@-${MV} ${OBJECTDIR}/mcal/timers/mcal_timer1.d ${OBJECTDIR}/mcal/timers/mcal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/timers/mcal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal/timers/mcal_timer2.p1: mcal/timers/mcal_timer2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcal/timers" 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/mcal/timers/mcal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal/timers/mcal_timer2.p1 mcal/timers/mcal_timer2.c 
	@-${MV} ${OBJECTDIR}/mcal/timers/mcal_timer2.d ${OBJECTDIR}/mcal/timers/mcal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal/timers/mcal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/application.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/application.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/application.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/application.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/application.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/application.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
