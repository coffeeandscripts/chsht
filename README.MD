
![logo](https://raw.githubusercontent.com/coffeeandscripts/chsht/master/logo.png "logo")
[![Build Status](https://travis-ci.com/coffeeandscripts/chsht.svg?token=dH3y9JqosoN1ssy6bA33&branch=master)](https://travis-ci.com/coffeeandscripts/chsht)

**A lightweight console cheatsheet.**

## Overview
Using chsht, you will no longer struggle to remember keymappings or shortcuts in your favourite console or GUI applications. With a large collection of pre-prepared cheatsheets which are easy to edit, as well as the ability to add your own, it will simplify navigating your out-of-the-box or otherwise customised experience. Built to reflect the ever popular "man pages" that have become the bread and butter of many programmers, developers and enthusiasts, chsht strives to simplify the process and readability, while focussing on user defined processes as well as in-app key-mappings. This is not limited to applications however, as systemwide keymappings can also be forgotten, or common commandline arguments may need easy reference. Many of these are provided, but you can add your own.

## Commands
~~~
-v [val], --view [val]          View sheet
-n [val], --new [val]           New sheet
-l [val], --list [val]          List sheets
--list-all                      List all sheets
-a [val], --add [val]           Add sheet
--set-editor [val]              Set editor
-e [val], --edit [val]          Edit sheet
-r [val], --remove [val]        Remove sheet
-h, --help                      Help
--reset                         Removes ~/.chsht directory
~~~

## Quickstart
### Installation
~~~
$ make
$ make install
$ make clean            # optional to clean working directory
~~~

### Edit sheets
All sheets can be found in ~/.chsht/sheets.

When making a new sheet, simply type:

~~~
chsht -n sheet_name --set-editor your_editor_choice 		# this defaults to vi
~~~

The default sheet will be copied and opened in this case.

~~~
\1Title
\2Subtitle
\sBold\/ - this is bold
\bBlue
\pPurple
\cCyan
\yYellow
\gGreen
\2Subtitle
\*(shortcut)[explanation]
\*(shortcut)[explanation]
\*(shortcut)[explanation]
\*(shortcut)[explanation]
\2Subtitle
\3Subsubtitle
You can write more here
~~~


### Uninstallation
~~~
$ make uninstall
~~~

## For Developers

You can add your own cheatsheet on installation through our command line API:

~~~
$ chsht -a your_app.chsht
~~~

The chsht file can also be manually added to ~/.chsht/sheets/ if that is a preferred option.

## License
Copyright (C) 2018 coffee&scripts and animalsa

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.
