#!/bin/bash
cd /home/pi/software
#WINEDEBUG=+relay wine ./capturess.exe config &>/tmp/relay_debug.log
#WINEDEBUG=fixme-all,err-all,warn+cursor,-all wine ./capturess.exe.so config 
#WINEDEBUG=+relay wineconsole cmd /C ./capturess.exe.so config
/usr/bin/wineserver  -k || true
/usr/bin/wineserver -w
/usr/bin/wineserver -p
sleep 5 
TERM=xterm wineconsole --backend=curses cmd /C ./capturess.exe.so config
