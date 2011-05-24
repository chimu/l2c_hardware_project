@ECHO OFF

IF EXIST "C:\yagarto-ARM\set-path-17112007.bat" (
  ECHO Found yagarto-arm 2007 - setting the paths variables:
  %windir%\System32\cmd.exe /k C:\yagarto-ARM\set-path-17112007.bat
) ELSE (
  ECHO No local install of yagarto-arm 2007 - trying to map to the network...
  IF NOT EXIST "V:\MSTdev\yagarto-ARM\set-path-17112007.bat" (
    net use v: /delete /yes
    net use v: \\elec.canterbury.ac.nz\root\elecapp
    IF EXIST "V:\MSTdev\yagarto-ARM\set-path-17112007.bat" (
      %windir%\System32\cmd.exe /k V:\MSTdev\yagarto-ARM\set-path-17112007.bat
    ) ELSE (
      ECHO Couldn't connect to the network - either unavailable or 
      ECHO insufficient rights.
      ECHO Can't set the path to the compiler.
      ECHO Setup has failed.
      pause
    )
  ) ELSE (
    ECHO Found yagarto-arm on the network - setting paths variables:
    %windir%\System32\cmd.exe /k V:\MSTdev\yagarto-ARM\set-path-17112007.bat
  )
)
