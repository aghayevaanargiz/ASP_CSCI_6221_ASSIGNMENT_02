## Investigation of endianness (big/little endian).

> **Note:** I did not use any AI tools for my investigation of the Endianness concept. I actually find this task valuable because I miss the days when we used to use Google to search for things ourselves. I will cite the sources I used throughout my report.

## 1. Introduction
Computers speak the language of 0s and 1s. When those 0s and 1s are put together in the computer's memory, they have a specific meaning. The question is, how do we decide the specific way to put these 0s and 1s together? This ordering is pretty important because computer memory stores multi byte values sequentially. The idea of a multi byte value basically means a value whose representation requires more than 1 byte of storage space. Computer memory, particularly RAM, can be thought of as an array of individually addressable bytes. When we want to store a value that requires more than one byte, we have to split it into 1 byte parts and put those parts sequentially in memory. The question arises: **in which order?** The answer to this question is exactly what the concept of endianness solves. This concept is quite important in Computer Architecture and Programming. Endianness directly affects how multi byte data is represented in memory, how binary data is exchanged between systems, and how software processes low level binary data.

## 2. What Is Endianness?

As we said earlier, Endianness solves the problem of deciding how to order bytes in computer memory. But this definition alone is not precise enough for such a concept. Let us investigate it a bit more in detail. If the following details seem too much, you can kindly skip them. I decided to explain the concept in detail so that I can first see where the problem comes from and then investigate it more deeply.

### What is a byte?

A byte is an addressable unit of data storage large enough to hold any member of the basic character set of the execution environment ([Programming languages, C](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3088.pdf)). This is a bit technical definition for a byte. If we have to simplify it, we can say that a byte is a basic unit of digital information in computers, made up of eight smaller units called bits.

As we mentioned earlier, some information requires more memory storage, more than one byte, in computer memory. At this point, the value is split into 1 byte parts and these bytes have to be placed sequentially in memory. The question is, in which order? This is where Big Endian and Little Endian come into the picture.

I want to mention a small note here. While searching on Google, I saw several discussions about whether Endianness describes the ordering of bytes or bits. Endianness deals with the ordering of bytes in a multi byte value. It should not be confused with the ordering of individual bits within a byte.

### Big Endian vs Little Endian

In a Big Endian system, the most significant byte is placed at the lowest memory address, while in a Little Endian system, the least significant byte is placed at the lowest memory address ([Programming languages, C](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3088.pdf)).

I want to follow a specific example to explain it rather than sinking in technical terminology. Let's take a specific example:

<mark>0x12345678</mark>

Breaking the value into parts, we get:

<mark>0x12  0x34  0x56  0x78</mark>

For this example, as you can see, we need 4 bytes to store this value. The concept of Most Significant Byte (MSB) refers to the highest order byte, or in other words, the byte that contributes the most to the overall value. LSB is the opposite. An intuitive example given by [What is Endianness? Big Endian & Little Endian](https://www.geeksforgeeks.org/dsa/little-and-big-endian-mystery/) is quite helpful here. It basically says that in the number 2,984, changing 4 to 5 increases the number by 1, while changing 2 to 3 increases the number by 1000. In our example, 0x12 is therefore the most significant byte.

For a Big Endian system, the memory storage for our example would be something like below:

| Address | Byte |
|---------|------|
| 1000    | 12   |
| 1001    | 34   |
| 1002    | 56   |
| 1003    | 78   |

As you can observe, the most significant byte, 0x12, is placed at the lowest memory address, 1000. This is exactly how Big Endian works.

The same value in a Little Endian system would look as follows. The least significant byte is placed at the lowest memory address.

| Address | Byte |
|---------|------|
| 1000    | 78   |
| 1001    | 56   |
| 1002    | 34   |
| 1003    | 12   |

At this point, an interesting question came to my mind. **If both systems do not change the value itself, then why do we have two of them? Can we not agree on one system only and use that? For example, Big Endian**.

I was searching for a reading that answers this question and found a very interesting one, [On Holy Wars and a Plea for Peace](https://gwern.net/doc/cs/algorithm/1981-cohen.pdf), written by Danny Cohen. He explains the situation in a way that I found particularly interesting.

Cohen explains that the two approaches emerged partly because there were different ways of thinking about how numbers should be arranged. Big Endian thinking was influenced by the way numbers and written language are normally presented from left to right. Little Endian thinking, on the other hand, placed more emphasis on numerical significance and the relationship between significance and increasing memory addresses.

> **Cohen:** *English, like most modern languages, suggests that we arrange computer words from left to right... The convention introduced by our numbering system places the wide end on the left and the narrow end on the right.*

> **Cohen:** *They believe in starting with the narrow end of every word and that low addresses are of lower order than high addresses... This order is consistent with itself, with the Hebrew language, and (more importantly) with mathematics, because significance increases with increasing item numbers (address).*

Cohen also answers another question I had, which is, "Can we not agree on one system and use that?" He says, *"Both camps have adopted the slogan 'We'd rather fight than switch!' I believe they mean it."* Here, as I understand the concept, he means that once different groups and industries have built systems around different conventions, changing to one common convention becomes difficult and costly.

The reading itself gives a more rigorous historical viewpoint on the emergence of both approaches. Cohen explains that early communication systems, such as RS 232, Telex, HDLC, SDLC, and several communication chips, were built around sending the least significant bit first. At the same time, mainframe and computer designers had reasons to favor different forms of word alignment. This shows that the emergence of two approaches was not simply a matter of people choosing whichever order they personally liked. Different technical systems had already developed around different conventions.

### My Critical View

After investigating the concept, I think the existence of both Big Endian and Little Endian can be understood from two different perspectives. The first one is the difference between human conventions for representing numbers and the way numerical significance can be related to memory addresses. The second one is more practical. Different areas of computing developed their own conventions because those conventions were useful or convenient for the systems they were building.

Therefore, I would not say that one side was simply correct and the other side was wrong. The important point is that once a particular byte order becomes part of an architecture, communication protocol, file format, or other system, changing it is no longer a simple decision. Existing hardware and software have already been built around that convention.

This also changed my initial view of the problem. At first, I thought that if both systems represent exactly the same value, there should be no reason to have two different systems. After investigating the historical and technical reasons, I think the real problem is not that one representation is better than the other. The bigger problem is **agreement**. As long as different systems use different conventions, they need to know which convention is being used when exchanging or interpreting multi byte data.


## References
[Programming languages, C](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3088.pdf)

[Programming languages, C](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3088.pdf)

[On Holy Wars and a Plea for Peace](https://gwern.net/doc/cs/algorithm/1981-cohen.pdf)

