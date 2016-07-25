all:
	particle compile photon .
flash:
	# 200026000f47343432313031 , pilot
	# 1a002e001847353236343033 , unison
	# 20002d000b47353235303037 , vandalism
	particle flash 1a002e001847353236343033 . # unison
clean:
	rm *.bin
