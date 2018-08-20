#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

char encodeNote(int octave, char noteLetter, char accidentalSign);
bool hasCorrectSyntax(string song);
int encodeSong(string song, string& instructions, int& badBeat);
bool isLetter(char letter);
bool isAccidental(char acc);
bool isNote(string note);
bool isPlayable(string song);
bool isPlayableNote(string note);


void testone(int n)
{
    string ins = "";
    int bb = 0;
    switch (n)
    {
        default: {
            cout << "Bad argument" << endl;
        } break; case  1: {
            assert(hasCorrectSyntax(""));
        } break; case  2: {
            assert(!hasCorrectSyntax("C"));
        } break; case  3: {
            assert(!hasCorrectSyntax("#"));
        } break; case  4: {
            assert(!hasCorrectSyntax("3"));
        } break; case  5: {
            assert(hasCorrectSyntax("/"));
        } break; case  6: {
            assert(hasCorrectSyntax("A/"));
        } break; case  7: {
            assert(hasCorrectSyntax("B/"));
            assert(hasCorrectSyntax("C/"));
            assert(hasCorrectSyntax("D/"));
            assert(hasCorrectSyntax("E/"));
            assert(hasCorrectSyntax("F/"));
        } break; case  8: {
            assert(hasCorrectSyntax("G/"));
        } break; case  9: {
            assert(!hasCorrectSyntax("H/"));
        } break; case 10: {
            assert(!hasCorrectSyntax("e/"));
        } break; case 11: {
            assert(!hasCorrectSyntax("#/"));
        } break; case 12: {
            assert(!hasCorrectSyntax("5/"));
        } break; case 13: {
            assert(!hasCorrectSyntax("#5/"));
        } break; case 14: {
            assert(!hasCorrectSyntax("C#"));
        } break; case 15: {
            assert(!hasCorrectSyntax("C5"));
        } break; case 16: {
            assert(!hasCorrectSyntax("C#5"));
        } break; case 17: {
            assert(!hasCorrectSyntax("C5#/"));
        } break; case 18: {
            assert(hasCorrectSyntax("C#/"));
        } break; case 19: {
            assert(hasCorrectSyntax("Db/"));
        } break; case 20: {
            assert(hasCorrectSyntax("C3/"));
        } break; case 21: {
            assert(hasCorrectSyntax("C#3/"));
        } break; case 22: {
            assert(!hasCorrectSyntax("C34/"));
        } break; case 23: {
            assert(!hasCorrectSyntax("C#34/"));
        } break; case 24: {
            assert(!hasCorrectSyntax("C#b/"));
        } break; case 25: {
            assert(hasCorrectSyntax("C0/"));
            assert(hasCorrectSyntax("D1/"));
        } break; case 26: {
            assert(hasCorrectSyntax("B9/"));
            assert(hasCorrectSyntax("B#9/"));
            assert(hasCorrectSyntax("Cb0/"));
        } break; case 27: {
            assert(hasCorrectSyntax("//"));
        } break; case 28: {
            assert(hasCorrectSyntax("C//"));
        } break; case 29: {
            assert(hasCorrectSyntax("/C/"));
        } break; case 30: {
            assert(hasCorrectSyntax("C/C/"));
        } break; case 31: {
            assert(hasCorrectSyntax("C#/C/"));
        } break; case 32: {
            assert(hasCorrectSyntax("C/C3/"));
        } break; case 33: {
            assert(hasCorrectSyntax("C#4/Eb5/"));
        } break; case 34: {
            assert(!hasCorrectSyntax("C/E"));
        } break; case 35: {
            assert(!hasCorrectSyntax("C#5/E5b/"));
        } break; case 36: {
            assert(!hasCorrectSyntax("C#5/#/"));
        } break; case 37: {
            assert(hasCorrectSyntax("////"));
        } break; case 38: {
            assert(hasCorrectSyntax("//C/D/E/F///F/E//D/C/"));
        } break; case 39: {
            assert(!hasCorrectSyntax("C/C/D/E/F/F/E/D/C/3/E/F/"));
        } break; case 40: {
            assert(hasCorrectSyntax("CD/"));
        } break; case 41: {
            assert(hasCorrectSyntax("C#D/"));
        } break; case 42: {
            assert(hasCorrectSyntax("C#3D/"));
        } break; case 43: {
            assert(hasCorrectSyntax("C3D/"));
        } break; case 44: {
            assert(hasCorrectSyntax("CD#/"));
        } break; case 45: {
            assert(hasCorrectSyntax("CD#3/"));
        } break; case 46: {
            assert(hasCorrectSyntax("CD3/"));
        } break; case 47: {
            assert(hasCorrectSyntax("C#D3/"));
        } break; case 48: {
            assert(hasCorrectSyntax("C#4D#5/"));
        } break; case 49: {
            assert(!hasCorrectSyntax("CD5#/"));
        } break; case 50: {
            assert(!hasCorrectSyntax("C#D#H/"));
        } break; case 51: {
            assert(!hasCorrectSyntax("C#4#/"));
        } break; case 52: {
            assert(!hasCorrectSyntax("C#43D#5/"));
        } break; case 53: {
            assert(hasCorrectSyntax("A3C#E//E//F#3A3D4/A3C#E/"));
        } break; case 54: {
            assert(hasCorrectSyntax("C0C0DC0DD/E#FbB#Cb/B#9/"));
        } break; case 55: {
            assert(hasCorrectSyntax("G3B3DD5//G/A/A3B/C5/B3D5//G//G//CE5//C5/D5/E5/F#5/B3G5//G//G/"));
        } break; case 56: {
            assert(hasCorrectSyntax("DADDA/"));
        } break; case 57: {
            assert(encodeSong("", ins, bb) == 0);
        } break; case 58: {
            encodeSong("", ins, bb);
            assert(ins == "");
        } break; case 59: {
            bb = 666;
            encodeSong("", ins, bb);
            assert(bb == 666);
        } break; case 60: {
            assert(encodeSong("/", ins, bb) == 0);
        } break; case 61: {
            assert(encodeSong("/", ins, bb) == 0);
            assert(ins == " ");
        } break; case 62: {
            bb = 666;
            encodeSong("/", ins, bb);
            assert(bb == 666);
        } break; case 63: {
            assert(encodeSong("G/", ins, bb) == 0);
        } break; case 64: {
            ins = "@@@";
            encodeSong("G/", ins, bb);
            assert(ins == "L");
        } break; case 65: {
            bb = 666;
            encodeSong("G/", ins, bb);
            assert(bb == 666);
        } break; case 66: {
            assert(encodeSong("G#/", ins, bb) == 0  &&  ins == "$");
        } break; case 67: {
            assert(encodeSong("Gb/", ins, bb) == 0  &&  ins == "#");
        } break; case 68: {
            assert(encodeSong("G3/", ins, bb) == 0  &&  ins == "S");
        } break; case 69: {
            assert(encodeSong("G#3/", ins, bb) == 0  &&  ins == "9");
        } break; case 70: {
            assert(encodeSong("B#1/", ins, bb) == 0  &&  ins == "Z");
        } break; case 71: {
            assert(encodeSong("C2/", ins, bb) == 0  &&  ins == "Z");
        } break; case 72: {
            assert(encodeSong("B5/", ins, bb) == 0  &&  ins == "O");
        } break; case 73: {
            assert(encodeSong("Cb6/", ins, bb) == 0  &&  ins == "O");
        } break; case 74: {
            assert(encodeSong("B#5/", ins, bb) == 0  &&  ins == "P");
        } break; case 75: {
            assert(encodeSong("C6/", ins, bb) == 0  &&  ins == "P");
        } break; case 76: {
            assert(encodeSong("//", ins, bb) == 0  &&  ins == "  ");
        } break; case 77: {
            assert(encodeSong("G//", ins, bb) == 0  &&  ins == "L ");
        } break; case 78: {
            assert(encodeSong("/G/", ins, bb) == 0  &&  ins == " L");
        } break; case 79: {
            assert(encodeSong("G/A/", ins, bb) == 0  &&  ins == "LQ");
        } break; case 80: {
            assert(encodeSong("G#/G/", ins, bb) == 0  &&  ins == "$L");
        } break; case 81: {
            assert(encodeSong("G/G3/", ins, bb) == 0  &&  ins == "LS");
        } break; case 82: {
            assert(encodeSong("C#4/Db5/", ins, bb) == 0  &&  ins == "!^");
        } break; case 83: {
            assert(encodeSong("////", ins, bb) == 0  &&  ins == "    ");
        } break; case 84: {
            assert(encodeSong("G///A/B/C//D//", ins, bb) == 0  &&  ins == "L  QWG H ");
        } break; case 85: {
            assert(encodeSong("C2/C#2/D2/D#2/Fb2/E#2/F#2/G2/G#2/A2/A#2/B2/", ins, bb) == 0  &&  ins == "Z1X2CV3B4N5M");
        } break; case 86: {
            assert(encodeSong("B#2/Db3/D3/Eb3/E3/F3/Gb3/G3/Ab3/A3/Bb3/Cb4/", ins, bb) == 0  &&  ins == ",6.7/A8S9D0F");
        } break; case 87: {
            assert(encodeSong("C4/C#/D/D#4/E/F4/Gb4/G4/Ab/A/Bb/B4/", ins, bb) == 0  &&  ins == "G!H@JK#L$Q%W");
        } break; case 88: {
            assert(encodeSong("C5/C#5/D5/D#5/E5/F5/F#5/G5/G#5/A5/A#5/B5/", ins, bb) == 0  &&  ins == "E^R&TY*U(I)O");
        } break; case 89: {
            assert(encodeSong("CE/", ins, bb) == 0  &&  ins == "[GJ]");
        } break; case 90: {
            assert(encodeSong("CEb/", ins, bb) == 0  &&  ins == "[G@]");
        } break; case 91: {
            assert(encodeSong("C#E/", ins, bb) == 0  &&  ins == "[!J]");
        } break; case 92: {
            assert(encodeSong("C3F#5/", ins, bb) == 0  &&  ins == "[,*]");
        } break; case 93: {
            assert(encodeSong("CDEFGAB/", ins, bb) == 0  &&  ins == "[GHJKLQW]");
        } break; case 94: {
            assert(encodeSong("C#D3EbF#5Gb2AB/", ins, bb) == 0  &&  ins == "[!.@*3QW]");
        } break; case 95: {
            assert(encodeSong("CD/E/FG/", ins, bb) == 0  &&  ins == "[GH]J[KL]");
        } break; case 96: {
            assert(encodeSong("D3/F#3/A3/D4//D3F#3A3D4/", ins, bb) == 0  &&  ins == ".8DH [.8DH]");
        } break; case 97: {
            assert(encodeSong("G3B3DD5//G/A/A3B/C5/B3D5//G//G//CE5//C5/D5/E5/F#5/B3G5//G//G/", ins, bb) == 0  &&  ins == "[SFHR] LQ[DW]E[FR] L L [GT] ERT*[FU] L L");
        } break; case 98: {
            assert(encodeSong("DADDA/", ins, bb) == 0  &&  ins == "[HQHHQ]");
        } break; case 99: {
            assert(encodeSong("C", ins, bb) == 1);
        } break; case 100: {
            ins = "@@@";
            encodeSong("C", ins, bb);
            assert(ins == "@@@");
        } break; case 101: {
            bb = 666;
            encodeSong("C", ins, bb);
            assert(bb == 666);
        } break; case 102: {
            assert(encodeSong("C0/", ins, bb) == 2);
        } break; case 103: {
            ins = "@@@";
            encodeSong("C0/", ins, bb);
            assert(ins == "@@@");
        } break; case 104: {
            encodeSong("C0/", ins, bb);
            assert(bb == 1);
        } break; case 105: {
            assert(encodeSong("C/D/C0/", ins, bb) == 2  &&  bb == 3);
        } break; case 106: {
            assert(encodeSong("C/D/E/C0/F/G/", ins, bb) == 2  &&  bb == 4);
        } break; case 107: {
            assert(encodeSong("C/D/C0/E/F/C0/", ins, bb) == 2  &&  bb == 3);
        } break; case 108: {
            assert(encodeSong("C/D/D0/E/F/C0/G/", ins, bb) == 2  &&  bb == 3);
        } break; case 109: {
            assert(encodeSong("C/D/EFC0/", ins, bb) == 2  &&  bb == 3);
        } break; case 110: {
            assert(encodeSong("C/D/EFC0G/", ins, bb) == 2  &&  bb == 3);
        } break; case 111: {
            assert(encodeSong("B1/", ins, bb) == 2);
        } break; case 112: {
            assert(encodeSong("C#6/", ins, bb) == 2);
        } break; case 113: {
            assert(encodeSong("C7/", ins, bb) == 2);
        } break; case 114: {
            assert(encodeSong("C8/", ins, bb) == 2);
        } break; case 115: {
            assert(encodeSong("C9/", ins, bb) == 2);
        }
    }
}

