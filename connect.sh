#!/bin/sh

exec JLinkGDBServer -endian little -device XMC4500-1024 -if swd -speed auto -nogui -halt -vd -ir -xc connect.gdb
