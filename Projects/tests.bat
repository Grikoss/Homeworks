@echo off
for /R %%i in (*.sln) do (%msbuild% %%i)
for /R %%i in (*.exe) do (
%%i open
if errorlevel 1 (echo %%i - tests failed!) else (echo %%i - tests passed!)
)
pause