MAIN	= hexDecode
SOURCE	= $(MAIN).cpp
OBJECT	= $(MAIN).o
CC		= clang++

$(MAIN):	$(MAIN).o
	$(CC) -o $(MAIN) $(OBJECT)


clean:
	rm -f $(MAIN) $(OBJECT)
