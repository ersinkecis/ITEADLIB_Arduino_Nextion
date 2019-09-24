@mainpage Home Page

# Nextion

--------------------------------------------------------------------------------

# All Fixes by Ersin Kecis
* libraries.properties file added. (thanks to per1234@github)
* CompButton_v0_32.ino          file renamed (by me) to CompButton.ino
* CompCrop_v0_32.ino            file renamed (by me) to CompCrop.ino
* CompDualStateButton_v0_32.ino file renamed (by me) to CompDualStateButton.ino
* CompGauge_v0_32.ino           file ranamed (by me) to CompGauge.ino
* CompHotspot_v0_32.ino         file ranamed (by me) to CompHotspot.ino
* CompNumber_v0_32.ino          file ranamed (by me) to CompNumber.ino
* CompPage_v0_32.ino            file ranamed (by me) to CompPage.ino
* CompPicture_v0_32.ino         file ranamed (by me) to CompPicture.ino
* CompProgressBar_v0_32.ino     file ranamed (by me) to CompProgressBar.ino
* CompSlider_v0_32.ino          file ranamed (by me) to CompSlider.ino
* CompText_v0_32.ino            file ranamed (by me) to CompText.ino
* CompTimer_v0_32.ino           file ranamed (by me) to CompTimer.ino
* CompWaveform_v0_32.ino        file ranamed (by me) to CompWaveform.ino
* NexHardware.cpp file (thanks to toskabnk@github):
  Code added:
      #define NEX_RET_SLEEP_MODE                  (0X86)
      #define NEX_RET_EXIT_SLEEP_MODE             (0X87)
      bool _sleepModeNextion = false;
  Modified:
      original:  *number = ((uint32_t)temp[4] << 24) | ((uint32_t)temp[3] << 16) | (temp[2] << 8) | (temp[1]);
      modified:  *number = ((uint32_t)temp[4] << 24) | ((uint32_t)temp[3] << 16) | ((uint32_t)temp[2] << 8) | ((uint32_t)temp[1]);
  Code added after this line: if (NEX_RET_EVENT_TOUCH_HEAD == c)
	  else 
	  {
	  	if(NEX_RET_SLEEP_MODE == c)
	  	{
	  		_sleepModeNextion=true;
	  	} 
	  	else
	  	{
              if(NEX_RET_EXIT_SLEEP_MODE == c)
              {
                  _sleepModeNextion=false;
              }
          }
      }
  Code added at and of file:
      bool sleepModeNextion(){
          return _sleepModeNextion;
      }
      bool setSleepNextion(bool status){
          _sleepModeNextion=status;
      }
* NexHardware.h file (thanks to toskabnk@github):
  Code added at end of file:
      bool sleepModeNextion();
      bool setSleepNextion(bool status);
* NexConfig.h file (by me):
  Modified:
      original: #define DEBUG_SERIAL_ENABLE
                #define dbSerial Serial
                #define nexSerial Serial2
      modified: //#define DEBUG_SERIAL_ENABLE
                //#define dbSerial Serial
                #define nexSerial Serial
* NexHardware.cpp file (thanks to speedfox-uk@github):
  Overload method added: bool nexInit(SoftwareSerial *serialPort)
* NexHardware.h file (thanks to speedfox-uk@github):
  Code added:
      #include <SoftwareSerial.h>
      extern SoftwareSerial *nexSerial;
      bool nexInit(SoftwareSerial *serialPort);
* NexGpio.cpp file (thanks to speedfox-uk@github):
  Modified:
      Serial.print(cmd);
      //Serial.print(cmd);
* HMIHardwareSerial.ino file added. (thanks to lincomatic@github)
* HMISoftwareSerial.ino file added. (thanks to lincomatic@github)
* HMI.cpp file added. (code by laicheng.zhang@itead.cc - thanks to lincomatic@github)
* HMI.h file added. (code by laicheng.zhang@itead.cc - thanks to lincomatic@github)
* NexHardware.cpp file (thanks to floggy22@github):
  Overload method added: bool nexInit(int baudDebug, int baudDisplay, int pinRX, int pinTX)
