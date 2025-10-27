@echo off
windres res.rc -o res.o
if %errorlevel% neq 0 (
    echo Failed to generate resource object file.
    exit /b %errorlevel%
)
echo === Resource object file generated successfully!. ===
