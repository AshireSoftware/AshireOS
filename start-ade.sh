#!/bin/bash

# Set x11 (or XLibre)
export XDG_SESSION_TYPE=x11

# Set DE and WM info
export XDG_CURRENT_DESKTOP=Ashire
export DESKTOP_SESSION=Ashire

# Start the Ashire window manager
# ashire-window-manager &

# Start Window Manager and compositor (until AshireWM is made)
openbox &
picom -b &

# Start Panel
ashire-panel &

# Set background
~/.fehbg &

# Wait for processes to finish (or sleep)
wait
