/**
 * @file songs.h
 * @brief Defines musical note frequencies, the Song data structure, and
 *        predefined song melodies for the Adaptive Music Player.
 *
 * This file contains:
 * - Constants for musical note frequencies (in Hertz)
 * - The `Song` struct used for holding melody and duration data
 * - Several predefined songs with extended versions (~30 seconds each)
 * - A global song collection array for sequential access
 *
 * These definitions are intended for microcontroller music playback systems
 * using PWM or tone-generation libraries. Notes are represented as integer
 * frequencies, while durations are stored in milliseconds.
 */

#ifndef SONGS_H
#define SONGS_H

// ============================================================================
// NOTE FREQUENCIES (Hz)
// ============================================================================
/**
 * @name Musical Note Frequency Constants
 * @brief Standard equal-tempered scale note frequencies.
 * @{
 */
#define C4  262
#define Cs4 277
#define D4  294
#define Ds4 311
#define E4  330
#define F4  349
#define Fs4 370
#define G4  392
#define Gs4 415
#define A4  440
#define As4 466
#define B4  494
#define C5  523
#define Cs5 554
#define D5  587
#define Ds5 622
#define E5  659
#define F5  698
#define Fs5 740
#define G5  784
#define Gs5 831
#define A5  880
#define As5 932
#define B5  988
#define C6  1047
#define REST 0 ///< Represents a pause or silence in the melody
/** @} */


// ============================================================================
// SONG DATA STRUCTURE
// ============================================================================
/**
 * @struct Song
 * @brief Represents a musical composition consisting of notes and durations.
 *
 * The melody is an array of integer note frequencies (Hz).
 * Durations are specified in milliseconds and correspond 1:1 with melody entries.
 */
struct Song {
    const char* name;     ///< Human-readable song title
    int* melody;          ///< Pointer to array of note frequencies
    int* durations;       ///< Pointer to array of note durations in milliseconds
    int length;           ///< Number of elements in melody/durations arrays
};


// ============================================================================
// SONG ARRAYS
// ============================================================================

/**
 * @brief Melody and durations for *Happy Birthday* (extended version).
 */
int HBDMelody[] = {
    G4,G4,A4,G4,C5,B4,  G4,G4,A4,G4,D5,C5,  G4,G4,G5,E5,C5,B4,A4,  F5,F5,E5,C5,D5,C5,
    G4,G4,A4,G4,C5,B4,  G4,G4,A4,G4,D5,C5,  G4,G4,G5,E5,C5,B4,A4,  F5,F5,E5,C5,D5,C5
};
int HBDDurations[] = {
    250,250,500,500,500,1000,  250,250,500,500,500,1000,  250,250,500,500,500,500,1000,  250,250,500,500,500,1000,
    250,250,500,500,500,1000,  250,250,500,500,500,1000,  250,250,500,500,500,500,1000,  250,250,500,500,500,1000
};


/**
 * @brief Melody and durations for *Jingle Bells* (extended version).
 */
int jingleMelody[] = {
    E5,E5,E5,REST, E5,E5,E5,REST, E5,G5,C5,D5,E5,REST,
    F5,F5,F5,F5, F5,E5,E5,E5,E5, E5,D5,D5,E5,D5,REST,G5,REST,
    E5,E5,E5,REST, E5,E5,E5,REST, E5,G5,C5,D5,E5,REST,
    F5,F5,F5,F5, F5,E5,E5,E5,E5, G5,G5,F5,D5,C5,REST
};
int jingleDurations[] = {
    250,250,500,250, 250,250,500,250, 250,250,250,250,750,250,
    250,250,250,250, 250,250,250,250,250, 250,250,250,250,500,250,500,250,
    250,250,500,250, 250,250,500,250, 250,250,250,250,750,250,
    250,250,250,250, 250,250,250,250,250, 250,250,250,250,750,250
};


/**
 * @brief Melody and durations for *We Wish You a Merry Christmas* (extended).
 */
