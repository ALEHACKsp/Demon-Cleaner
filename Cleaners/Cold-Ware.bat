TITLE "Cold Ware Cleaner"
rmdir /s /q Call Of Duty Black Ops Cold War\Data\data\shmem
rmdir /s /q %localappdata%\Battle.net
rmdir /s /q %localappdata%\Blizzard Entertainment
rmdir /s /q %appdata%\Battle.net
rmdir /s /q %programdata%\Battle.net
rmdir /s /q %programdata%\Blizzard Entertainment
rmdir /s /q %USERPROFILE%\Documents\Call Of Duty Black Ops Cold War
del /f /q %USERPROFILE%\Documents\Call Of Duty Black Ops Cold War
del /f /q %programdata%\Blizzard Entertainment
del /f /q %programdata%\Battle.net
del /f /q %appdata%\Battle.net
del /f /q %localappdata%\Blizzard Entertainment
del /f /q %localappdata%\Battle.net
del /f /q Call Of Duty Black Ops Cold War\Data\data\shmem
@reg delete "HKEY_LOCAL_MACHINE\Software\WOW6432Node\Blizzard Entertainment"
@reg delete "HKEY_CURRENT_USER\Software\Blizzard Entertainment\Battle.net\"

exit
