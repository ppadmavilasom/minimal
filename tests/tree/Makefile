build: tree_height tree_inorder

tree_height: tree.c height.c
	cc -g tree.c height.c -Werror -o tree_height

tree_inorder: tree.c inorder.c
	cc -g tree.c inorder.c -Werror -o tree_inorder

memcheck: check_valgrind
	valgrind -q --leak-check=full \
	--errors-for-leak-kinds=definite \
	--error-exitcode=1 ./tree_inorder 5 6 7 8 1 2 3 4

check_valgrind:
	@command -v valgrind >/dev/null 2>&1 || { echo "valgrind required." >&2; exit 1; }	

check: build memcheck
	./tree_inorder 1 | grep 1
	./tree_inorder 4 3 2 1 | grep "1 2 3 4"
	./tree_inorder 9 1 8 2 7 3 | grep "1 2 3 7 8 9"
	./tree_height 1 | grep "1"
	./tree_height 7 10 5 | grep "2"
	./tree_height 4 3 2 1 | grep "4"

clean:
	-rm tree_height tree_inorder
