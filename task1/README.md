## Investigation of endianness (big/little endian).

> **Note:** I did not use any AI tools for my investigation of the Endianness concept. I actually find this task valuable because I miss the days when we used to use Google to search for things ourselves. I will cite the sources I used throughout my report.

## 1. Introduction
Computers speak the language of 0s and 1s. When those 0s and 1s are put together in the computer's memory, they have a specific meaning. The question is, how do we decide the specific way to put these 0s and 1s together? This ordering is pretty important because computer memory stores multi byte values sequentially. The idea of a multi byte value basically means a value whose representation requires more than 1 byte of storage space. Computer memory, particularly RAM, can be thought of as an array of individually addressable bytes. When we want to store a value that requires more than one byte, we have to split it into 1 byte parts and put those parts sequentially in memory. The question arises: **in which order?** The answer to this question is exactly what the concept of endianness solves. This concept is quite important in Computer Architecture and Programming. Endianness directly affects how multi byte data is represented in memory, how binary data is exchanged between systems, and how software processes low level binary data.

## 2. What Is Endianness?
As we said earlier Endianness solves the problem of deciding how to order bytes in computer's memory. But this definition alone is not precise enough for such a concept. Let us investigate it a bit more in detail. If the following details seem so much detailed to you you can kindly skip. I decided to explain the concept in detail so that I can see where does the problem come from first then to investigate it much in detail. 

What is byte? Byte is addressable unit of data storage large enough to hold any member of the basic character set of the execution environment. ([Programming languages — C](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3088.pdf)). This is a bit technical definition for a byte. If we have to simplify it, we can say a byte is the basic unit of digital information in computers, made up of eight smaller units called bits. As we mentioned earlier some information requires more memory storage, more than a byte or 8 bits, in computers memory. At this point the value is split across 8 bits and put in a specific order sequentially, in Big Endian order or Little endian order. I want to mention a small note. While searching on google i saw several discussion made around whether Endianness describe the ordering of bytes or bits. Endianness deals with the ordering of bytes, bits within a single byte are handled consistently by the memory architecture's byte-addressing scheme.  

**Big Endian vs Little Endian**- In a big-endian system, the most significant byte (MSB) is placed at the lowest memory address, while in Little Endian system the least significant byte (LSB) is placed at the lowest memory address. I want to follow a specific example to explain it rather than sinking in technical terminology. Let's take a specific example: <mark>0x12345678</mark>

## 3. How Is a Multi Byte Value Represented in Memory?

## 4. Big Endian vs Little Endian

## 5. What Endianness Does and Does Not Change

## 6. Why Does Endianness Matter?

## 7. Is "Big Endian vs Little Endian" Always That Simple?

## 8. Critical Analysis

## 9. Conclusion

## References
