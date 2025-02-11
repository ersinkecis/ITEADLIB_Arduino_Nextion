/**
 * @file NexHardware.h
 *
 * The definition of base API for using Nextion. 
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/8/11
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
#ifndef __NEXHARDWARE_H__
#define __NEXHARDWARE_H__
#include <Arduino.h>
#include "NexConfig.h"
#include "NexTouch.h"

#include <SoftwareSerial.h>
extern SoftwareSerial *nexSerial;

/**
 * @addtogroup CoreAPI 
 * @{ 
 */

/**
 * Init Nextion.  
 * 
 * @return true if success, false for failure. 
 */
bool nexInit(void);
bool nexInit(SoftwareSerial *serialPort);
bool nexInit(int baudDebug, int baudDisplay, int pinRX, int pinTX);

/**
 * Listen touch event and calling callbacks attached before.
 * 
 * Supports push and pop at present. 
 *
 * @param nex_listen_list - index to Nextion Components list. 
 * @return none. 
 *
 * @warning This function must be called repeatedly to response touch events
 *  from Nextion touch panel. Actually, you should place it in your loop function. 
 */
void nexLoop(NexTouch *nex_listen_list[]);

/**
 * @}
 */

bool recvRetNumber(uint32_t *number, uint32_t timeout = 100);
uint16_t recvRetString(char *buffer, uint16_t len, uint32_t timeout = 100);
void sendCommand(const char* cmd);
bool recvRetCommandFinished(uint32_t timeout = 100);

/*
 * Code added: 
 * Detect if the device is in sleepMode
 * sleepModeNextion returns if the device automatically enters sleep mode
 * setSleepNexsetSleepNextion allows you to modify the variable that stores whether it is in sleep mode or not, 
 * useful when the device wakes up by command and automatically. It allows you to modify the variable that stores 
 * whether it is in sleep mode or not, useful when the device wakes up by command and automatically.
 */
bool sleepModeNextion();
bool setSleepNextion(bool status);
/*
 * End code added.
 */
 
#endif /* #ifndef __NEXHARDWARE_H__ */
