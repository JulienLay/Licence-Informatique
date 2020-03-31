#/!bin/sh
ghdl -a $1
ghdl -a $2
ghdl -e test
./test --vcd=test.vcd
gtkwave test.vcd &