int main()
{
    
    for (int n = 1; n <= 115; n++)
    testone(n);

    cerr << "Passed!" << endl;
}

/*
 *************************************
 encodeNote
 *************************************
 
 Given an octave number, a note letter, and an accidental sign, return
 the character that the indicated note is encoded as if it is playable.
 Return a space character if it is not playable.
 
 First parameter:   the octave number (the integer 4 is the number of the
 octave that starts with middle C, for example).
 Second parameter:  an upper case note letter, 'A' through 'G'
 Third parameter:   '#', 'b', or ' ' (meaning no accidental sign)
 
 Examples:  encodeNote(4, 'A', ' ') returns 'Q'
 encodeNote(4, 'A', '#') returns '%'
 encodeNote(4, 'H', ' ') returns ' '
 */

char encodeNote(int octave, char noteLetter, char accidentalSign)
{
    // This check is here solely to report a common CS 31 student error.
    if (octave > 9)
    {
        cerr << "********** encodeNote was called with first argument = "
        << octave << endl;
    }
    
    // Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B#
    //      to -1, 0,   1,   2,   3, ...,  11, 12
    
    int note;
    switch (noteLetter)
    {
        case 'C':  note =  0; break;
        case 'D':  note =  2; break;
        case 'E':  note =  4; break;
        case 'F':  note =  5; break;
        case 'G':  note =  7; break;
        case 'A':  note =  9; break;
        case 'B':  note = 11; break;
        default:   return ' ';
    }
    switch (accidentalSign)
    {
        case '#':  note++; break;
        case 'b':  note--; break;
        case ' ':  break;
        default:   return ' ';
    }
    
    // Convert ..., A#1, B1, C2, C#2, D2, ... to
    //         ..., -2,  -1, 0,   1,  2, ...
    
    int sequenceNumber = 12 * (octave - 2) + note;
    
    string keymap = "Z1X2CV3B4N5M,6.7/A8S9D0FG!H@JK#L$Q%WE^R&TY*U(I)OP";
    if (sequenceNumber < 0  ||  sequenceNumber >= keymap.size())
        return ' ';
    return keymap[sequenceNumber];
}

