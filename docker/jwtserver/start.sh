#!/bin/sh
nc -p "$PORT" -lke /process_request.sh
