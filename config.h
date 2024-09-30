/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int refresh_rate        = 165;  /* matches dwm's mouse event processing to your monitor's refresh rate for smoother window interactions */
static const unsigned int enable_noborder     = 1;   /* toggles noborder feature (0=disabled, 1=enabled) */
static const unsigned int borderpx            = 2;   /* border pixel of windows */
static const unsigned int snap                = 26;  /* snap pixel */
static const int swallowfloating              = 1;   /* 1 means swallow floating windows by default */
static const unsigned int systraypinning      = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft       = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing      = 5;   /* systray spacing */
static const int systraypinningfailfirst      = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor */
static const int showsystray                  = 1;   /* 0 means no systray */
static const int showbar                      = 1;   /* 0 means no bar */
static const int topbar                       = 1;   /* 0 means bottom bar */
#define ICONSIZE                              17     /* icon size */
#define ICONSPACING                           5      /* space between icon and title */
#define SHOWWINICON                           1      /* 0 means no winicon */
static const char *fonts[]                    = { "JetBrainsMono Nerd Font Mono:size=14", "Noto Color Emoji:pixelsize=14:antialias=true:autohint=true" };

//static const char normbordercolor[]           = "#3B4252";
//static const char normbgcolor[]               = "#2E3440";
//static const char normfgcolor[]               = "#D8DEE9";
//static const char selbordercolor[]            = "#434C5E";
//static const char selbgcolor[]                = "#434C5E";
//static const char selfgcolor[]                = "#ECEFF4";
//
//static const char *colors[][3] = {
//    /*               fg           bg           border   */
//    [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
//    [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor },
//};

static const char col_flamingo[]    = "#f2cdcd";
static const char col_crust[]       = "#111115";
static const char col_mantle[]      = "#181825";
static const char col_base[]        = "#1e1e2e";
static const char col_surface0[]    = "#313244";
static const char col_text[]    = "#cdd6f4";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_text, col_base, col_mantle},
	[SchemeSel]  = { col_text, col_surface0,  col_flamingo },
};

static const char *const autostart[] = {
	"sh", "-c", "feh ~/Pictures/Wallpapers/* --recursive --randomize --bg-fill", NULL,
	"sh", "-c", "xrandr --output DP-0 --mode 1920x1080 --rate 165.00", NULL,
	"dunst", NULL,
	"/usr/lib/mate-polkit/polkit-mate-authentication-agent-1", NULL,
	"picom", NULL,
	"aw-qt", NULL,
	"slstatus", NULL,
    NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "󰝚", "󰭹", "", "", "" };

static const char ptagf[] = "[%s %s]";  /* format of a tag label */
static const char etagf[] = "[%s]";     /* format of an empty tag */
static const int lcaselbl = 0;          /* 1 means make tag label lowercase */

