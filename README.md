# dwm

A dynamic window manager for X written in C.

> This program is meant to be used with [this](https://github.com/andreapasquetto/dwmblocks) status bar. \
> All settings can be modified in [config.h](./config.h).

## Installation

1. Clone the repository:

   ```sh
   git clone https://github.com/andreapasquetto/dwm.git
   ```

2. Make changes to the configuration, if necessary

3. Compile and install:

   ```sh
   make && make clean install
   ```

> This build does not block color fonts from being displayed in the status bar, but [`libxft-bgra`](https://aur.archlinux.org/packages/libxft-bgra/) is needed in order to mitigate rendering issues.

## Features and Patches

- Autostart of `dwmblocks`
- Support for color fonts (with `libxft-bgra`, otherwise the build will crash)
- [accessnthmonitor](https://dwm.suckless.org/patches/accessnthmonitor)
- [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen)
- [cyclelayouts](https://dwm.suckless.org/patches/cyclelayouts)
- [restartsig](https://dwm.suckless.org/patches/restartsig)
- [shiftviewclients](https://github.com/bakkeby/patches/wiki/shiftviewclients)
- [statuscmd](https://dwm.suckless.org/patches/statuscmd)
- [swallow](https://dwm.suckless.org/patches/swallow)

### Apply window rules

Add an entry in the `rules` array. For example, to customize the behavior of the `alacritty` terminal:

```c
static const Rule rules[] = {
//  class  instance  title           tags mask  isfloating  isterminal  noswallow  monitor
  { NULL,  NULL,     "Event Tester", 0,         0,          0,          1,        -1       },
};
```

> Use a utility program like [`xprop`](https://linux.die.net/man/1/xprop) to see the `class`, `instance` and `title` of a window.

## Main keyboard shortcuts

| Keys           | Action                                                          |
| -------------- | --------------------------------------------------------------- |
| `MOD + \`      | cycle through layouts (use `SHIFT` to reverse the order)        |
| `MOD + 1-5`    | switch to the selected tag                                      |
| `MOD + Tab`    | switch to the previously visited tag                            |
| `ALT + Tab`    | cycle through the windows' stack in the active tag              |
| `MOD + Q`      | quit active window                                              |
| `MOD + F`      | toggle fullscreen mode                                          |
| `MOD + B`      | toggle bar visibility                                           |
| `MOD + M`      | increase the number of master windows (use `SHIFT` to decrease) |
| `MOD + PGUP`   | switch to the previous tag that has active windows              |
| `MOD + PGDOWN` | switch to the next tag that has active windows                  |

> For other shortcuts, consider using a universal program like [`sxhkd`](https://github.com/baskerville/sxhkd).
