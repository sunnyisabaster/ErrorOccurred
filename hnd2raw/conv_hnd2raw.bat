@echo off
setlocal enabledelayedexpansion
set /a v=000
for %%i in (F:\junzhengdu\Filtered_data\crack_calibration_2121Nov04\blank_90kV_1.5mA_2.5mm_512x512\*.hnd) do (
echo %%i
@hnd conv %%i F:\junzhengdu\Filtered_data\crack_calibration_2121Nov04\blank_90kV_1.5mA_2.5mm_512x512_raw\!v!.raw
set /a v+=1
)
pause