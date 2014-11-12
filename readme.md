# imgtogba

This program converts GIF/PNG/JPG images into a const unsigned 16-bit bitmap array suitable for use in GBA C/C++ programs. Platform is Windows, current version is `1.0`.

# Compiling

Compile program by running compile.bat; GCC required. Output is in prog folder.

# Format details

Array format:

`const unsigned short array[] = { [x dimension], [y dimension], [...color data...] }`

Color bit storage format:

```
FEDCBA9876543210
tbbbbbgggggrrrrr
```

- Nonstandard transparent bit F (`0x8000`) may only be set if transparent mode is on and source is a GIF/PNG with a single transparent palette color.

# Usage

    imgtogba [variable name] [image filename] [(0/1) compact mode] [(0/1) transparent mode]

- Program output is printed to stdout; redirect to a file of your choice.
- Does not support dithering of transparent images; you will have to do that yourself.

# License

Do what you want.

## GD Credits

This program uses the GD graphics library. GD copyright statement:

Portions copyright 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004 by Cold Spring Harbor Laboratory. Funded under Grant P41-RR02188 by the National Institutes of Health.
Portions copyright 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004 by Boutell.Com, Inc.

Portions relating to GD2 format copyright 1999, 2000, 2001, 2002, 2003, 2004 Philip Warner.

Portions relating to PNG copyright 1999, 2000, 2001, 2002, 2003, 2004 Greg Roelofs.

Portions relating to gdttf.c copyright 1999, 2000, 2001, 2002, 2003, 2004 John Ellson (ellson@graphviz.org).

Portions relating to gdft.c copyright 2001, 2002, 2003, 2004 John Ellson (ellson@graphviz.org).

Portions relating to JPEG and to color quantization copyright 2000, 2001, 2002, 2003, 2004, Doug Becker and copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004 Thomas G. Lane. This software is based in part on the work of the Independent JPEG Group. See the file README-JPEG.TXT for more information.

Portions relating to GIF compression copyright 1989 by Jef Poskanzer and David Rowley, with modifications for thread safety by Thomas Boutell.

Portions relating to GIF decompression copyright 1990, 1991, 1993 by David Koblas, with modifications for thread safety by Thomas Boutell.

Portions relating to WBMP copyright 2000, 2001, 2002, 2003, 2004 Maurice Szmurlo and Johan Van den Brande.

Portions relating to GIF animations copyright 2004 Jaakko Hyvatti (jaakko.hyvatti@iki.fi)

Permission has been granted to copy, distribute and modify gd in any context without fee, including a commercial application, provided that this notice is present in user-accessible supporting documentation.

This does not affect your ownership of the derived work itself, and the intent is to assure proper credit for the authors of gd, not to interfere with your productive use of gd. If you have questions, ask. "Derived works" includes all programs that utilize the library. Credit must be given in user-accessible documentation.

This software is provided "AS IS." The copyright holders disclaim all warranties, either express or implied, including but not limited to implied warranties of merchantability and fitness for a particular purpose, with respect to this code and accompanying documentation.

Although their code does not appear in the current release, the authors also wish to thank Hutchison Avenue Software Corporation for their prior contributions.

## Example image credits:

- Sadler_teapots.jpg: By Teapotgeorge (Own work) [Public domain], via Wikimedia Commons
- Rad_weiss_transparent.gif: By Haustao (Own work) [CC-BY-SA-3.0 (http://creativecommons.org/licenses/by-sa/3.0) or GFDL (http://www.gnu.org/copyleft/fdl.html)], via Wikimedia Commons
- flat_file.png: By superoak [Public domain]


