#
#
########################################
# This connects to a GDB Server listening
# for commands on localhost at tcp port 2331
target remote dev.lagerdata.app:2159
########################################


########################################

########################################





########################################
# Reset the chip to get to a known state.
monitor reset halt



########################################


# Load the program executable called "image.elf"
file ./_build/test/test_suite_mpu9250_drv/blue42_test_mpu9250_drv


set breakpoint pending on

load
break main
