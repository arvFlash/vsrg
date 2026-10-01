vsrg written in C using raylib
to compile, first compile make and create a lib directory, then put your libraylib.a into either lib/windows or lib/linux/x11 or lib/linux/wayland depending on your OS / display server
running make will compile for linux x11
running make wayland will compile for linux wayland
running make windows will compile for windows 
