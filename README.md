# RLE-Codec
Compression and Decompression of byte data using RLE codec algorithm.

RLE Compression -> Used to compress series of similar bytes to their number and respective byte data.
Step1 : Parse the header and read the byte data.
Step2 : Read 3 datas ahead to switch on marker or not.
Step3 : Switch on marker(in this case it is byte 00) if the data is not equal.
        Else, increment count and continue.
Step4 : When not equal,turn marker off if on and output the count and corresponding byte.
Step5 : Read till end and write compressed file.

RLE Decompression -> Extract byte data and their count to decompress.
Step1 : Check if marker is on or not.
Step2 : If on, display as it is.
        Else, take count and byte data to continuosly write data.
Step3 : Read, till end and write decompressed file.
