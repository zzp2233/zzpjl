SET SCRIPT_PATH=%~dp0%
SET PATH=%SCRIPT_PATH%\..\tools\utils;%PATH%
make "%1" -j %NUMBER_OF_PROCESSORS%
