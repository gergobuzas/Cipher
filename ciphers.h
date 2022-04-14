/**
 * \file ciphers.h
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#ifndef CipherS_H
#define CipherS_H

#include <string>
#include <vector>
#include "memtrace.h"

using std::string;

/**
 * Az ős osztály interfésze
 */ 
class Cipher {
public:
    /**
     * Titkosítja a kapott stringet
     * @param   message titkosítandó üzenet
     * @return  a message szöveg titkosított változata
     */
    virtual std::string encode(const std::string& message) = 0;
    /**
     * Dekódolja a kapott stringet
     * @param   ciphertext titkosított üzenet
     * @return  a megfejtett nyílt szöveg
     */
    virtual std::string decode(const std::string& ciphertext) = 0;
    /**
     * Létrehoz egy másolatot dinamikusan
     * @return  a létrehozott objektumra mutató pointer
     */
    virtual Cipher* clone() const = 0;
    /**
     * Alap destruktor
     */ 
    virtual ~Cipher() { };
};

//Osztályok, amiket meg kell csinálni a leírások és az osztálydiagram alapján
class CaesarCipher: public Cipher{
private:
    int shift;
public:
    CaesarCipher(): shift(0){};
    explicit CaesarCipher(int shiftCtor){ shift = shiftCtor;}
    std::string encode(const std::string& message);
    std::string decode(const std::string& ciphertext);
    Cipher* clone() const;

};

class MyCipher: public Cipher {
private:
    string key;
    int offset;
public:
    explicit MyCipher(string ckey){ key = ckey; offset = 0;}
    MyCipher(string ckey, int coffset){ key = ckey; offset = coffset;}
    string encode(const string& message);
    string decode(const std::string& ciphertext);
    Cipher* clone() const;
};

/*
class CipherQueue {

};
*/
#endif