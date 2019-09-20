/*
 Problem code: P02PackChar
 Score: 20
 
 Kiran got exited when he heard that, the latest operating system when it needs to swap memory
 between RAM and Hard Disk, it begin compressing memory that is marked as inactive. And loads
 the required block of memory from disk into the newly created empty space in RAM.
 The concept of storing the same information in less amount of memory using compression
 techniques intrigued him.
 
 Kiran also recently came across anatomy of typography article, how the fonts are
 designed to make the text easy to read.
 Article: https://www.canva.com/learn/typography-terms/
 
 For experimenting purpose Kiran came up with a lossy compression technique, like:
 1. The input stream of characters contain, small case a-z, space and full stop only.
 2. In the letters a-z, he separated characters which completely fit in X-Height.
    which are "acemnorsuvwxz", calling them X-Char-Set.
 3. Leaving the full stop and space from the stream as they are,
    for every character which is not in X-Char-Set,
    he replaced it with the closest character in X-Char-Set.
 4. Mapping of the resulting steam is done like this
    Each character in this set "acemnorsuvwxz" is assigned codes like this
    ----------------------------------------------------------
    a c e m n o r s u  v  w  x  z  .  ' ' // last one is space
    1 2 3 4 5 6 7 8 9 10 11 12 13 14  15
    ----------------------------------------------------------
 5. For the resulting stream, using these codes, he packed each character in 4-bits.
 6. Needed padding bits of 0's are added to keep the resulting stream size in multiple of 2 bytes.
 
 Examples:
 
 Input:
 "abc ef."
 
 Output:
 {4, {17, 47, 51, 224}}
 
 Details:
 
 replacing characters {'b', 'f'} not in X-Char-Set
 "abc ef." after replacing 'b' -> 'a' and 'f'->'e' will result in
 "aac ee."
 
 char 'b' has 'a' and 'c' in X-Char-Set at equal distance,
 so using left side char 'a' for replacement.
 
 packing each character using the codes.
 "aac ee." => {0x11, 0x2f, 0x33, 0xe0}
 
 Codes:
 a - 1, c - 2, e - 3,
 ' ' - 0xf
 . - 0xe // full stop
 
 Padding:
 result must be multiple of 2 bytes so adding padding of 4 bits of 0's.
 
 i.e: {4, {0x11, 0x2f, 0x33, 0xe0}}
 which is equal to {4, {17, 47, 51, 224}}

References:
 X-Height: The height of a typeface’s lowercase letters (disregarding ascenders and descenders).
 Check the 9th, 17th and 18th words in https://www.canva.com/learn/typography-terms/
 
Constraints:
 - The text contains space, full stop and all small letters a-z only.
 - Each character must be packed in 4-bits.
 - You need to add necessary padding (bits of 0's).
 - The final size must in the multiple of 2 bytes.
 - When two characters are at same distance, use the character on the left side.
 
 
Note:
    Blob type is defined in Functions.h

    like this:

    typedef struct {
        int length;
        unsigned char *bytes;
    } Blob;
*/

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

Blob *map_and_pack(char *sentence) {
    return NULL;
}

