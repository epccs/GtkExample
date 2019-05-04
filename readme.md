# GtkExample

From <https://github.com/epccs/GtkExample>

## Overview

The [Raspberry Pi Press] has a new [book] on C and GUI programing, GTK is new to me.

[Raspberry Pi Press]: https://www.raspberrypi.org/blog/an-introduction-to-c-gui-programming-the-new-book-from-raspberry-pi-press/
[boook]: https://www.raspberrypi.org/magpi-issues/C_GUI_Programming.pdf


## Guid

I don't have much use for GUI's but from time to time I need to spin something simple and with minimal cost. The R-Pi has turned into the best tool for more jobs than I care to admit so it is past time to learn some GTK.


## toolchain

The developr files for these examples are packaged by Debain. Each example has its files and a Makefile in its own folder. The packages are available from Debain on Ubuntu and Raspbian. 

```
sudo apt-get install libgtk2.0-dev
```

* [libgtk2.0-dev](https://packages.ubuntu.com/search?keywords=libgtk2.0-dev)


## VScode

I want IntelliSense to work; I fear this will be a slight pain.

For metainformation about installed libraries, there is a tool, "man pkg-config" to learn about it. It is used to control the build system for sophisticated software. How do I extract the stuff IntelliSense needs?

```
pkg-config --cflags-only-I gtk+-2.0 | sed 's/-I\([^ ]*\)/"\1",\n/g'
"/usr/include/gtk-2.0",
 "/usr/lib/x86_64-linux-gnu/gtk-2.0/include",
 "/usr/include/gio-unix-2.0/",
 "/usr/include/cairo",
 "/usr/include/pango-1.0",
 "/usr/include/atk-1.0",
 "/usr/include/cairo",
 "/usr/include/pixman-1",
 "/usr/include/gdk-pixbuf-2.0",
 "/usr/include/libpng16",
 "/usr/include/pango-1.0",
 "/usr/include/harfbuzz",
 "/usr/include/pango-1.0",
 "/usr/include/glib-2.0",
 "/usr/lib/x86_64-linux-gnu/glib-2.0/include",
 "/usr/include/freetype2",
 "/usr/include/libpng16",
 "/usr/include/freetype2",
 "/usr/include/libpng16",
```

All those include path's need to be added to ".vscode/c_cpp_properties.json" includePath. That should be something that could be automated, but VScode has bloat issues as it is.