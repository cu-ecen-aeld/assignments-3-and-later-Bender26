#!/bin/sh

case "$1" in
    start)
        start-stop-daemon -n aesdsocket -a /usr/bin/aesdsocket -S -- -d 
        ;;
    stop)
        start-stop-daemon -K -n aesdsocket
        ;;
    *)
        echo "Usage: $0 {start|stop}"
    exit 1
esac

exit 0