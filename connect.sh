#!/bin/sh

JLinkGDBServer -device XMC4500-1024 -if swd -speed auto -nogui -xc connect.gdb
