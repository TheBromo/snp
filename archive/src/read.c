/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule W#defineerthur -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 W#defineerthur, Switzerland -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// begin students to add code for task 4.1
// end of input
#define EOL 10 // end of line
// abnormal return values
#define PARSE_ERROR -1
#define READ_ERROR -2
// ASCII Codes
#define ASCII_SPACE 32   // ' '
#define ASCII_DIGIT_0 48 // '0'
#define ASCII_DIGIT_9 57 // '9'

// conversion buffer
#define NO_POS -1
#define BUFFERSIZE 10
// end students to add code

int getInt(int maxResult) {
  char buffer[BUFFERSIZE];
  int result = 0;
  fgets(buffer, BUFFERSIZE, stdin);

  // read line: up to EOL or EOF (i.e. error while reading)
  int bytes = 0;
  int input = atoi(buffer);
  while ((input != EOL) && (input != EOF)) { // read whole line
    if (bytes < BUFFERSIZE) {                // only buffer first n characters
      buffer[bytes] = (char)input;
      bytes++;
    } else {
      result = PARSE_ERROR; // exceed buffer size, continue read line
    }
    fgets(buffer, BUFFERSIZE, stdin);
    input = atoi(buffer);
  }
  if (input == EOF) {
    result = READ_ERROR;
  }
  // check for numbers: skip leading and trailing spaces
  // (i.e. this includes all control chars below the space ASCII code)
  int pos = 0;
  while ((pos < bytes) && (buffer[pos] <= ASCII_SPACE))
    pos++; // skip SP
  int posOfFirstDigit = pos;
  int posOfLastDigit = NO_POS;
  while ((pos < bytes) && (buffer[pos] >= ASCII_DIGIT_0) &&
         (buffer[pos] <= ASCII_DIGIT_9)) {
    posOfLastDigit = pos;
    pos++;
  }
  while ((pos < bytes) && (buffer[pos] <= ASCII_SPACE))
    pos++; // skip SP
  // produce return value
  if (result != 0) {
    // previously detected read or parse error given
  } else if ((pos != bytes) || (posOfLastDigit == NO_POS)) {
    result = PARSE_ERROR;
  } else { // convert number
    for (int i = posOfFirstDigit; i <= posOfLastDigit; i++) {
      result = result * 10 + (buffer[i] - ASCII_DIGIT_0);
      if (result > maxResult) {
        result = PARSE_ERROR;
        break;
      }
    }
  }
  return result;
}
