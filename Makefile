all:
	particle compile photon .
flash:
	particle flash 200026000f47343432313031 .
clean:
	rm *.bin
