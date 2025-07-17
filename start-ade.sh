#!/bin/bash

# Set x11 (or XLibre)
export XDG_SESSION_TYPE=x11

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
