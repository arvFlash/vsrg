vsrg written in C using raylib

to compile, first compile raylib and create a lib directory, then put your libraylib.a into either lib/windows or lib/linux/x11 or lib/linux/wayland depending on your OS / display server

```
make // compiles for X11
make wayland // compiles for wayland
make windows // compiles for windows
```
