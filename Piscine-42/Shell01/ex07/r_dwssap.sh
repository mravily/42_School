cat /etc/passwd | grep -v '#' | sed -n "n;p" | cut -d ':' -f1 | rev | sort -rd | sed -n "$FT_LINE1","$FT_LINE2"p | tr "\n" "," | sed -e "s/,/, /g" | sed -e "s/..$/./g" | tr -d "\n"
