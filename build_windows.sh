#!/bin/sh

pacman -Syu --noconfirm
pacman -S --needed --noconfirm zstd
pacman -S --needed --noconfirm
    zstd \
    mingw-w64-x86_64-cmake \
    mingw-w64-x86_64-ninja \
    mingw-w64-x86_64-vala \
    mingw-w64-x86_64-gobject-introspection \
    mingw-w64-x86_64-gsettings-desktop-schemas \
    mingw-w64-x86_64-gtk3 \
    mingw-w64-x86_64-gspell \
    mingw-w64-x86_64-gtksourceview4 \
    mingw-w64-x86_64-libgit2-glib \
    mingw-w64-x86_64-libpeas \
    mingw-w64-x86_64-libsecret \
    mingw-w64-x86_64-libsoup \
    mingw-w64-x86_64-libdazzle

meson --prefix $PWD/gitg-dist build \
&& cd build \
&& ninja \
&& ninja install
