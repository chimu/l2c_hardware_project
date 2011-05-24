@ECHO OFF

IF EXIST "C:\yagarto-ARM\openocd-r279\bin\openocd-ftd2xx.exe" (
  ECHO Found yagarto-arm 2007 - starting openocd:
  start C:\yagarto-ARM\openocd-r279\bin\openocd-ftd2xx -f ./cfg/arm7_ft2232.cfg
  C:\yagarto-ARM\17112007\bin\arm-elf-insight -x ./cfg/test_ram.gdb
) ELSE (
  ECHO No local install of yagarto-arm 2007 - trying to map to the network...
  IF NOT EXIST "V:\MSTdev\yagarto-ARM\openocd-r279\bin\openocd-ftd2xx.exe" (
    net use v: /delete /yes
    net use v: \\elec.canterbury.ac.nz\root\elecapp
    IF EXIST "V:\MSTdev\yagarto-ARM\openocd-r279\bin\openocd-ftd2xx.exe" (
      start V:\MSTdev\yagarto-ARM\openocd-r279\bin\openocd-ftd2xx.exe -f ./cfg/arm7_ft2232.cfg
      REM V:\MSTdev\yagarto-ARM\17112007\bin\arm-eabi-insight -x ./cfg/test_ram.gdb
      C:\yagarto-ARM\dev\gcc_insight_win\insight\bin\arm-eabi-insight -x ./cfg/test_ram.gdb
    ) ELSE (
      ECHO Couldn't connect to the network - either unavailable or 
      ECHO insufficient rights.
      ECHO Can't set the path to the compiler.
      ECHO Setup has failed.
      pause
    )
  ) ELSE (
    ECHO Found yagarto-arm on the network - setting paths variables:
    start V:\MSTdev\yagarto-ARM\openocd-r279\bin\openocd-ftd2xx.exe -f ./cfg/arm7_ft2232.cfg
    REM V:\MSTdev\yagarto-ARM\17112007\bin\arm-eabi-insight -x ./cfg/test_ram.gdb
    C:\yagarto-ARM\dev\gcc_insight_win\insight\bin\arm-eabi-insight -x ./cfg/test_ram.gdb  
  )
)
