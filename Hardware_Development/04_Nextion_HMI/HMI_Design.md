# HMI DESIGN DOCUMENTATION
<sup>Ganti ke Bahasa Indonesia? [Klik disini!](Desain_HMI.md)</sup>

## Version Log
- [V3.0.0](#v300-unreleased)
- [V2.1.0](#v210)
- [V2.0.0](#v200)
- [V2.0.0](#v200)
- [V1.0.0](#v100) 

- - - -

# V3.0.0 (unreleased)
<sup>[(Back to top)](#version-log)</sup>

#### Developer:
- Haidar
- Ayu (added support for `loadingPage` and `startup` pages)
  
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

#### Developer: Haidar
## Fixed
- Fixed highlight color in setting time 

## Added
- Added access button to `wiringGuide2` page in `windSound` page
- Added access button to `placementGuide2` page in `wiringGuide2` page
- Added charging indicator icon
- Added value of X and Y axes in temperature graph
- Added color indicator of temperature measurement

## Changed
- Changed `startup` page
- Changed buttons layout of `home` page
- Changed `batLev` as battery indicator from `local vscope` to `global vscope`
- Changed timestamp format from 2 line to 1 line `dd/mm/yyyy HH:MM:ss`
- Changed measurement unit appearance in corresponding title, no longer in value box
- Changed lowest slider to 0% with 20% brightness

## Removed
- Removed unnecessary icons 

- - - -

# V2.0.0
<sup>[(Back to top)](#version-log)</sup>

#### Developer: Haidar
## Changed
- **Breaking:** Changed UI layout and color theme totally
- **Breaking:** Pictures in `Picture` pane are dedicated for one page or one effect page per picture, not for icon
- **Breaking:** Pages in `Page` pane renamed to its function
- Changed lowest slider to 20% with 20% brightness
- Changed timestamp display from running to frozen when user adjust the time setting

## Added
- **Breaking:** Added option of temperature trend capture and streaming only

## Removed
- Removed a feature charging indicator
- Removed a feature low battery indicator

- - - -

# V1.0.0
<sup>[(Back to top)](#version-log)</sup>

#### Developer: Rustanto
### :package: Description
The first design created to support the Baby Incubator Tester user interface.