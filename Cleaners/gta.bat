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

del /f %windir%\GTAV\D3DCompiler_40.dll
del /f C:\$RECYCLE.BIN\desktop.ini
del /f %windir%\GTAV\xinput1_3.dll
del /f %windir%\GTAV\xinput9_1_0.dll
del /f %windir%\GTAV\d3dx9_30.dll

exit
