#pragma once
#include <stdio.h>
#include <ctype.h>
#include <string.h>

static const int UNITE_TEMPS = 60;
/*
20 WPM -> une nité = 60ms
Point = 60 ms -> u*1 (Court)
Trait = 180 ms -> u*3 (Long)
Espace entre symbole = 60ms u*1
Espace entre lettres = 180 ms u*3 
Espace entre mots = 420 ms u*7
*/

// Enumération pour lettres, chiffres et ponctuation courante
typedef enum {
    A, B, C, D, E, F, G, H, I, J,
    K, L, M, N, O, P, Q, R, S, T,
    U, V, W, X, Y, Z,
    ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF,
    POINT, VIRGULE, QUESTION, APOSTROPHE, EXCLAMATION,
    SLASH, PARENTHESE_OUV, PARENTHESE_FERM, ET, DEUX_POINTS,
    POINT_VIRGULE, EGAL, PLUS, MOINS, UNDERSCORE, GUILLEMET, DOLLAR, ARROBASE,
    NB_CARACTERES
} Caractere;

// Tableau associant chaque caractère à son code Morse officiel
static const char* morseCode[NB_CARACTERES] = {
    // Lettres
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    // Chiffres
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
    // Ponctuation
    ".-.-.-", "--..--", "..--..", ".----.", "-.-.--",
    "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-."
};