bool isLetter(char letter) {
    if (letter >= 65 && letter <= 71) {
        return true;
    }
    return false;
}

bool isAccidental(char acc) {
    if (acc == 'b' || acc == '#')
        return true;
    return false;
}

bool isNote(string note){
    if (note == "")
        return true;
    int len = note.length();
    if (!isLetter(note[0])) {
        return false;
    }
    for (int i = 1; i < len; i++){
        if (isAccidental(note[i])) {
            if(!isLetter(note[i-1])){
                return false;
            }
        }
        else if (isdigit(note[i])) {
            if(!isLetter(note[i-1]) && !isAccidental(note[i-1])) {
                return false;
            }
        }
        else if (!isLetter(note[i]))
            return false;
        
    }
    return true;
}

bool hasCorrectSyntax(string song){
    if (song == "")
        return true;
    int len = song.length();
    if (song[len-1] != '/')
        return false;
    string chord = "";
    for (int i = 0; i < len; i++) {
        if (song[i] == '/') {
            if (!isNote(chord))
                return false;
            else {
                chord = "";
                continue;
            }
        }
        chord += song[i];
        
    }
    return true;
}

bool isPlayableNote(string note) {
    if (!hasCorrectSyntax(note))
        return false;
    
    int len = note.length();
    for (int i=0; i < len; i++) {
        if (note[i] == '0' || note[i] == '7' || note[i] == '8' || note[i] == '9')
            return false;
        if (note[i] == '1') {
            if (note[i-1] != '#')
                return false;
        }
        if (note[i] == '6') {
            if (note[i-1] != 'b' && note[i-1] != 'C')
                return false;
        }
        if (note[i] == '2') {
            if (note[i-1] == 'b') {
                if (note[i-2] == 'C')
                    return false;
            }
        }
    }
    return true;
}

