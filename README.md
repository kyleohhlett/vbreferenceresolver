vbreferenceresolver
===================

Resolves DLL/OCX References in VB6 Files

![WINAPI](http://cdn.memegenerator.net/instances/500x/51256513.jpg)

___________________
EXAMPLE REFERENCES |
-------------------|

InkObj.dll (while registered)

7D868ACD-1A5D-4A47-A247-F39741353012

HKEY_CLASSES_ROOT\TypeLib\{7D868ACD-1A5D-4A47-A247-F39741353012}
HKEY_CLASSES_ROOT\Wow6432Node\TypeLib\{7D868ACD-1A5D-4A47-A247-F39741353012}
HKEY_LOCAL_MACHINE\SOFTWARE\Classes\TypeLib\{7D868ACD-1A5D-4A47-A247-F39741353012}
HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Wow6432Node\TypeLib\{7D868ACD-1A5D-4A47-A247-F39741353012}
HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Classes\TypeLib\{7D868ACD-1A5D-4A47-A247-F39741353012}
- path to dll actually at ...\{7D868ACD-1A5D-4A47-A247-F39741353012}\1.0\0\win32

HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Visual Basic\6.0\{7D868ACD-1A5D-4A47-A247-F39741353012}#1.0
- different than above; only one key with path to the respective OCA file
----------------------------------------------------------------------------------------------------------------------------
IGThreed40.ocx (while registered)

F20E41DE-526A-423A-B746-D860D06076B4

HKEY_CLASSES_ROOT\TypeLib\{F20E41DE-526A-423A-B746-D860D06076B4}
HKEY_CLASSES_ROOT\Wow6432Node\TypeLib\{F20E41DE-526A-423A-B746-D860D06076B4}
HKEY_LOCAL_MACHINE\SOFTWARE\Classes\TypeLib\{F20E41DE-526A-423A-B746-D860D06076B4}
HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Wow6432Node\TypeLib\{F20E41DE-526A-423A-B746-D860D06076B4}
HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Classes\TypeLib\{F20E41DE-526A-423A-B746-D860D06076B4}
- path to dll actually at ..\{F20E41DE-526A-423A-B746-D860D06076B4}\4.0\0\win32

HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Visual Basic\6.0\{F20E41DE-526A-423A-B746-D860D06076B4}#4.0
----------------------------------------------------------------------------------------------------------------------------
AbaleZip.dll

HKEY_CLASSES_ROOT\TypeLib\{99396B3B-57DC-41BB-9957-6917CC1980B0}
HKEY_CLASSES_ROOT\Wow6432Node\TypeLib\{99396B3B-57DC-41BB-9957-6917CC1980B0}
HKEY_LOCAL_MACHINE\SOFTWARE\Classes\TypeLib\{99396B3B-57DC-41BB-9957-6917CC1980B0}
HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Wow6432Node\TypeLib\{99396B3B-57DC-41BB-9957-6917CC1980B0}
HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Classes\TypeLib\{99396B3B-57DC-41BB-9957-6917CC1980B0}
----------------------------------------------------------------------------------------------------------------------------