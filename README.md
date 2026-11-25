# NFSMW_NOSTrailFix ![Latest Release Downloads](https://img.shields.io/github/downloads/CiPH3R-88/NFSMW_NOSTrailFix/latest/total)

A lightweight, modern visual enhancement plugin for **Need for Speed: Most Wanted (2005) v1.3**, restoring, fixing, and expanding nitrous flare and trail effects.

---

## Overview

In vanilla *Need for Speed: Most Wanted (2005)*, nitrous trail rendering suffers from multiple visual issues at high refresh rates and framerates, including rapid flickering, compressed trail lengths, clipping, and immediate disappearing when paused. 

**NFSMW_NOSTrailFix** completely resolves these engine limitations, offering high-refresh compatibility, customizable trail scaling, smooth fade-out blending, and complete 360° camera visibility.

---

## Features

### 🚀 High-FPS Compatibility
- **Flicker Elimination (`NOSTrailFixForHighFPS`):** Fixes the vanilla engine timing bug that causes nitrous trails to flicker rapidly at framerates above 60 FPS (120Hz, 144Hz, 165Hz, 240Hz+).
- **Framerate-Aware Length Scaling:** Prevents nitrous trails from compressing into tiny dots or stubby artifacts at high frame rates, keeping trails long and cinematic.

### 🎨 Visual & Length Customization
- **Custom Trail Length (`NOSTrailLength`):** Scale and extend nitrous trail lengths without clipping forward through the car's chassis.
- **Position Offset Scalar (`NOSTrailPositionScalar`):** Fine-tune the trail origin position relative to the vehicle's taillights and exhaust points.
- **Smooth Tip Fade-Out (`NOSTrailFadeOut`):** Gradually fades out the trailing tip into the background (customizable from 1% to 80%), eliminating harsh squared edges.
- **Master Trail Toggle (`NOSTrail`):** Quickly enable or disable the entire nitrous trail visual effect.

### 📸 Pause & Camera Fixes
- **Pause Freeze Fix (`NOSFlareTrailPauseFix`):** Freezes active NOS trails in place when the game is paused rather than instantly vanishing.
- **360° Camera Visibility:** Fixes the directional frustum culling bug, allowing NOS trails to remain fully visible from all camera angles (front, side, and debug cameras) instead of disappearing when looking forward.

---

## Installation

1. Copy `NFSMW_NOSTrailFix.asi` and `NFSMW_NOSTrailFix.ini` into your game's `scripts/` directory.
   *(Requires an ASI Loader such as [`Ultimate ASI Loader / dinput8.dll`](https://github.com/ThirteenAG/Ultimate-ASI-Loader/releases)).*
2. Configure your desired options in `NFSMW_NOSTrailFix.ini`.

---

## Configuration Reference

All options can be configured inside **`NFSMW_NOSTrailFix.ini`**:

```ini
[NOSTRAIL]
NOSTrail = 1                                   ; 0 = Off | 1 = Enabled (Default)
NOSTrailLength = 0                             ; 0 = Default set by game | Values > 0 scale trail length directly
NOSTrailPositionScalar = 0.0                   ; 0 = Default (no offset) | Values > 0 offset trail position relative to tail lights
NOSFlareTrailPauseFix = 0                      ; 0 = Off (Default) | 1 = Keep NOS flare trail visible/frozen while paused
NOSTrailFixForHighFPS = 1                      ; 0 = Off | 1 = Fix trail flicker and scale length properly at high FPS (Default)
NOSTrailFadeOut = 40                           ; 0 = Off | 1 to 80 = Percentage of trail tip to fade out smoothly into background (Default: 40)
```

| Setting | Description | Default |
| :--- | :--- | :--- |
| `NOSTrail` | Master toggle to enable or disable nitrous trail rendering. | `1` |
| `NOSTrailLength` | Custom multiplier/scalar for trail length (`0` = game default). | `0` |
| `NOSTrailPositionScalar` | Fine-tunes the origin anchor position relative to taillights. | `0.0` |
| `NOSFlareTrailPauseFix` | Keeps trails visible and frozen at 360° angles during pause. | `0` |
| `NOSTrailFixForHighFPS` | Eliminates flickering and fixes length scaling at >60 FPS. | `1` |
| `NOSTrailFadeOut` | Percentage (1–80%) of the trail tip that fades out smoothly. | `40` |

---

## Compatibility

- **Game Version:** Need for Speed: Most Wanted (2005) v1.3 (`speed.exe`).
- **Companion Mods:** 100% compatible with `NFSMW_WideScreenMode`, `NFSMW_ControllerSupport`, `X360Stuff`, `HD Reflections`, and `Sunset Mod`.

---

## Credits

- **nlg** — For providing the IDA Pro database for NFS Most Wanted.
- **ThirteenAG** — Referred to for initial research.
