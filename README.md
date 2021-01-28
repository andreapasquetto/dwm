# dwm

A dynamic window manager for X written in C.

> All settings can be modified in [config.h](./config.h).

## Patches

- [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen)
- [cyclelayouts](https://dwm.suckless.org/patches/cyclelayouts)
- [hide-vacant-tags](https://dwm.suckless.org/patches/hide_vacant_tags)
- [restartsig](https://dwm.suckless.org/patches/restartsig)
- [shiftviewclients](https://github.com/bakkeby/patches/wiki/shiftviewclients)
- [statuscmd and statuscmd-signal](https://dwm.suckless.org/patches/statuscmd)
- [swallow](https://dwm.suckless.org/patches/swallow)
- [vanitygaps](https://dwm.suckless.org/patches/vanitygaps)

## Main keyboard shortcuts

| Keys              | Action                                                             |
| ----------------- | ------------------------------------------------------------------ |
| `MOD + Enter`     | spawn defaul terminal (alacritty)                                  |
| `MOD + Space`     | spawn default launcher (dmenu)                                     |
| `MOD + 1-9`       | switch to selected tag                                             |
| `MOD + Tab`       | switch to previous visited tag                                     |
| `MOD + F`         | toggle fullscreen                                                  |
| `MOD + \`         | cycle through available layouts (use `SHIFT` to reverse the order) |
| `MOD + PGUP`      | switch to next (non vacant) tag                                    |
| `MOD + PGDOWN`    | switch to previous (non vacant) tag                                |
| `MOD + G`         | toggle gaps                                                        |
| `MOD + SHIFT + G` | set default gaps size                                              |
| `MOD + ,`         | decrease gaps size                                                 |
| `MOD + .`         | increase gaps size                                                 |
