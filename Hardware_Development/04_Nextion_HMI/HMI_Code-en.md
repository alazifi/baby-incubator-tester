# ARDUINO CODING DOCUMENTATION
## Version log
- [V3.0.0](#v3.0.0)
- [V2.1.0](#v2.1.0)
- [V2.0.0](#v2.0.0)
- [V2.0.0](#v2.0.0)
- [V1.0.0](#v1.0.0) 

- - - -

<a name="V3.0.0"></a>

# V3.0.0 (UNRELEASED)
#### Creator:
    - Mr. Haidar
    - Mrs. Ayu (added support for `loadingPage` and `startup` pages)
  
## Changed
- **Breaking:** Changed data acquisition method form `wavefrom` to dymamic `line`
- **Breaking:** Separated 4 resolutions of data sampling 
- Changed `startup` page layout
- Changed appearance of loading battery level

## Added
- Added animated `loadingPage` page
- Added 4 layouts to support 4 modes of data sampling  
- Added `trendSpeed` page to choose interval time of data sampling

- - - -

<a name="V2.1.0"></a>

# V2.1.0
#### Creator: Mr. Haidar
## Fixed
- Fixed highlight color in setting time 

## Added
- Added access button to `wiringGuide2` page in `windSound` page
- Added access button to `placementGuide2` page in `wiringGuide2`
- Added `charging indicator` icon
- Added value of Y and X axes in temperature graph
- Added color indicator of temperature measurement

## Changed
- Changed start up page
- Changed buttons home layout
- Changed `batLev` as battery indicator from `local vscope` to `global vscope`
- Changed timestamp format from 2 line to 1 line `dd/mm/yyyy HH:MM:ss`
- Changed measurement unit appearance in corresponding title, no longer in value box
- Changed lowest slider to 0% progress bar with 20% brightness

## Removed
- Removed unnecessary icons 

- - - -

<a name="V2.0.0"></a>

# V2.0.0
#### Creator: Mr. Haidar
## Changed
- **Breaking:** Changed UI layout and color theme totally
- **Breaking:** Pictures in `Picture` pane are dedicated for one page or one effect page per picture, not for icon
- **Breaking:** Pages in `Page` pane renamed to its function
- Changed lowest slider to 20% progress bar with 20% brightness
- Changed timestamp display from running to frozen when adjusting the time setting

## Added
- **Breaking:** Added option of temperature trend capture and streaming only

## Removed
- Removed a feature `charging indicator`
- Removed a feature `low battery indicator`

- - - -

<a name="V1.0.0"></a>

# V1.0.0
#### Creator: Mr. Rustanto
### :package: Description

The first legacy code created to support PCB device that has features:
1. Measure 6 temperature in Celcius, 1 humidity in %RH, and its maximum values, also sound level in dB and air flow in m/s
2. Display measurement results to HMI Nextion every `6000 ms`
3. Store measurement results to SD Card every `3000 ms`
4. Battery level indicator