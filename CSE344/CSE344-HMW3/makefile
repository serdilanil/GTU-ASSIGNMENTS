SEMAPHORE = "wholeSaler_wait" "mutex" "s_cf0" "s_cf1" "s_cf2" "s_cf3" "s_cf4" "s_cf5" "s_milk" "s_sugar" "s_walnuts" "s_flour"

compile: named.c unnamed.c
		gcc -Wall -o named named.c -pthread -lrt && gcc -Wall -o unnamed unnamed.c -pthread -lrt

named:  
	 	gcc -Wall -o named named.c -pthread -lrt && ./named -i 'input.txt' -n $(SEMAPHORE)

unnamed:
		 gcc -Wall -o unnamed unnamed.c -pthread -lrt && ./unnamed -i 'input.txt'

.PHONY: named unnamed compile