#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>
#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);


PN532_SPI pn532spi(SPI, 10);
NfcAdapter nfc = NfcAdapter(pn532spi);

// ----------------------  Read NFC ---------------------
if (nfc.tagPresent()) {
    NfcTag tag = nfc.read();
    tag.print();
}

// -----------------------   Write info to NFC -----------
if (nfc.tagPresent()) {
    NdefMessage message = NdefMessage();
    message.addTextRecord("Hello, Arduino!");
    success = nfc.write(message);
}

