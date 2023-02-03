# get_next_line

## Definition of Variables
- char buffer[BUFFER_SIZE]: stores texts after the read function.  
- static char *save: if '\n' is in the buffer, then the rest of the characters are copied to the save.
- result: a string to return.

## How to work
### check save
- if the 'save' is NULL, read the 'buffer size' in the text and the result to the 'buffer'.
- else if the 'save' isn't NULL, you have to move the data in the 'save' to the 'buffer', and the 'save' set to NULL.

### find '\n' in the buffer
- Find '\n' in the buffer
- If '\n' in the buffer
    - the former append to the 'result'
        : [0th] index to the [index of '\n']
    - the others to the save 
        : [index + 1] to the [BUFFER_SIZE - 1]
    - return 'result'
- If '\n' is not in the buffer
    - entire 'buffer' copy to the 'result'
    - until you find the '\n', read the text.

## exception: return NULL
- if the read failed: return value of read is -1 or 0
- fd value error: fd < 0

## Help Functions
- find_char : function for finding the index of '\n', if not return -1
- append_buffer: after the 'result' of 'save', append a part of the 'buffer'