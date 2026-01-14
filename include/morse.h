#pragma once
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define UNIT_MS(wpm) (1200.0 / (wpm)) // Unité pour X WPM

static const double TIME_UNIT     = UNIT_MS(20);
static const double DOT           = TIME_UNIT;
static const double DASH          = TIME_UNIT * 3;
static const double SYMBOLE_SPACE = TIME_UNIT;
static const double LETTER_SPACE  = TIME_UNIT * 3;
static const double WORD_SPACE    = TIME_UNIT * 7;

static const double TOLERENCE     = 10;

/*
20 WPM -> une unité = 60ms
Point = 60 ms -> u*1 (Court)
Trait = 180 ms -> u*3 (Long)
Espace entre symbole = 60ms u*1
Espace entre lettres = 180 ms u*3 
Espace entre mots = 420 ms u*7
*/

typedef struct {
    char letter;
    const char *morse;
} MorseEntry;

static const MorseEntry morseTable[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
    {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'\'', ".----."}, {'!', "-.-.--"},
    {'/', "-..-."}, {'(', "-.--."}, {')', "-.--.-"}, {'&', ".-..."}, {':', "---..."},
    {';', "-.-.-."}, {'=', "-...-"}, {'+', ".-.-."}, {'-', "-....-"}, {'_', "..--.-"},
    {'"', ".-..-."}, {'$', "...-..-"}, {'@', ".--.-."}
};

static const size_t CARACTERES_COUNT = sizeof(morseTable)/sizeof(MorseEntry);