/* See LICENSE file for copyright and license details. */

#define TERM "alacritty"      /* default terminal       */
#define TERMCLASS "Alacritty" /* default terminal class */

/* appearance */
static char *fonts[]         = {"JetBrainsMono Nerd Font:size=10"};
static unsigned int borderpx = 2;  /* window border                        */
static int showbar           = 1;  /* 0 = no bar                           */
static int topbar            = 1;  /* 0 = bottom bar                       */
static unsigned int snap     = 10; /* snap                                 */
static int swallowfloating   = 0;  /* 1 = default swallow floating windows */
static unsigned int gappih   = 2;  /* inner gap (horizontal)               */
static unsigned int gappiv   = 2;  /* inner gap (vertical)                 */
static unsigned int gappoh   = 2;  /* outer gap (horizontal)               */
static unsigned int gappov   = 2;  /* outer gap (vertical)                 */
static int smartgaps         = 1;  /* 1 = no outer gap with one window     */

/* colors */
static char normfgcolor[]     = "#ffffff";
static char normbgcolor[]     = "#000000";
static char normbordercolor[] = "#888888";
static char selfgcolor[]      = "#ffffff";
static char selbgcolor[]      = "#1976d2";
static char selbordercolor[]  = "#1976d2";
static char *colors[][3]      = {
/*                fg           bg           border         */
  [SchemeNorm] = {normfgcolor, normbgcolor, normbordercolor},
  [SchemeSel]  = {selfgcolor,  selbgcolor,  selbordercolor },
};

