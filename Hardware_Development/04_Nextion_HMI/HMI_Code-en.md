# HMI CODE DOCUMENTATION
## Version log
- [V3.0.0](#v300-unreleased)
- [V2.1.0](#v210)
- [V2.0.0](#v200)
- [V2.0.0](#v200)
- [V1.0.0](#v100) 

- - - -

# V3.0.0 (UNRELEASED)
#### Creator:
- Mr. Haidar
- Mrs. Ayu (added support for `loadingPage` and `startup` pages)
  
## Changed
- **Breaking:** Changed data acquisition method form `wavefrom` to dymamic `line`
- **Breaking:** Separated 4 resolutions of data sampling 
- Changed `startup` page layout
- Changed appearance of loading battery level using `...` while loading

## Added
- Added animated `loadingPage` page
- Added 4 layouts to support 4 modes of data sampling  
- Added `trendSpeed` page to choose interval time of data sampling

- - - -

# V2.1.0
<sup>[(Back to top)](#version-log)</sup>
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

# V2.0.0
<sup>[(Back to top)](#version-log)</sup>
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

# V1.0.0
<sup>[(Back to top)](#version-log)</sup>
#### Creator: Mr. Rustanto
### :package: Description

The first legacy code created to support PCB device that has features:
1. Measure 6 temperature in Celcius, 1 humidity in %RH, and its maximum values, also sound level in dB and air flow in m/s
2. Display measurement results to HMI Nextion every `6000 ms`
3. Store measurement results to SD Card every `3000 ms`
4. Battery level indicator