* NexHardware.h file (thanks to floggy22@github):
  Code added:
      bool nexInit(int baudDebug, int baudDisplay, int pinRX, int pinTX);
--------------------------------------------------------------------------------

# Introduction

Nextion Arduino library provides an easy-to-use way to manipulate Nextion serial
displays. Users can use the libarry freely, either in commerical projects or 
open-source prjects,  without any additional condiitons. 

For more information about the Nextion display project, please visit 
[the wiki。](http://wiki.iteadstudio.com/Nextion_HMI_Solution)  
The wiki provdies all the necessary technical documnets, quick start guide, 
tutorials, demos, as well as some useful resources.

To get your Nextion display, please visit 
[iMall.](http://imall.itead.cc/display/nextion.html)

To discuss the project?  Request new features?  Report a BUG? please visit the 
[Forums](http://support.iteadstudio.com/discussions/1000058038)

# Download Source Code 

Latest version is unstable and a mass of change may be applied in a short time 
without any notification for users. Commonly, it is for developers of this 
library. 

**Release version is recommanded for you, unless you are one of developers of this 
library.**

**Release notes** is at
<https://github.com/itead/ITEADLIB_Arduino_Nextion/blob/master/release_notes.md>.

## Latest(unstable)

Latest source code(master branch) can be downloaded:
  <https://github.com/itead/ITEADLIB_Arduino_Nextion/archive/master.zip>. 

You can also clone it via git:

    git clone   https://github.com/itead/ITEADLIB_Arduino_Nextion
    fixed clone https://github.com/ersinkecis/ITEADLIB_Arduino_Nextion_ALL_FIXED

## Releases(stable)

  - https://github.com/itead/ITEADLIB_Arduino_Nextion/archive/v0.7.0.zip
  - https://github.com/itead/ITEADLIB_Arduino_Nextion/archive/v0.7.0.tar.gz

All releases can be available from:
<https://github.com/itead/ITEADLIB_Arduino_Nextion/releases>.

# Documentation

Offline Documentation's entry `doc/Documentation/index.html` shiped with source code
can be open in your browser such as Chrome, Firefox or any one you like. 

# Suppported Mainboards

**Now, All boards, can be supported. :)**

For example:

  - Arduino Nano, ESP8266 and etc. :)
  - Iteaduino MEGA2560
  - Iteaduino UNO
  - Arduino MEGA2560
  - Arduino UNO

# Configuration

In configuration file NexConfig.h, you can find two macros below:

  - dbSerial: Debug Serial (baudrate:9600), needed by beginners for debug your 
    nextion applications or sketches. If your complete your work, it will be a 
    wise choice to disable Debug Serial.

  - nexSerial: Nextion Serial, the bridge of Nextion and your mainboard.

**Note:** the default configuration is for NANO, ESP8266 and all others.

## Redirect dbSerial and nexSerial

If you want to change the default serial to debug or communicate with Nextion ,
you need to modify the line in configuration file:

	#define dbSerial Serial    ---> #define dbSerial Serialxxx
    #define nexSerial Serial2  ---> #define nexSerial Serialxxx

## Disable Debug Serial

If you want to enable the debug information,you need to modify the line in 
configuration file:

    //#define DEBUG_SERIAL_ENABLE ---> #define DEBUG_SERIAL_ENABLE

# UNO-like Mainboards

If your board has only one hardware serial, such as UNO, you should disable 
dbSerial and redirect nexSerial to Serial(Refer to section:`Serial configuration`). 

# Useful Links

<http://blog.iteadstudio.com/nextion-tutorial-based-on-nextion-arduino-library/>

<https://github.com/ersinkecis/ITEADLIB_Arduino_Nextion_ALL_FIXED>

<https://ersinkecis.blogspot.com/>

<https://www.youtube.com/user/ersinkecis>

# License

-------------------------------------------------------------------------------


    The MIT License (MIT) 

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: 
    
    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


-------------------------------------------------------------------------------
