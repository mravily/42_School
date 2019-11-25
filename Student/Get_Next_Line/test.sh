i=1
while ((i <= 2001))
	do
	echo "BUFFER_SIZE = $i"
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c main.c
	for doc in 'text3.txt'
	do
	touch lol.txt
	./a.out $doc > lol.txt
	diff $doc lol.txt
	rm lol.txt
	done
	echo ======================================================================
	((i+=8))
	done