/* tags and window rules */
static char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
static Rule rules[] = {
/* class      instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
  {"Gimp",    NULL,     NULL,           0,         1,          0,          0,         -1      },
  {TERMCLASS, NULL,     NULL,           0,         0,          1,          0,         -1      },
  {"Sxiv",    NULL,     NULL,           0,         1,          0,          0,         -1      },
  {"mpv",     NULL,     NULL,           0,         1,          0,          0,         -1      },
  {NULL,      NULL,     "Event Tester", 0,         0,          0,          1,         -1      },
};

/* layouts */
#define FORCE_VSPLIT 1        /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static float mfact     = 0.5; /* master size [0.05 - 0.95]                                     */
static int nmaster     = 1;   /* clients in master                                             */
static int resizehints = 1;   /* 1 = respect size hints in tiled resizals                      */
static const Layout layouts[] = {
/* symbol  arrange function */
  {"[]=",  tile                  }, /* default */
  {"[M]",  monocle               },
  {"[@]",  spiral                },
  {"[\\]", dwindle               },
  {"M[]",  deck                  },
  {"TTT",  bstack                },
  {"===",  bstackhoriz           },
  {"HHH",  grid                  },
  {"###",  nrowgrid              },
  {"---",  horizgrid             },
  {":::",  gaplessgrid           },
  {":M:",  centeredmaster        },
  {"|M|",  centeredfloatingmaster},
  {"><>",  NULL                  },
  {NULL,   NULL                  },
};

#define SHCMD(cmd) {.v = (const char *[]) {"/bin/sh", "-c", cmd, NULL}} /* shell commands spawner */

/* key bindings */
#include <X11/XF86keysym.h>
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                \
  {MODKEY,                           KEY, view,       {.ui = 1 << TAG}}, \
  {MODKEY | ControlMask,             KEY, toggleview, {.ui = 1 << TAG}}, \
  {MODKEY | ShiftMask,               KEY, tag,        {.ui = 1 << TAG}}, \
  {MODKEY | ControlMask | ShiftMask, KEY, toggletag,  {.ui = 1 << TAG}},
static Key keys[] = {
  TAGKEYS(XK_1, 0)
  TAGKEYS(XK_2, 1)
  TAGKEYS(XK_3, 2)
  TAGKEYS(XK_4, 3)
  TAGKEYS(XK_5, 4)
  TAGKEYS(XK_6, 5)
  TAGKEYS(XK_7, 6)
  TAGKEYS(XK_8, 7)
  TAGKEYS(XK_9, 8)
/* modifier            key                       function          argument */
  {MODKEY,             XK_Escape,                spawn,            SHCMD("dmenusysops")},
  {MODKEY,             XK_F1,                    spawn,            SHCMD("")},
  {MODKEY,             XK_F2,                    spawn,            SHCMD("")},
  {MODKEY,             XK_F3,                    spawn,            SHCMD("")},
  {MODKEY,             XK_F4,                    spawn,            SHCMD("")},
  {MODKEY,             XK_F5,                    spawn,            SHCMD("")},
  {MODKEY,             XK_F6,                    spawn,            SHCMD("")},
  {MODKEY,             XK_F7,                    spawn,            SHCMD("")},
  {MODKEY,             XK_F8,                    spawn,            SHCMD("")},
  {MODKEY,             XK_F9,                    spawn,            SHCMD("")},
  {MODKEY,             XK_F10,                   spawn,            SHCMD("")},
  {MODKEY,             XK_F11,                   spawn,            SHCMD("dmenumount")},
  {MODKEY,             XK_F12,                   spawn,            SHCMD("dmenuumount")},
  {MODKEY,             XK_Print,                 spawn,            SHCMD("dmenuscreenshot")},
  {MODKEY,             XK_Scroll_Lock,           spawn,            SHCMD("")},
  {MODKEY,             XK_Pause,                 spawn,            SHCMD("")},
  {MODKEY,             XK_backslash,             cyclelayout,      {.i = +1}},
  {MODKEY | ShiftMask, XK_backslash,             cyclelayout,      {.i = -1}},
  {MODKEY,             XK_0,                     view,             {.ui = ~0}},
  {MODKEY | ShiftMask, XK_0,                     tag,              {.ui = ~0}},
  {MODKEY,             XK_equal,                 spawn,            SHCMD("")},
  {MODKEY,             XK_apostrophe,            spawn,            SHCMD("")},
  {MODKEY,             XK_grave,                 spawn,            SHCMD("")},
  {MODKEY,             XK_BackSpace,             spawn,            SHCMD("")},
  {MODKEY,             XK_Tab,                   view,             {0}      },
  {MODKEY,             XK_q,                     killclient,       {0}      },
  {MODKEY,             XK_w,                     spawn,            SHCMD("")},
  {MODKEY,             XK_e,                     spawn,            SHCMD("pcmanfm")},
  {MODKEY,             XK_r,                     spawn,            SHCMD("")},
  {MODKEY,             XK_t,                     spawn,            SHCMD("")},
  {MODKEY,             XK_y,                     spawn,            SHCMD("")},
  {MODKEY,             XK_u,                     spawn,            SHCMD("")},
  {MODKEY,             XK_i,                     spawn,            SHCMD("")},
  {MODKEY,             XK_o,                     spawn,            SHCMD("")},
  {MODKEY,             XK_p,                     spawn,            SHCMD("")},
  {MODKEY,             XK_bracketleft,           spawn,            SHCMD("")},
  {MODKEY,             XK_bracketright,          spawn,            SHCMD("")},
  {MODKEY,             XK_Return,                spawn,            SHCMD(TERM)},
  {MODKEY,             XK_a,                     spawn,            SHCMD("")},
  {MODKEY,             XK_s,                     spawn,            SHCMD("")},
  {MODKEY,             XK_d,                     spawn,            SHCMD("")},
  {MODKEY,             XK_f,                     togglefullscr,    {0}      },
  {MODKEY,             XK_g,                     togglegaps,       {0}      },
  {MODKEY | ShiftMask, XK_g,                     defaultgaps,      {0}      },
  {MODKEY,             XK_h,                     setmfact,         {.f = -0.05}},
  {MODKEY,             XK_j,                     focusstack,       {.i = +1 }},
  {MODKEY,             XK_k,                     focusstack,       {.i = -1 }},
  {MODKEY,             XK_l,                     setmfact,         {.f = +0.05}},
  {MODKEY,             XK_z,                     spawn,            SHCMD("")},
  {MODKEY,             XK_x,                     spawn,            SHCMD("")},
  {MODKEY,             XK_b,                     togglebar,        {0}      },
  {MODKEY,             XK_n,                     spawn,            SHCMD("")},
  {MODKEY,             XK_m,                     incnmaster,       {.i = +1}},
  {MODKEY | ShiftMask, XK_m,                     incnmaster,       {.i = -1}},
  {MODKEY,             XK_comma,                 incrgaps,         {.i = -1}},
  {MODKEY,             XK_period,                incrgaps,         {.i = +1}},
  {MODKEY,             XK_minus,                 spawn,            SHCMD("")},
  {MODKEY,             XK_space,                 spawn,            SHCMD("dmenu_run -p 'Launch: '")},
  {MODKEY,             XK_Insert,                spawn,            SHCMD("")},
  {MODKEY,             XK_Delete,                spawn,            SHCMD("")},
  {MODKEY,             XK_Home,                  spawn,            SHCMD("")},
  {MODKEY,             XK_End,                   spawn,            SHCMD("")},
  {MODKEY,             XK_Page_Up,               shiftviewclients, {.i = -1}},
  {MODKEY,             XK_Page_Down,             shiftviewclients, {.i = +1}},
  {MODKEY,             XK_Left,                  focusmon,         {.i = -1}},
  {MODKEY | ShiftMask, XK_Left,                  tagmon,           {.i = -1}},
  {MODKEY,             XK_Right,                 focusmon,         {.i = +1}},
  {MODKEY | ShiftMask, XK_Right,                 tagmon,           {.i = +1}},
  {MODKEY,             XK_Up,                    spawn,            SHCMD("")},
  {MODKEY,             XK_Down,                  spawn,            SHCMD("")},
  {0,                  XF86XK_AudioMute,         spawn,            SHCMD("pamixer -t; pkill -RTMIN+11 dwmblocks")},
  {0,                  XF86XK_AudioRaiseVolume,  spawn,            SHCMD("pamixer --allow-boost -i 5; pkill -RTMIN+11 dwmblocks")},
  {0,                  XF86XK_AudioLowerVolume,  spawn,            SHCMD("pamixer --allow-boost -d 5; pkill -RTMIN+11 dwmblocks")},
  {0,                  XF86XK_AudioPrev,         spawn,            SHCMD("mpc prev")},
  {0,                  XF86XK_AudioNext,         spawn,            SHCMD("mpc next")},
  {0,                  XF86XK_AudioPause,        spawn,            SHCMD("mpc pause")},
  {0,                  XF86XK_AudioPlay,         spawn,            SHCMD("mpc play")},
  {0,                  XF86XK_AudioStop,         spawn,            SHCMD("mpc stop")},
  {0,                  XF86XK_AudioRewind,       spawn,            SHCMD("mpc seek +5")},
  {0,                  XF86XK_AudioForward,      spawn,            SHCMD("mpc seek -5")}
};

/* button definitions (ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, ClkRootWin) */
static Button buttons[] = {
/* click          event mask  button  function         argument */
  {ClkTagBar,     0,          Button1, view,           {0}      },
  {ClkTagBar,     0,          Button3, toggleview,     {0}      },
  {ClkStatusText, 0,          Button1, sigdwmblocks,   {.i = 1} },
  {ClkStatusText, 0,          Button2, sigdwmblocks,   {.i = 2} },
  {ClkStatusText, 0,          Button3, sigdwmblocks,   {.i = 3} },
  {ClkWinTitle,   0,          Button2, zoom,           {0}      },
  {ClkClientWin,  MODKEY,     Button1, movemouse,      {0}      },
  {ClkClientWin,  MODKEY,     Button2, togglefloating, {0}      },
  {ClkClientWin,  MODKEY,     Button3, resizemouse,    {0}      },
};

/* commands not used:
 * - incrigaps
 * - incrogaps
 * - incrihgaps
 * - incrivgaps
 * - incrohgaps
 * - incrovgaps
 * - setlayout
 * - quit
 */

