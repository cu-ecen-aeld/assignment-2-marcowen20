default:
ifeq ($(CROSS_COMPILE),)
	gcc writer.c -o writer
else
	$(CROSS_COMPILE)gcc writer.c -o writer
endif

clean:
	rm writer -f *.o