int merryMelody[] = {
    D4,G4,G4,A4,G4,Fs4, E4,E4,E4, A4,A4,B4,A4,G4, Fs4,Fs4,Fs4, B4,B4,C5,B4,A4, G4,E4,D4,D4,E4,A4,Fs4,G4,REST,
    D4,G4,G4,A4,G4,Fs4, E4,E4,E4, A4,A4,B4,A4,G4, Fs4,Fs4,Fs4, B4,B4,C5,B4,A4, G4,E4,D4,D4,E4,A4,Fs4,G4,REST
};
int merryDurations[] = {
    300,300,200,300,300,300, 300,300,600, 300,300,200,300,300,300, 300,300,600, 
    300,300,200,300,300,300, 300,300,300,300,300,300,300,900,250,
    300,300,200,300,300,300, 300,300,600, 300,300,200,300,300,300, 300,300,600, 
    300,300,200,300,300,300, 300,300,300,300,300,300,300,900,250
};


/**
 * @brief Melody and durations for *Silent Night* (extended version).
 */
int silentMelody[] = {
    G4,A4,G4,E4,REST,G4,A4,G4,E4,REST,
    D5,D5,B4,REST,C5,C5,G4,REST,
    A4,A4,C5,B4,A4,REST,G4,A4,G4,E4,REST,
    A4,A4,C5,B4,A4,REST,G4,A4,G4,E4,REST,
    D5,D5,F5,D5,B4,REST,C5,E5,C5,G4,E4,G4,F4,D4,C4,REST
};
int silentDurations[] = {
    500,250,250,1000,250,500,250,250,1000,250,
    500,500,1000,250,500,500,1000,250,
    500,500,250,250,500,250,500,250,250,1000,250,
    500,500,250,250,500,250,500,250,250,1000,250,
    500,500,250,250,1000,250,500,250,250,500,250,250,250,250,1000,250
};


/**
 * @brief Melody and durations for *Deck the Halls* (extended version).
 */
int deckMelody[] = {
    G4,F4,E4,D4,C4,D4,E4,C4, D4,E4,F4,D4,E4,REST,
    G4,F4,E4,D4,C4,D4,E4,C4, D4,D4,C4,B4,C4,REST,
    E4,E4,F4,E4,D4,C4,D4,REST, E4,E4,F4,E4,D4,REST,
    G4,F4,E4,D4,C4,D4,E4,C4, D4,D4,C4,B4,C4,REST,
    G4,F4,E4,D4,C4,D4,E4,C4, D4,E4,F4,D4,E4,REST
};
int deckDurations[] = {
    300,200,300,300,300,300,300,600, 300,300,300,300,900,250,
    300,200,300,300,300,300,300,600, 300,300,300,300,900,250,
    300,300,200,300,300,300,900,250, 300,300,200,300,900,250,
    300,200,300,300,300,300,300,600, 300,300,300,300,900,250,
    300,200,300,300,300,300,300,600, 300,300,300,300,900,250
};


// ============================================================================
// SONG COLLECTION
// ============================================================================

/**
 * @brief Total number of songs defined in this file.
 */
const int TOTAL_SONGS = 5;

/**
 * @brief Array of all available songs for the Adaptive Music Player.
 */
const Song songs[TOTAL_SONGS] = {
    {"Happy Birthday", HBDMelody, HBDDurations, sizeof(HBDMelody)/sizeof(int)},
    {"Jingle Bells", jingleMelody, jingleDurations, sizeof(jingleMelody)/sizeof(int)},
    {"Merry Xmas", merryMelody, merryDurations, sizeof(merryMelody)/sizeof(int)},
    {"Silent Night", silentMelody, silentDurations, sizeof(silentDurations)/sizeof(int)},
    {"Deck the Halls", deckMelody, deckDurations, sizeof(deckMelody)/sizeof(int)}
};

#endif // SONGS_H
