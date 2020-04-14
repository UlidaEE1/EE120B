# Test file for "lab2"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0x0F , PINB: 0x0F , PINC: 0X0F => PORTD: 0x2A "
# Set inputs
setPINA 0x0F
setPINB 0x0F
setPINC 0x0F
# Continue for several ticks
continue 1
# Set expect values
expectPORTD 0x2C
# Check pass/fail
checkResult


test "PINA: 0x32 PINB: 0x32 , PINC:0x32 => PORTD: 0x96"
setPINA 0x32
setPINB 0x32
setPINC 0x32
continue 1
expectPORTD 0x95
checkResult

test "PINA: 0x80 PINB: 0x08 , PINC:0X00 => PORTD: 0x8A"
setPINA 0x80
setPINB 0x08
setPINC 0x00
continue 1
expectPORTD 0x8A
checkResult


# Add tests below

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
