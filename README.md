CSC 4553 Intro to Operating Systems -- Lab 0
Sahib Bhalrhu

Part 0 Q1: After following the execution of the program, I have a better understanding of where exactly to look out for parent-child differences. Seeing how not flushing results in this overflow to stdout and how it must be explicitly addressed. 

Part 1 Q1: The output would see parentchild on almost every line for every variant except printf without any flush (childparent). This is because printf will write a larger buffer to stdout to save resources, but write will send data straight to stdout, and flushing after printf clears the buffer.

Part1 Q2: Adding a 0.1s sleep seemed to increase the frequency of childparent but the output was still almost entirely parentchild. A 1s sleep dramatically reduced the speed of the output but it was similar to the 0.1s sleep variant.