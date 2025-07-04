#!/bin/bash

# Set x11 (or XLibre)
export XDG_SESSION_TYPE=x11

# Start the Ashire window manager
# ashire-window-manager &

# Start Window Manager (until AshireWM is made)
kwin_x11 &

# Start Panel
ashire-panel &

# Wait for processes to finish (or sleep)
wait
