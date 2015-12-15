#include <SPI.h>
#include "PN532_SPI.h"
#include "PN532.h"
#include "NfcAdapter.h"

PN532_SPI interface(SPI, 10);
NfcAdapter nfc = NfcAdapter(interface);

void setup(void) {
  Serial.begin(9600);
  Serial.println("NDEF Reader");
  nfc.begin();
}

void loop(void) {
    Serial.println("\nScan a NFC tag\n");
    if (nfc.tagPresent())
    {
        NfcTag tag = nfc.read();
        tag.print();

        Serial.println("Writing to tag...");

        NdefMessage message = NdefMessage();
        message.addTextRecord("Hello, Arduino!");
        nfc.write(message);
    }
    delay(5000);
}