static const Rule rules[] = {
    /* class                instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
    { "St",                 NULL,     NULL,           0,         0,          1,          0,         0 },
    { "kitty",              NULL,     NULL,           0,         0,          1,          0,         0 },
    { "Alacritty",          NULL,     NULL,           0,         0,          1,          0,         0 },
    { "terminator",         NULL,     NULL,           0,         0,          1,          0,         0 },
    { "lutris",             NULL,     NULL,           0,         1,          0,          0,         0 },
    { "steam_app_default",  NULL,     NULL,           0,         1,          0,          0,         0 },
    { "thunar",             NULL,     NULL,           0,         1,          0,          0,         0 },
    { "solanum",             NULL,     NULL,           0,         1,          0,          0,         0 },
    { NULL,                 NULL,     "Event Tester", 0,         0,          0,          1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.6; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;   /* number of clients in master area */
static const int resizehints = 0;   /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "",      tile },    /* first entry is default */
    { "",      NULL },    /* no layout function means floating behavior */
    { "",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ALTKEY,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ALTKEY, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define STATUSBAR "dwmblocks"
/* commands */
static const char *launchercmd[] = { "rofi", "-show", "drun", NULL };
static const char *termcmd[]     = { "kitty", NULL };

//bindsym XF86AudioPlay exec dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.PlayPause
//bindsym XF86AudioPause exec playerctl pause
//bindsym XF86AudioNext exec playerctl next
//bindsym XF86AudioPrev exec playerctl previous
static Key keys[] = {
    /* modifier                     key                        function        argument */
    { MODKEY,                       XK_r,                      spawn,          {.v = launchercmd} },
    { MODKEY,                       XK_Return,                 spawn,          SHCMD ("rofi -modi drun,run -show drun")},
    { MODKEY|ControlMask,           XK_r,                      spawn,          SHCMD ("protonrestart")},
    { MODKEY,                       XK_w,                      spawn,          SHCMD ("brave")},
    { MODKEY,                       XK_b,                      spawn,          SHCMD ("xdg-open https://")},
    { MODKEY|ALTKEY,                       XK_Tab,                    spawn,          SHCMD ("maim -s | xclip -selection clipboard -t image/png; xclip -selection clipboard -t image/png -o > ~/Screenshots/$(date +%F-%H:%M:%S).png")},
    { MODKEY,                       XK_e,                      spawn,          {.v = termcmd } },
    { MODKEY|ALTKEY,                XK_b,                      spawn,          SHCMD ("feh ~/Pictures/Wallpapers/* --recursive --randomize --bg-fill")},
    { 0,                            XF86XK_MonBrightnessUp,    spawn,          SHCMD ("xbacklight -inc 2")},
    { 0,                            XF86XK_MonBrightnessDown,  spawn,          SHCMD ("xbacklight -dec 2")},
    { 0,                            XF86XK_AudioRaiseVolume,   spawn,          SHCMD ("pactl set-sink-volume 0 +1%")},
    { 0,                            XF86XK_AudioLowerVolume,   spawn,          SHCMD ("pactl set-sink-volume 0 -1%")},
    { 0,                            XF86XK_AudioMute,          spawn,          SHCMD ("pactl set-sink-mute 0 toggle")},
    { 0,                            XF86XK_AudioPlay,          spawn,          SHCMD ("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.PlayPause")},
    { 0,                            XF86XK_AudioMute,          spawn,          SHCMD ("playerctl pause")},
    { 0,                            XF86XK_AudioNext,          spawn,          SHCMD ("playerctl next")},
    { 0,                            XF86XK_AudioPrev,          spawn,          SHCMD ("playerctl previous")},
    { MODKEY|ALTKEY,             XK_t,                      togglebar,      {0} },
    { MODKEY,                       XK_j,                      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,                      focusstack,     {.i = -1 } },
    { MODKEY|ALTKEY,             XK_j,                      movestack,      {.i = +1 } },
    { MODKEY|ALTKEY,             XK_k,                      movestack,      {.i = -1 } },
    { MODKEY,                       XK_i,                      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_o,                      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,                      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,                      setmfact,       {.f = +0.05} },
    { MODKEY|ALTKEY,             XK_h,                      setcfact,       {.f = +0.25} },
    { MODKEY|ALTKEY,             XK_l,                      setcfact,       {.f = -0.25} },
    { MODKEY|ALTKEY,             XK_o,                      setcfact,       {.f =  0.00} },
    { MODKEY,                       XK_z,                 zoom,           {0} },
    { MODKEY,                       XK_Tab,                    view,           {0} },
    { MODKEY,                       XK_q,                      killclient,     {0} },
    { MODKEY,                       XK_1,                      setlayout,      {.v = &layouts[0]} }, { MODKEY,                       XK_2,                      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_semicolon,                      fullscreen,     {0} },
    { MODKEY,                       XK_space,                  setlayout,      {0} },
    { MODKEY|ALTKEY,             XK_m,                      togglefloating, {0} },
    { MODKEY|ALTKEY,             XK_y,                      togglefakefullscreen, {0} },
    { MODKEY,                       XK_0,                      view,           {.ui = ~0 } },
    { MODKEY,                       XK_comma,                  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period,                 focusmon,       {.i = +1 } },
    { MODKEY|ALTKEY,             XK_comma,                  tagmon,         {.i = -1 } },
    { MODKEY|ALTKEY,             XK_period,                 tagmon,         {.i = +1 } },
    TAGKEYS(                        XK_a,                      0)
    TAGKEYS(                        XK_s,                      1)
    TAGKEYS(                        XK_d,                      2)
    TAGKEYS(                        XK_f,                      3)
    TAGKEYS(                        XK_g,                      4)
    { MODKEY|ALTKEY,             XK_q,                      quit,           {0} },
    { MODKEY|ControlMask,           XK_q,                      spawn,          SHCMD("$HOME/.config/rofi/powermenu.sh")},
    //{ MODKEY|ControlMask|ShiftMask, XK_r,                      spawn,          SHCMD("systemctl reboot")},
    //{ MODKEY|ControlMask|ShiftMask, XK_s,                      spawn,          SHCMD("systemctl suspend")},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkTagBar,            ALTKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            ALTKEY,         Button3,        toggletag,      {0} },
    { ClkClientWin,         ALTKEY,         Button1,        moveorplace,    {.i = 2} },
    { ClkClientWin,         ALTKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            ALTKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            ALTKEY,         Button3,        toggletag,      {0} },
};
