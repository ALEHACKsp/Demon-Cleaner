@echo off

rmdir /s /q "C:\$RECYCLE.BIN"
rmdir /s /q "C:\Users\Jet\AppData\Local\Temp\"
rmdir /s /q C:\MSOCache
rmdir /s /q C:\System Volume Information
del /f C:\Users\Public\Libraries\collection.dat
del /f D:\steam\steamapps\common\Apex Legends\EasyAntiCheat_launcher.exe
del /f D:\steam\steamapps\common\Apex Legends\EasyAntiCheat_x64.dll
del /f D:\steam\steamapps\common\Apex Legends\OriginSDK.dll
del /f D:\steam\steamapps\common\Apex Legends\steam_api64.dll
del /f C:\steam\steamapps\common\Apex Legends\EasyAntiCheat_launcher.exe
del /f C:\steam\steamapps\common\Apex Legends\EasyAntiCheat_x64.dll
del /f C:\steam\steamapps\common\Apex Legends\OriginSDK.dll
del /f C:\steam\steamapps\common\Apex Legends\steam_api64.dll
del /f E:\steam\steamapps\common\Apex Legends\EasyAntiCheat_launcher.exe
del /f E:\steam\steamapps\common\Apex Legends\EasyAntiCheat_x64.dll
del /f E:\steam\steamapps\common\Apex Legends\OriginSDK.dll
del /f E:\steam\steamapps\common\Apex Legends\steam_api64.dll
del /f F:\steam\steamapps\common\Apex Legends\EasyAntiCheat_launcher.exe
del /f F:\steam\steamapps\common\Apex Legends\EasyAntiCheat_x64.dll
del /f F:\steam\steamapps\common\Apex Legends\OriginSDK.dll
del /f F:\steam\steamapps\common\Apex Legends\steam_api64.dll


del /f D:\steam\steamapps\common\Fishing Planet\baselib.dll
del /f D:\steam\steamapps\common\Fishing Planet\UnityPlayer.dll

del /f C:\steam\steamapps\common\Fishing Planet\baselib.dll
del /f C:\steam\steamapps\common\Fishing Planet\UnityPlayer.dll

del /f E:\steam\steamapps\common\Fishing Planet\baselib.dll
del /f E:\steam\steamapps\common\Fishing Planet\UnityPlayer.dll


del /f D:\steam\steamapps\common\Counter-Strike Global Offensive\csgo\bin\client.dll
del /f D:\steam\steamapps\common\Counter-Strike Global Offensive\csgo\bin\server.dll


del /f C:\Users\Default\NTUSER.DAT
del /f C:\Users\%username%\ntuser.ini
del /f C:\Users\%username%\ntuser.pol
rmdir /s /q C:\Users\Public\Shared Files
rmdir /s /q C:\Users\Public\Libraries
del /f C:\%programdata%\ntuser.pol
rmdir /s /q C:\%localappdata%\Microsoft\Feeds
rmdir /s /q C:\%localappdata%\Microsoft\Feeds Cache
rmdir /s /q C:\%localappdata%\Microsoft\Windows\INetCache
rmdir /s /q C:\%localappdata%\Microsoft\Windows\WebCache
del /f C:\$RECYCLE.BIN\desktop.ini
del /f C:\desktop.ini
rmdir /s /q C:\%programdata%\Origin
rmdir /s /q C:\%localappdata%\Origin
rmdir /s /q C:\%appdata%\Origin
rmdir /s /q C:\%homepath%\.Origin
rmdir /s /q C:\%homepath%\.QtWebEngineProcess
rmdir /s /q C:\%homepath%\Saved Games\Respawn
rmdir /s /q C:\%programdata%\Electronic Arts
rmdir /s /q C:\%programfiles%\Common Files\EAInstaller
rmdir /s /q C:\%systemdrive%\Windows\ServiceProfiles\LocalService\AppData\Local\Origin
rmdir /s /q C:\%systemdrive%\Windows\ServiceProfiles\LocalService\AppData\Roaming\Origin
rmdir /s /q C:\%appdata%\EasyAntiCheat
rmdir /s /q C:\%localappdata%\Temp
rmdir /s /q C:\%localappdata%\ConnectedDevicesPlatform
del /f %windir%\INF\setupapi.dev.log
del /f %windir%\INF\setupapi.setup.log
del /f /q %windir%\Temp
del /f /q %windir%\Prefetch
del /f /q %windir%\System32\restore
@reg delete "HKLM\SOFTWARE\Classes\Applications\r5apex.exe" /f
@reg delete "HKCR\Applications\r5apex.exe" /f
@reg delete "HKLM\SOFTWARE\Microsoft\RADAR\HeapLeakDetection\DiagnosedApplications\r5apex.exe" /f
@reg delete "HKLM\SOFTWARE\Respawn\Apex" /f
@reg delete "HKCU\Software\Electronic Arts" /f
@reg delete "HKLM\SOFTWARE\WOW6432Node\Electronic Arts" /f
@reg delete "HKLM\SOFTWARE\Classes\origin" /f
@reg delete "HKLM\SOFTWARE\Classes\origin2" /f
@reg delete "HKCR\origin" /f
@reg delete "HKCR\origin2" /f
@reg delete "HKCR\Applications\Origin.exe" /f
@reg delete "HKLM\SOFTWARE\Classes\Applications\Origin.exe" /f
@reg delete "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\RecentDocs\.Origin" /f
@reg delete "HKLM\SYSTEM\ControlSet001\Services\Origin Client Service" /f
@reg delete "HKLM\SYSTEM\ControlSet001\Services\Origin Web Helper Service" /f
@reg delete "HKLM\SYSTEM\CurrentControlSet\Services\Origin Client Service" /f
@reg delete "HKLM\SYSTEM\CurrentControlSet\Services\Origin Web Helper Service" /f
@reg delete "HKLM\SOFTWARE\Microsoft\RADAR\HeapLeakDetection\DiagnosedApplications\Origin.exe" /f
@reg delete "HKLM\SOFTWARE\Microsoft\RADAR\HeapLeakDetection\DiagnosedApplications\r5apex.exe" /f
@reg delete "HKCR\Local Settings\Software\Microsoft\Windows\Shell\MuiCache" /f
