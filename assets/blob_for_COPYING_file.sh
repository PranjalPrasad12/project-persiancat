#!/bin/bash
# Converts COPYING file to a C++ header for embedding.
# This script converts the COPYING file text into a text blob for the persiancat-browser-CLI portion
#   case 'C': // Display licensing and copying related stuff
# ..................................................................................
#               return 0;
xxd -i ../COPYING > ../persiancat-browser-CLI/COPYING_blob.h
echo "Generated COPYING_blob.h from COPYING"