bool isPlayable(string song){
    if (song == "")
        return true;
    int len = song.length();
    if (song[len-1] != '/')
        return false;
    string chord = "";
    for (int i = 0; i < len; i++) {
        if (song[i] == '/') {
            chord += song[i];
            if (!isPlayableNote(chord))
                return false;
            else {
                chord = "";
                continue;
            }
        }
        chord += song[i];
    }
    return true;
}

int encodeSong(string song, string& instructions, int& badBeat){
    if(isPlayable(song)) {
        string encoding = "";
        int len = song.length();
        int countSlash = 0;
        for (int i = 0; i < len; i++) {
            if (song[i] == '/') {
                countSlash++;
            }
        }
        if (countSlash == len) {
            for (int i = 0; i < len; i++) {
                encoding += " ";
            }
            instructions = encoding;
            return 0;
        }
        string chord = "";
        for (int i = 0; i < song.length(); i++){
            if (song.length() == 1) {
                encoding += " ";
                ;                instructions = encoding;
                return 0;
            }
            if (song[i] != '/') {
                chord += song[i];
            }
            else {
                int chordLen = chord.length();
                if (chordLen == 0) {
                    encoding += " ";
                    song = song.substr(1, song.length()-1);
                    chord = "";
                    i = -1;
                }
                else if (chordLen == 1) {
                    encoding += encodeNote(4, chord[0], ' ');
                    song = song.substr(2, song.length()-2);
                    chord = "";
                    i = -1;
                }
                else if (chordLen == 2 && (isdigit(chord[1]) || isAccidental(chord[1]))) {
                    if (isAccidental(chord[1])) {
                        encoding += encodeNote(4, chord[0], chord[1]);
                        song = song.substr(3, song.length()-3);
                        chord = "";
                        i = -1;
                    }
                    if (isdigit(chord[1])) {
                        int num = chord[1] - 48;
                        encoding += encodeNote(num, chord[0], ' ');
                        song = song.substr(3, song.length()-3);
                        chord = "";
                        i = -1;
                    }
                }
                else if (chordLen == 3 && isdigit(chord[2]) && isAccidental(chord[1])) {
                    int num = chord[2] - 48;
                    encoding += encodeNote(num, chord[0], chord[1]);
                    song = song.substr(4, song.length()-4);
                    chord = "";
                    i = -1;
                }
                else {
                    //multiple notes
                    encoding += '[';
                    while (chord.length() > 1) {
                        int cLen = chord.length();
                        if (isdigit(chord[1])) {
                            int num = chord[1] - 48;
                            encoding += encodeNote(num, chord[0], ' ');
                            chord = chord.substr(2, cLen-2);
                        }
                        else if (isAccidental(chord[1])) {
                            if(isdigit(chord[2])) {
                                int num = chord[2] - 48;
                                encoding += encodeNote(num, chord[0], chord[1]);
                                chord = chord.substr(3, cLen-3);
                            }
                            else {
                                encoding += encodeNote(4, chord[0], chord[1]);
                                chord = chord.substr(2, cLen-2);
                            }
                        }
                        else {
                            encoding += encodeNote(4, chord[0], ' ');
                            chord = chord.substr(1, cLen-1);
                        }
                    }
                    if (chord.length() == 1)
                        encoding += encodeNote(4, chord[0], ' ');
                    encoding += ']';
                    song = song.substr(chordLen + 1, song.length() - chordLen - 1);
                    chord = "";
                    i = -1;
                }
            }
            
        }
        instructions = encoding;
        return 0;
    }
    if(!hasCorrectSyntax(song))
        return 1;
    
    int len = song.length();
    int beatCount = 0;
    string chord = "";
    for (int i = 0; i < len; i++) {
        if (song[i] == '/') {
            chord += song[i];
            if (isPlayable(chord))
                beatCount++;
            else {
                badBeat = beatCount + 1;
                return 2;
            }
        }
        else {
            chord += song[i];
            continue;
        }
        
    }
    return 2;
}
