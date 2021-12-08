/* See LICENSE file for copyright and license details. */

// APPEARANCE
static const unsigned int borderpx = 2; // windows borders
static const unsigned int snap     = 5; // threshold for window snap
static const int swallowfloating   = 0; // 1 = swallow floating windows by default
static const int showbar           = 1; // 0 = no bar
static const int topbar            = 1; // 0 = bottom bar

static const char *fonts[] = {
	"JetBrainsMono Nerd Font:size=10",
	"JoyPixels:pixelsize=10:antialias=true:autohint=true",
};

static const char *colors[][3] = {
//                 fg         bg         border
	[SchemeNorm] = { "#ffffff", "#000000", "#888888" },
	[SchemeSel]  = { "#ffffff", "#1976d2", "#1976d2" },
};

// TAGS
static const char *tags[] = { ">_", "{}", "~/", "www", "?" };

static const Rule rules[] = {
//  class  instance  title           tags mask  isfloating  isterminal  noswallow  monitor
	{ NULL,  NULL,     "Event Tester", 0,         0,          0,          1,        -1       },
};

// LAYOUTS
static const float mfact     = 0.5; // master size [0.05 - 0.95]
static const int nmaster     = 1;   // clients in master
static const int resizehints = 1;   // 1 = respect size hints in tiled resizals
static const Layout layouts[] = {
//  symbol  arrange function
	{ "[]=",  tile             }, // default
	{ "[M]",  monocle          },
	{ "><>",  NULL             },
	{ NULL,   NULL             },
};

// KEYS
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                           KEY, view,       { .ui = 1 << TAG } }, \
	{ MODKEY | ControlMask,             KEY, toggleview, { .ui = 1 << TAG } }, \
	{ MODKEY | ShiftMask,               KEY, tag,        { .ui = 1 << TAG } }, \
	{ MODKEY | ControlMask | ShiftMask, KEY, toggletag,  { .ui = 1 << TAG } },

static Key keys[] = {
	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
	TAGKEYS(XK_5, 4)

//  modifier            key           function          argument
	{ MODKEY,             XK_backslash, cyclelayout,      { .i = +1 }    },
	{ MODKEY | ShiftMask, XK_backslash, cyclelayout,      { .i = -1 }    },
	{ MODKEY,             XK_0,         view,             { .ui = ~0 }   },
	{ MODKEY | ShiftMask, XK_0,         tag,              { .ui = ~0 }   },
	{ MODKEY,             XK_Tab,       view,             { 0 }          },
	{ ALTKEY,             XK_Tab,       focusstack,       { .i = +1 }    },
	{ ALTKEY | ShiftMask, XK_Tab,       focusstack,       { .i = -1 }    },
	{ MODKEY,             XK_q,         killclient,       { 0 }          },
	{ MODKEY,             XK_f,         togglefullscr,    { 0 }          },
	{ MODKEY,             XK_h,         setmfact,         { .f = -0.05 } },
	{ MODKEY,             XK_l,         setmfact,         { .f = +0.05 } },
	{ MODKEY,             XK_b,         togglebar,        { 0 }          },
	{ MODKEY,             XK_m,         incnmaster,       { .i = +1 }    },
	{ MODKEY | ShiftMask, XK_m,         incnmaster,       { .i = -1 }    },
	{ MODKEY,             XK_Page_Up,   shiftviewclients, { .i = -1 }    },
	{ MODKEY,             XK_Page_Down, shiftviewclients, { .i = +1 }    },
	{ MODKEY,             XK_Left,      focusmon,         { .i = -1 }    },
	{ MODKEY | ShiftMask, XK_Left,      tagmon,           { .i = -1 }    },
	{ MODKEY,             XK_Right,     focusmon,         { .i = +1 }    },
	{ MODKEY | ShiftMask, XK_Right,     tagmon,           { .i = +1 }    },
};

// BUTTONS (ClkTagBar, ClkStatusText, ClkWinTitle, ClkClientWin)
static Button buttons[] = {
// click           event mask  button   function        argument
	{ ClkTagBar,     0,          Button1, view,           { 0 }      },
	{ ClkTagBar,     0,          Button3, toggleview,     { 0 }      },
	{ ClkStatusText, 0,          Button1, sigdwmblocks,   { .i = 1 } },
	{ ClkStatusText, 0,          Button2, sigdwmblocks,   { .i = 2 } },
	{ ClkStatusText, 0,          Button3, sigdwmblocks,   { .i = 3 } },
	{ ClkWinTitle,   0,          Button2, zoom,           { 0 }      },
	{ ClkClientWin,  MODKEY,     Button1, movemouse,      { 0 }      },
	{ ClkClientWin,  MODKEY,     Button2, togglefloating, { 0 }      },
	{ ClkClientWin,  MODKEY,     Button3, resizemouse,    { 0 }      },
};
